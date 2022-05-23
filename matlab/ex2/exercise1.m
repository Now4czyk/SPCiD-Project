%% Link do sprawozdania
% https://docs.google.com/document/d/1rqwLZ-c1CUDAs6HAGjWjasRgMZJ9j3YUT7sq61bgrIs/edit
% Indeks: 147698
clc;
clear all;
close all;

%% 4.2 Podstawowy UAR z regulatorem PID

%% Odkomentuj te dane i zakomentuj reszte skryptu do odpalenia schematu scheme1_1
% k = 6;
% T_1 = 5.9;
% T_2 = 0.8;
% Tp = 0.01;
% T = 1000;

%% Implementacja dyskretnego regulatora PID
%nastawy PID
kp = 2;
Ti = 0.5;
Td = 2;
Tp = 0.01;
%współczynniki transmitancji
k = 6;
T_1 = 5.9;
T_2 = 0.8;
s = tf('s');
G_s = k/((1+s*T_1)*(1+s*T_2));
%step(G_s);
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
for i=3:N
    %TODO tu coś tam info o bardziej punktowanym podejściu 
    %obliczenie uchybu i dotychczasowej sumy uchybow
    e(i) = w(i) - y(i-1);
    sumaUchybow = sumaUchybow + e(i);
    %równanie (6)
    u(i) = kp*(e(i) + Tp/Ti*sumaUchybow + Td/Tp*(e(i)+e(i-1)));
    y(i) = (2-1.42*Tp)*y(i-1) + (-0.21*Tp^2+1.42*Tp-1)*y(i-2) + 1.27* Tp^2*u(i-2);
end
figure;
% plot(1:N, w);
% hold on;
plot(1:N, y);
% no niby wszystko git ale jednak ten wykres to tak nie do końca





