ENTITY PortaNot IS
PORT(entrada_not: IN BIT;
	saida_not: OUT BIT);

END PortaNot;


ARCHITECTURE behav OF PortaNot IS
BEGIN
saida_not <= NOT(entrada_not);
END;