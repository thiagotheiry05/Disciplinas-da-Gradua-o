ENTITY Mux4x1 IS
PORT(I0,I1,I2,I3: IN BIT;
s : in bit_vector(1 downto 0); 
d : OUT BIT);
END Mux4x1;
ARCHITECTURE behav OF Mux4x1 IS
BEGIN
WITH s SELECT
d <= I0 WHEN '0'&'0',
I1 WHEN '0'&'1', 
I2 WHEN '1'&'0', 
I3 WHEN '1'&'1'; 

END behav;