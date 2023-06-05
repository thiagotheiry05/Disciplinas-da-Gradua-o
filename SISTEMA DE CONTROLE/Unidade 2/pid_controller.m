function [u,i,d] = pid_controller(e,ek,ik,dk)
%#codegen 
T = 0.2;
kp =  5.2169;
ki = 0.5527;
kd = 12.31;

% Cálculo dos termos do controlador PID
p = kp * e;
i = ik + ((ki * T) / 2) * (e + ek);
d = -dk + ((2 * kd) / T) * (e - ek);

u = p + i + d;
