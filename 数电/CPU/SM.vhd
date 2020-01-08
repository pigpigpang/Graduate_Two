library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;

entity SM is
port (
	clk : in std_logic;
	SM : out std_logic);
end SM;

architecture beh of SM is
signal S : std_logic := '0';
begin
process (clk)
begin
	if(clk'event and clk='0')then
		if(S = '0')then
			S <= '1';
		else
			S <= '0';
		end if;
	end if;
end process;
	SM <= S;
end beh;