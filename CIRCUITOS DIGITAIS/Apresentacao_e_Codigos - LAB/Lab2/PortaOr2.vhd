ENTITY PortaOr2 IS
PORT(cin1,cin2,cin3,cin4: IN BIT;
	saida_or2: OUT BIT);

END PortaOr2;


ARCHITECTURE behav OF PortaOr2 IS
BEGIN
saida_or2 <= cin1 or cin2 or cin3 or cin4;
END;