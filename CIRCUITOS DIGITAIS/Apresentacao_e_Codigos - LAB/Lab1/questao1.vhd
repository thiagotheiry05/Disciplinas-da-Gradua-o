ENTITY PortaOr IS
	PORT(A, B: IN BIT;
	S : OUT BIT);
END PortaOr;

ARCHITECTURE behav of PortaOr IS
BEGIN
	S <= A OR B;
END behav;