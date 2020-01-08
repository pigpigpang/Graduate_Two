library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
entity alu_ex3 is
port(m: in std_logic;
	s: in std_logic_vector(3 downto 0);
	a: in std_logic_vector(7 downto 0);
	b: in std_logic_vector(7 downto 0);
	T: out std_logic_vector(7 downto 0);
	cf,cz: out std_logic);
end alu_ex3;
architecture bhv of alu_ex3 is
signal aa,bb,cc : std_logic_vector(8 downto 0);
signal jinwei,weiling : std_logic;
begin
	process(m,s,a,b)
	begin
		aa<= '0'&a;
		bb<= '0'&b;
		if m='1' then
			if s="1001" then
				cc<=aa+bb;
				jinwei<=cc(8);
				if cc(7 downto 0)="00000000" then weiling<='1';
				end if;
			elsif s="0110" then
				cc<=aa-bb;
				jinwei<=cc(8);
				if cc(7 downto 0)="00000000" then weiling<='1';
				end if;
			elsif s="1011" then
				cc<=aa or bb;
			elsif s="0101" then
				cc<=not aa;
			end if;
		end if;
		T<=cc(7 downto 0);
		cf<=jinwei;
		cz<=weiling;
	end process;
end;