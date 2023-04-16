ENTITY PortaAnd2 IS
PORT(entrada2_and1,entrada2_and2,entrada2_and3: IN BIT;
	saida_and2: OUT BIT);

END PortaAnd2;


ARCHITECTURE behav OF PortaAnd2 IS
BEGIN
saida_and2 <= entrada2_and1 AND entrada2_and2 AND entrada2_and3;
END;