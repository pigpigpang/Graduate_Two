library IEEE;
use IEEE.std_logic_1164.all;
entity mux4_3_1 is
port (d0,d1,d2:in STD_LOGIC_VECTOR(3 downto 0);
      sel :in STD_LOGIC_VECTOR(2 downto 0);
      dout:out STD_LOGIC_VECTOR(3 downto 0) );
end mux4_3_1;   
architecture rtl of mux4_3_1 is
begin
    process(sel)
	begin
		if(sel="000") then
			dout<=d0;
		elsif(sel="001") then
			dout<=d1;
		else dout<=d2;
        end if;
    end process;
end rtl;
        
        
