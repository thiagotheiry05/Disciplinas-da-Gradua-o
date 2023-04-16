ENTITY TesteDePropriedades IS
	PORT(A, B, C: IN BIT;
	Si1, Si2, Si3, 
	Sc1, Sc2, Sc3, Sc4, 
	Sa1, Sa2, Sa3, Sa4,
	Sd1, Sd2, Sd3, Sd4,
	Sm1, Sm2, Sm3, Sm4: OUT BIT);
END TesteDePropriedades;

-- Identidade
ARCHITECTURE identidade of TesteDePropriedades IS
BEGIN
	Si1 <= A OR '0';
	Si2 <= A AND '1';
	Si3 <= NOT (NOT A);
END identidade;

-- Comutatividade
ARCHITECTURE comutatividade of TesteDePropriedades IS
BEGIN
	-- Adição
	Sc1 <= A OR B;
	Sc2 <= B OR A;
	
	-- Multiplicação
	Sc3 <= A AND B;
	Sc4 <= B AND A;
END comutatividade;

-- Associatividade
ARCHITECTURE associatividade of TesteDePropriedades IS
BEGIN
	-- Adição
	Sa1 <= A OR (B OR C);
	Sa2 <= (A OR B) OR C;
	
	-- Multiplicação
	Sa3 <= A AND (B AND C);
	Sa4 <= (A AND B) AND C;
END associatividade;

-- Distributividade
ARCHITECTURE distributividade of TesteDePropriedades IS
BEGIN
	Sd1 <= A AND (B OR C);
	Sd2 <= (A AND B) OR (A AND C);
	
	Sd3 <= A OR (B AND C);
	Sd4 <= (A OR B) AND (A OR C);
END distributividade;

-- Leis de De Morgan
ARCHITECTURE DeMorgan of TesteDePropriedades IS
BEGIN
	Sm1 <= NOT(A AND B);
	Sm2 <= NOT(A) OR NOT(B);
	
	Sm3 <= NOT(A OR B);
	Sm4 <= NOT(A) AND NOT(B);
END DeMorgan;