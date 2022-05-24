%% Link do sprawozdania
% https://docs.google.com/document/d/1rqwLZ-c1CUDAs6HAGjWjasRgMZJ9j3YUT7sq61bgrIs/edit
% Indeks: 147698
clc;
clear all;
close all;
k = 6;
T_1 = 5.9;
T_2 = 0.8;

%% 4.2 Podstawowy UAR z regulatorem PID

%% Odkomentuj te dane i zakomentuj reszte skryptu do odpalenia schematu scheme1_1
% Tp = 0.01;
% kp = 1.6;
% Ti = 6;
% Td = 0.08;


%% Implementacja dyskretnego regulatora PID
%nastawy PID
kp = 1.6;
Ti = 6;
Td = 0.08;
Tp = 0.01;
%czas symulacji ciągłej to 45s zatem ilość próbek to 45/0.01 = 4500
N = 4500;
w = ones(1, N);
y = zeros(1, N);
e = zeros(1, N);
u = zeros(1, N);
y(1) = 0;
y(2) = 0;
%z rysunku 2: e(n) = w(n) - y(n-1)dlatego
e(1) = 1;
e(2) = 1;
sumaUchybow = e(1) + e(2);
ISE = Tp*sumaUchybow;
IAE = Tp*abs(sumaUchybow);
for i=3:N
    %TODO tu coś tam info o bardziej punktowanym podejściu 
    %obliczenie uchybu i dotychczasowej sumy uchybow
    e(i) = w(i) - y(i-1);
    sumaUchybow = sumaUchybow + e(i);
    %równanie (6)
    u(i) = kp*((e(i) + Tp/Ti*sumaUchybow + Td/Tp*(e(i)-e(i-1))));
    y(i) = (2-1.42*Tp)*y(i-1) + (-0.21*Tp^2+1.42*Tp-1)*y(i-2) + 1.27* Tp^2*u(i-2);
    ISE = ISE + Tp*e(i)^2;
    IAE = IAE + Tp*abs(e(i));
end
figure;
plot(0:0.01:44.99, w);
hold on;
plot(0:0.01:44.99, y);
disp(ISE)
disp(IAE)





