ENTITY PortaOr IS
PORT(input1,input2,input3: IN BIT;
	saida_or: OUT BIT);

END PortaOr;


ARCHITECTURE behav OF PortaOr IS
BEGIN
saida_or <= input1 or input2 or input3;
END;