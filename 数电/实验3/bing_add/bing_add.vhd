library ieee;
use ieee.std_logic_1164.all;
entity bing_add is
port(A, B : in std_logic_vector(0 to 3);
	 cin:in std_logic;
	 S : out std_logic_vector(0 to 3);
	 C : out std_logic);
end bing_add;
architecture bhv of bing_add is
component all_add is
port(x,y,z : in std_logic;
	 s,c : out std_logic);
end component;
signal temp : std_logic_vector(0 to 2);
begin
	g0 : all_add port map(A(3), B(3), cin, S(3), temp(0));
	g1 : all_add port map(A(2), B(2), temp(0), S(2), temp(1));
	g2 : all_add port map(A(1), B(1), temp(1), S(1), temp(2));
	g3 : all_add port map(A(0), B(0), temp(2), S(0), C);
end;