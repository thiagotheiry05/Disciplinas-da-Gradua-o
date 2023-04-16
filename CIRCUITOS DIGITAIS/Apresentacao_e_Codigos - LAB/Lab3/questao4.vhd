ENTITY Mux4x1 IS
PORT(I0,I1,I2,I3,s0,s1 : IN BIT;
	d : OUT BIT);
END;

ARCHITECTURE behav OF Mux4x1 IS
	SIGNAL M1: BIT;
	SIGNAL M2: BIT;
	
	COMPONENT Mux2x1 IS
	PORT(I0,I1,s0 : IN BIT;
		d : OUT BIT);
	END COMPONENT;

	BEGIN
	u1: Mux2x1 PORT MAP(I0 => I0, I1 => I1, s0 => s1, d => M1);
	u2: Mux2x1 PORT MAP(I0 => I2, I1 => I3, s0 => s1, d => M2);
	u3: Mux2x1 PORT MAP(I0 => M1, I1 => M2, s0 => s0, d => d);
END;