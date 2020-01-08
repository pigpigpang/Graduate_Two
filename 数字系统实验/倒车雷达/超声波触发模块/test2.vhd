library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity test2 is
	port(
        clk : in std_logic;
        trig : out std_logic 
    );
end test2;

architecture main of test2 is
signal count : std_logic_vector(16 downto 0):="00000000000000000";
begin
	process(clk)
	begin
	if (clk'event and clk = '1') then
		count <= count + "00000000000000001";
		if (count = "11100000000000000") then
			trig <= '1';
		end if;
		if (count = "11111111111111111") then
			count <= "00000000000000000";
			trig <= '0';
		end if;
	end if;
	end process;
end main;