ENTITY PortaAnd IS
PORT(entrada_and1,entrada_and2: IN BIT;
	saida_and: OUT BIT);

END PortaAnd;


ARCHITECTURE behav OF PortaAnd IS
BEGIN
saida_and <= entrada_and1 AND entrada_and2;
END;