clc;
clear all;
close all;
k=6;
T_1=5.1;
T_2=0.2;

%% modułu
Kp=2.125;
Ti=5.1;
Td=0;

%% symetrii
Kp=2.125;
Ti=0.8;
Td=0;

%% układ

Tp = .01

t = 10
M=t/Tp
plotTime = 0:Tp:t-Tp;

w = square(plotTime, 50);
e = zeros(1, M);
y = zeros(1, M);
u = zeros(1, M);
u_b = zeros(1, M);
IAE = zeros(1, M);
ISE = zeros(1, M);

max = .7;
min = -.7;

object_recursive = @(i, u, y)(k*Tp^2*u(i-2)-y(i-2)*(Tp^2-Tp*T_1-Tp*T_2+T_1*T_2)-y(i-1)*(Tp*T_1+Tp*T_2-2*T_1*T_2))/(T_1*T_2);

regulator = @(i, e, y) Kp*(e(i)+Tp/Ti*sum(e)+Td/Tp*(e(i)-e(i-1)));

for i=1:M
    if i > 2
        e(i)=w(i)-y(i-1);
    
        u(i)= regulator(i, e, y);
        
        if abs(u(i)) > 0.3
            u(i)=u(i)-Kp*Tp/Ti*sum(e);
        end
        u_b(i)=u(i);
        
        if u(i) > max
            u(i)=max;
        elseif u(i)<min
            u(i) = min;
        end
    
        y(i)=object_recursive(i, u, y);
        
    else
        e(i) = 1;
        y(i) = 0;
    end
    IAE(i)=sum(abs(e))*Tp;
    ISE(i)=sum(e.^2)*Tp;
end


figure;
subplot(2, 1, 1)

plot(plotTime, y)
hold on
stairs(plotTime, w)

subplot(2, 1, 2)
stairs(plotTime, u)

hold on

stairs(plotTime, u_b)

disp('IAE:')
disp(IAE(M));
disp('ISE:')
disp(ISE(M));