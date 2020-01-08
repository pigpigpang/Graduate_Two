library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
entity dex_add is
port(d:in std_logic_vector(7 downto 0);
 se:in std_logic_vector(2 downto 0);
 dout:out std_logic);
end dex_add;
architecture exa of dex_add is
	component index_add is
		generic(n:integer:=3);
			port(cin: in std_logic_vector (2**n-1 downto 0);
				 sel: in std_logic_vector (n-1 downto 0);
				cout: out std_logic);
	end component;
begin
    g0:index_add generic map(n=>3) port map( cin=>d , sel=>se , cout=>dout);
end exa;