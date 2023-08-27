num = 0.0194;
den = [1 0.1312 0.00430336];
G = tf(num,den);
rlocus(G);
title('Lugar das Raízes da Função de Transferência G(s)');
xlabel('Eixo Real');
ylabel('Eixo Imaginário');
grid on;