library ieee;
use ieee.std_logic_1164.all, ieee.std_logic_unsigned.all;
entity sit is
port(en,clk : in std_logic;
	 Z: out std_logic);
end sit;
architecture behave of sit is
signal tem: std_logic;
begin
	process(clk,en)
		begin
		if(en='1') then
			if(clk'event and clk='0') then
				tem <= not tem;
			end if;
		end if;
		Z <=tem;
		end process;
end;