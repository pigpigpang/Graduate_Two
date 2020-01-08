library ieee;
use ieee.std_logic_1164.all, ieee.std_logic_unsigned.all;

entity tyjoq is
port(we,clk : in std_logic;
	 ra,wa : in std_logic_vector(1 downto 0);
	 i : in std_logic_vector(7 downto 0);
	 ao,bo : out std_logic_vector(7 downto 0));
end tyjoq;

architecture behave of tyjoq is
signal a,b,c: std_logic_vector(7 downto 0);
begin
	process(we, clk)
	begin
		if (we = '1') then
			if ra="00" then ao<=a;
			elsif ra="01" then ao<=b;
			elsif ra="10" then ao<=c;
			else ao<="ZZZZZZZZ";
			end if;
			if wa="00" then bo<=a;
			elsif wa="01" then bo<=b;
			elsif wa="10" then bo<=c;
			else bo<="ZZZZZZZZ";
			end if;
		elsif (clk'event and clk='0') then
			if wa="00" then a<=i;
			elsif wa="01" then b<=i;
			elsif wa="10" then c<=i;
			end if;
		end if;
	end process;
end;