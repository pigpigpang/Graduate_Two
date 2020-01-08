library IEEE;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
use ieee.std_logic_arith.all;
entity mod8 is
port(
	clk:in STD_LOGIC;
	c_out:out STD_LOGIC_VECTOR(2 downto 0));
end mod8;
architecture mo8 of mod8 is
signal iq:integer;
begin
	process(clk)
	begin
	if clk'event and clk='1' then
	 if iq=8 then iq<=0;
	 else iq<=iq+1;
	 end if;
	end if;
	c_out <= conv_std_logic_vector(iq,3);
	end process;
end mo8; 