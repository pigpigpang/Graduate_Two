library ieee;
use ieee.std_logic_1164.all;
entity chuan_add is 
port(a,b: in std_logic_vector(3 downto 0);
	 c: out std_logic;
	 sum: out std_logic_vector(3 downto 0));
end chuan_add;
architecture behave of chuan_add is
signal temp : std_logic_vector(4 downto 0);
begin
	process(a,b)
	begin
		temp(0) <= '0';
		for i in 0 to 3 loop
			sum(i) <= a(i) xor b(i) xor temp(i);
			temp(i+1) <= (a(i) and b(i)) or (temp(i) and (a(i) xor b(i)));
		end loop;
		c <= temp(4);
	end process;
end;
