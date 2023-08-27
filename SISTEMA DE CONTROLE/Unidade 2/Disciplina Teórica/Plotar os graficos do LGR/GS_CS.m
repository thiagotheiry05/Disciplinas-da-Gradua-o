num = [0.238814 0.101208 0.0107224];
den = conv([1 0], conv([1 0.0656],[1 0.0656]));
G = tf(num, den);

rlocus(G);
title('Lugar das Ra�zes da Fun��o de Transfer�ncia G(s)C(s)');
xlabel('Eixo Real');
ylabel('Eixo Imagin�rio');
grid on;
