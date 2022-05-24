%% Link do sprawozdania
% https://docs.google.com/document/d/1rqwLZ-c1CUDAs6HAGjWjasRgMZJ9j3YUT7sq61bgrIs/edit
% Indeks: 147698
clc;
clear all;
close all;
%dane transmitancji początkowej
k = 6;
T_1 = 5.9;
T_2 = 0.8;

%% 4.2 Podstawowy ciągły UAR z regulatorem PID

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
%inicjalizacja wektorów niezbędnych do obliczenia sterowania, wyjścia oraz
%wskaźników jakości dyskretnego UAR
w = ones(1, N);
y = zeros(1, N);
e = zeros(1, N);
u = zeros(1, N);
ISE = zeros(1, N);
IAE = zeros(1, N);
y(1) = 0;
y(2) = 0;
%z rysunku 2: e(n) = w(n) - y(n-1)dlatego
e(1) = 1;
e(2) = 1;
sumaUchybow = e(1) + e(2);
ISE(1) = Tp*1;
ISE(2) = Tp*1;
IAE(1) = Tp*2;
IAE(2) = Tp*2;

for i=3:N
    %TODO tu coś tam info o bardziej punktowanym podejściu 
    %obliczenie uchybu i dotychczasowej sumy uchybow
    e(i) = w(i) - y(i-1);
    sumaUchybow = sumaUchybow + e(i);
    %równanie (6)
    u(i) = kp*((e(i) + Tp/Ti*sumaUchybow + Td/Tp*(e(i)-e(i-1))));
    %wyznaczone równanie rekursywne
    y(i) = (2-1.42*Tp)*y(i-1) + (-0.21*Tp^2+1.42*Tp-1)*y(i-2) + 1.27* Tp^2*u(i-2);
    %wskaźniki jakości
    ISE(i) = ISE(i-1) + Tp*e(i)^2;
    IAE(i) = IAE(i-1) + Tp*abs(e(i));
end

%wektor czasowy na potrzeby symulacji, oraz wykresy
t = 0:0.01:44.99;
figure;
subplot(2,1,1);
plot(t, w);
hold on;
plot(t, y);
legend( 'sygnał zadany', 'odpowiedź układu')
subplot(2,1,2);
plot(t, u);
legend('sygnał sterujący')
figure;
plot(t, ISE);
hold on;
plot(t, IAE);
legend( 'ISE', 'IAE')
