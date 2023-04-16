ENTITY circuito IS
PORT (A,B,C:IN BIT;
	S1,S2: OUT BIT);

END circuito;

ARCHITECTURE behav OF circuito IS
	SIGNAL AND1:BIT;
	SIGNAL AND2:BIT;
	SIGNAL AND3:BIT;
	SIGNAL AND4:BIT;
	SIGNAL AND5:BIT;
	SIGNAL AND6:BIT;
	SIGNAL AND7:BIT;
	SIGNAL NOT1:BIT;
	SIGNAL NOT2:BIT;
	SIGNAL NOT3:BIT;
	SIGNAL NOT4:BIT;
	SIGNAL NOT5:BIT;
	SIGNAL NOT6:BIT;
	
	
	COMPONENT PortaOr IS
		PORT(input1,input2,input3: IN BIT;
		saida_or: OUT BIT);
	END COMPONENT;
	
	COMPONENT PortaOr2 IS
		PORT(cin1,cin2,cin3,cin4: IN BIT;
		saida_or2: OUT BIT);
	END COMPONENT;
	
	COMPONENT PortaNot IS
		PORT(entrada_not: IN BIT;
		saida_not: OUT BIT);
	END COMPONENT;
	
	COMPONENT PortaAnd IS
		PORT(entrada_and1,entrada_and2: IN BIT;
		saida_and: OUT BIT);
	END COMPONENT;
	
	COMPONENT PortaAnd2 IS
		PORT(entrada2_and1,entrada2_and2,entrada2_and3: IN BIT;
		saida_and2: OUT BIT);
	END COMPONENT;
	
BEGIN
u1: PortaAnd PORT MAP(entrada_and1 => A, entrada_and2 => C, saida_and => AND1);
u2: PortaAnd PORT MAP(entrada_and1 => B, entrada_and2 => A, saida_and => AND2);
u3: PortaAnd PORT MAP(entrada_and1 => B, entrada_and2 => C, saida_and => AND3);
u4: PortaOr PORT MAP (input1 => AND1, input2 => AND2, input3 => AND3, saida_or => S1);
u5: PortaNot PORT MAP(entrada_not => A, saida_not => NOT1);
u6: PortaNot PORT MAP(entrada_not => B, saida_not => NOT2);
u7: PortaNot PORT MAP(entrada_not => A, saida_not => NOT3);
u8: PortaNot PORT MAP(entrada_not => C, saida_not => NOT4);
u9: PortaNot PORT MAP(entrada_not => B, saida_not => NOT5);
u10: PortaNot PORT MAP(entrada_not => C, saida_not => NOT6);
u11: PortaAnd2 PORT MAP(entrada2_and1 => NOT1, entrada2_and2 => NOT2, entrada2_and3 => C, saida_and2 =>AND4);
u12: PortaAnd2 PORT MAP(entrada2_and1 => NOT3, entrada2_and2 => B, entrada2_and3 => NOT4, saida_and2 =>AND5);
u13: PortaAnd2 PORT MAP(entrada2_and1 => A, entrada2_and2 => NOT5, entrada2_and3 => NOT6, saida_and2 =>AND6);
u14: PortaAnd2 PORT MAP(entrada2_and1 => A, entrada2_and2 => B, entrada2_and3 => C, saida_and2 =>AND7);
u15: PortaOr2 PORT MAP(cin1 => AND4, cin2 => AND5, cin3 => AND6, cin4 => AND7, saida_or2 => S2);
END;