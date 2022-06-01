close all; clc; clear all;

%%
k = 6;
T_1 = 5.9;
T_2 = 0.8;
s = tf('s');
G_s = k/((1+s*T_1)*(1+s*T_2))
%nastawy PID
kp = 1.6;
Ti = 6;
Td = 0.08;
Tp = 0.01;

N = 4500;
t = 0:0.01:44.99;

w = sin(2*t);
y = zeros(1, N);
e = zeros(1, N);
u = zeros(1, N);
y(1) = 0;
y(2) = 0;
e(1) = 1;
e(2) = 1;
sumaUchybow = e(1) + e(2);
for i=3:N
    %obliczenie uchybu i dotychczasowej sumy uchybow
    e(i) = w(i) - y(i-1);
    sumaUchybow = sumaUchybow + e(i);
    %równanie (6)
    u(i) = kp*((e(i) + Tp/Ti*sumaUchybow + Td/Tp*(e(i)-e(i-1))));
    %4.4 sprzężenie wyprzedzające - sygnał sterujący
    uf = 4.72/6*(-4)*w(i)+6.7/6*2*cos(2*t(i))+1/6*w(i);
    u(i) = uf + u(i);
    %wyznaczone równanie rekursywne
    y(i) = (2-1.42*Tp)*y(i-1) + (-0.21*Tp^2+1.42*Tp-1)*y(i-2) + 1.27* Tp^2*u(i-2);
end
figure;
subplot(2, 1, 1);
plot(t, w);
hold on;
plot(t, y);
legend( 'sygnał zadany', 'odpowiedź układu');
subplot(2, 1, 2);
plot(t, u);
legend('sygnał sterujący');