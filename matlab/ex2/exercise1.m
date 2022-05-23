%% Link do sprawozdania
% https://docs.google.com/document/d/1rqwLZ-c1CUDAs6HAGjWjasRgMZJ9j3YUT7sq61bgrIs/edit
% Indeks: 147698
clc;
clear all;
close all;

%% 4.2 Podstawowy UAR z regulatorem PID
k = 6;
T_1 = 5.9;
T_2 = 0.8;
Tp = 0.01;
T = 100; %???????????
s = tf('s');
G_s = k/((1+s*T_1)*(1+s*T_2));