num = [0.238814 0.101208 0.0107224];
den = conv([1 0], conv([1 0.0656],[1 0.0656]));
G = tf(num, den);

rlocus(G);
title('Lugar das Raízes da Função de Transferência G(s)C(s)');
xlabel('Eixo Real');
ylabel('Eixo Imaginário');
grid on;
