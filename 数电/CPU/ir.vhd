library ieee;
use ieee.std_logic_1164.all;

entity  ir is
port(
	a : in std_logic_vector(7 downto 0);
	LD_IR : in std_logic;
	HALT : in std_logic;
	clk : in std_logic;
	x : out std_logic_vector(7 downto 0));
end ir;

architecture bhv of ir is
signal temp : std_logic_vector(7 downto 0) := "00000000";
begin
	process(LD_IR,clk,HALT)
	begin
		if(HALT = '1')then
			temp <= "ZZZZZZZZ";
		elsif(clk'event and clk='0')then
			if(LD_IR='1')then
				temp <= a;
			end if;
		end if;
	end process;
	x <= temp;
end bhv;