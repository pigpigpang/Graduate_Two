library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
entity exchange is
     port(clk:in std_logic;
          clk2:out std_logic);
end exchange;
architecture arch of exchange is 
	signal count:integer range 0 to 23; 
	begin
		process(clk)
		begin
		if (clk'event and clk='1')then 
			if(count=23)then
				count<=0;
			else 
			count<=count+1;
			end if;
		end if;
		end process;
		process(clk)
		begin
		if(clk'event and clk='1') then 
			if(count=0)then
				clk2<='1';
			elsif (count=12) then clk2 <= '0';
			end if;
		end if;
		end process;
end arch;