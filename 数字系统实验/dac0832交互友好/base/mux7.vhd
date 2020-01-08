library IEEE;
use IEEE.std_logic_1164.all;
entity mux7 is
port (d0,d1,d2,d3,d4,d5:in STD_LOGIC_VECTOR(7 downto 0);
        sel :in STD_LOGIC_VECTOR(2 downto 0);
        seg:out STD_LOGIC_VECTOR(2 downto 0);
        dout:out STD_LOGIC_VECTOR(7 downto 0) );
        end mux7;
architecture rtl of mux7 is
begin
    dout <= 
	d0 when sel="000" else
	d1 when sel="001" else 
	d2 when sel="010" else 
	d3 when sel="011" else 
	d4 when sel="100" else 
	d5 when sel="101" else
	"00000000";
	seg<=sel;
end rtl;
        
        
