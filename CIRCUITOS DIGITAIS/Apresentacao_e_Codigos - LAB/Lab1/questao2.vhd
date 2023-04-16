ENTITY PortaAnd IS
	PORT(A, B: IN BIT;
	S : OUT BIT);
END PortaAnd;

ARCHITECTURE behav of PortaAnd IS
BEGIN
	S <= A AND B;
END behav;