ENTITY mux2x1 IS
PORT(I0,I1,s0 : IN BIT;
d : OUT BIT);
END mux2x1;
ARCHITECTURE behav OF mux2x1 IS
BEGIN
d <= (I0 and (not s0)) or (I1 and s0) ;

end behav; 