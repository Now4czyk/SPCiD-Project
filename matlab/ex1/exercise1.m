%% Zadanie 1
% Indeks: 147698
clc;
clear all;
close all;

%% 4.1 Model ciągły i dyskretny obiektu regulacji
k = 6;
T_1 = 5.9;
T_2 = 0.8;
Tp = 0.01;

%% Wyznacznie transmitancji
s = tf('s');
G_s = k/((1+s*T_1)*(1+s*T_2));
step(G_s);

%% W tym miejscu zostało wykonane zadanie ze schematu schemat1_1

%% Dyskretyzacja obiektu
% suma 3 pierwszych cyfr 1+4+7=12 -> parzysta czyli metoda delta+
% zdjęcie obliczeń wklejone w dokumencie

%% Implementacja odpowiedzi obiekt danego obliczonym równaniem różnicowym
k=6;
T_1 = 5.9;
T_2 = 0.8;
Tp = 0.01;
t = 0:Tp:40-Tp;
s = tf('s');
G_s = k/((1+s*T_1)*(1+s*T_2));
step(G_s);
hold on;
%dwie pierwsze próbki zerowe, ponieważ inaczej nie jesteśmy w stanie
%obliczyć y(3), a u to wektor 1, ponieważ wymuszenie jest skokowe
N= length(t);
u = ones(1, N);
y = zeros(1, N);
y(1) = 0;
y(2) = 0;

for i=3:N
    y(i) = (2-1.42*Tp)*y(i-1) + (-0.21*Tp^2+1.42*Tp-1)*y(i-2) + 1.27* Tp^2*u(i-2);
end

stairs(t, y, 'r')
legend('obiekt ciągły', 'obiekt z r. rekursywnego')


