A =[-0.0656 0;0.0656 -0.0656];
B = [0.2964;0];
C = [0 1];

% projeto observador

delta_s = (conv([1 5],[1 5])); % polos em -5 e -5
V = obsv(A, C);
qlA = A^2 + delta_s(2)*A + delta_s(3)*eye(size(A));
L = qlA*inv(V)*[0;1];


% projeto controlador

Aa = [0 C;[0;0] A]; Ba=[0;B];
delta_sc = conv((conv([1 0.0998-0.2605*i],[1 0.0998+0.2605*i])),[1 0.15]);
qcAa = Aa^3 + delta_sc(2)*Aa^2 + delta_sc(3)*Aa + delta_sc(4)*eye(size(Aa));
Ua = ctrb(Aa,Ba);
Ka = -[0 0 1]*inv(Ua)*qcAa;
K1 = real(Ka(1));
K2 = real(Ka(2:length(Ka)));

















