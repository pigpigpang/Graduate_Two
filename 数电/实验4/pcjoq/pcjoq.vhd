library ieee;
use ieee.std_logic_1164.all, ieee.std_logic_unsigned.all;

entity pcjoq is
port(a : in std_logic_vector(7 downto 0);
	 ld, inc, clk : in std_logic;
	 c : out std_logic_vector(7 downto 0));
end pcjoq;

architecture behave of pcjoq is
signal tem : std_logic_vector(7 downto 0);
begin
	process(ld, inc, clk)
	begin
		if (clk'event and clk = '0') then
			if inc = '1' then
				if tem = "11111111" then
					tem <= "00000000";
				else
					tem <= tem + 1;
				end if;
			elsif ld = '1' then
				tem <= a;
			end if;
		end if;
	end process;
	c <= tem;
end;