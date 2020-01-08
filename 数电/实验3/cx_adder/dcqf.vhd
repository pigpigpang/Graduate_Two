library ieee;
use ieee.std_logic_1164.all;
entity dcqf is
	port(
		D,C : in std_logic;
		q : out std_logic
		);
end dcqf;
architecture rtl of dcqf is
signal qc : std_logic;
begin
	process(D,C)
	begin
		if(C'event and C = '1') then
		qc <= D;
		end if;
	end process;
	q <= qc;
end rtl;
		