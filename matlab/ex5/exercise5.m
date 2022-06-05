close all; clc; clear all;

%% 4.5 ograniczenie sterowania i AWC
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

w = square(t, 50);
y = zeros(1, N);
e = zeros(1, N);
u = zeros(1, N);
e(1) = 1;
e(2) = 1;
sumaUchybow = e(1) + e(2);
%ustawianie ograniczeń
max = 1.3;
min = -max;
for i=3:N
    %obliczenie uchybu i dotychczasowej sumy uchybow
    e(i) = w(i) - y(i-1);
    sumaUchybow = sumaUchybow + e(i);
    %równanie (6)
    u(i) = kp*((e(i) + Tp/Ti*sumaUchybow + Td/Tp*(e(i)-e(i-1))));
    %4.5 ograniczenie i AWC1
    if abs(e(i)) > 0.02
        u(i) = u(i) - kp*Tp/Ti*sumaUchybow;
    end
    if u(i) < min
        u(i) = min;
    elseif u(i) > max
        u(i) = max;
    end
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