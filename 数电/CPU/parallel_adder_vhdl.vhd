library ieee;
use ieee.std_logic_1164.all;

entity  parallel_adder_vhdl is
port(
	A,B : in std_logic_vector(7 downto 0);
	C0 : in std_logic;
	S : out std_logic_vector(7 downto 0);
	C8 : out std_logic);
end parallel_adder_vhdl;

architecture str of parallel_adder_vhdl is
	component full_adder is
	port(
		x,y,z : in std_logic;
		s,c : out std_logic);
	end component;
	signal  C : std_logic_vector (8 downto 0);
	signal  BF : std_logic_vector (7 downto 0);
	begin
		BF(0) <= C0 xor B(0);
		BF(1) <= C0 xor B(1);
		BF(2) <= C0 xor B(2);
		BF(3) <= C0 xor B(3);
		BF(4) <= C0 xor B(4);
		BF(5) <= C0 xor B(5);
		BF(6) <= C0 xor B(6);
		BF(7) <= C0 xor B(7);
		FA1	: full_adder
		port map (A(0), BF(0), C(0), S(0), C(1));
		FA2	: full_adder
		port map (A(1), BF(1), C(1), S(1), C(2));
		FA3	: full_adder
		port map (A(2), BF(2), C(2), S(2), C(3));
		FA4	: full_adder
		port map (A(3), BF(3), C(3), S(3), C(4));
		FA5	: full_adder
		port map (A(4), BF(4), C(4), S(4), C(5));
		FA6	: full_adder
		port map (A(5), BF(5), C(5), S(5), C(6));
		FA7	: full_adder
		port map (A(6), BF(6), C(6), S(6), C(7));
		FA8	: full_adder
		port map (A(7), BF(7), C(7), S(7), C(8));
		C(0) <= C0;
		C8 <= C(8);
end str;