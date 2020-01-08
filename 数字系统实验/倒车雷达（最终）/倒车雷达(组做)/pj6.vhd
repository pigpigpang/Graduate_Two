library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity pj6 is
      port(clk:in std_logic;
           a : in std_logic_vector(3 downto 0);
           clk3:out std_logic);
end entity pj6;

architecture arch of pj6 is
signal count: std_logic_vector(7 downto 0);
signal clr: std_logic ;
 begin 
 process(clk)
   begin
   if(clk'event and clk='1') then 
		if(a = "1000")then
			if(count="11111111")then
				count<="00000000";
			elsif(count>"01111111")then
				clr<='1';
			else 
				clr<='0';
			end if;
		elsif(a = "0100")then
			if(count="11111111")then
				count<="00000000";
			elsif(count>"00111111")then
				clr<='1';
			else 
				clr<='0';
			end if;
		elsif(a = "0010")then
			if(count="11111111")then
				count<="00000000";
			elsif(count>"00011111")then
				clr<='1';
			else 
				clr<='0';
			end if;
		else 
			if(count="11111111")then
				count<="00000000";
			elsif(count>"01111111")then
				clr<='1';
			else 
				clr<='0';
			end if;
		end if;
		count<=count+1;
  end if;
end process;
 process(clr)
begin
   if(clr='1') then 
        clk3<=clk;
   else
        clk3<='0';
   end if;
end process;
end arch;