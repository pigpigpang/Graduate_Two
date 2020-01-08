library ieee;
use ieee.std_logic_1164.all;
entity ywjcq_4 is
port(
	SI,clk : in std_logic;
	SO : out std_logic;
	output : out std_logic_vector(3 downto 0)
	);
end ywjcq_4;
architecture rtl of ywjcq_4 is
component dcqf
	port(
		D,C : in std_logic;
		q : out std_logic
		);
end component;
signal z : std_logic_vector(4 downto 0);
begin
	z(4) <= SI;
	g0 : for i in 4 downto 1 generate
	g1 : dcqf port map(z(i),clk,z(i-1));
	end generate;
	SO <= z(0);
	output <= z(4 downto 1);
end rtl;