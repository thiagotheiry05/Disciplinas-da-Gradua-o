num = 0.0194;
den = [1 0.1312 0.00430336];
G = tf(num,den);
rlocus(G);
title('Lugar das Ra�zes da Fun��o de Transfer�ncia G(s)');
xlabel('Eixo Real');
ylabel('Eixo Imagin�rio');
grid on;