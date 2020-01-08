library IEEE;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
use ieee.std_logic_arith.all;
entity dac_b is
 port(
       vec:in STD_LOGIC_VECTOR( 7 downto 0);
       p0,p1,p2,p3,p4,p5,p6,p7:out STD_LOGIC_VECTOR(7 downto 0));
end dac_b;

architecture dac of dac_b is
begin
	process(vec)
	variable count:integer range 0 to 255;
	variable V:integer range 0 to 510;
	variable s0,s1,s2,c0,c1,c2:integer range 0 to 9;
	begin
		count:=conv_integer(vec);
		V:=count*2;
		s0:=count rem 10;
		count:=count / 10;
		s1:=count rem 10;
		count := count /10 ;
		s2:=count rem 10;
		c0:=V rem 10;
		V:=V/10;
		c1:=V rem 10;
		V:=V/10;
		c2:=V rem 10;
		if s0=0 then p0<="00111111";
		elsif s0=1 then p0<="00000110";
		elsif s0=2 then p0<="01011011";
		elsif s0=3 then p0<="01001111";
		elsif s0=4 then p0<="01100110";
		elsif s0=5 then p0<="01101101";
		elsif s0=6 then p0<="01111101";
		elsif s0=7 then p0<="00000111";
		elsif s0=8 then p0<="01111111";
		elsif s0=9 then p0<="01001111";
		end if;
		if s1=0 then p1<="00111111";
		elsif s1=1 then p1<="00000110";
		elsif s1=2 then p1<="01011011";
		elsif s1=3 then p1<="01001111";
		elsif s1=4 then p1<="01100110";
		elsif s1=5 then p1<="01101101";
		elsif s1=6 then p1<="01111101";
		elsif s1=7 then p1<="00000111";
		elsif s1=8 then p1<="01111111";
		elsif s1=9 then p1<="01001111";
		end if;
		if s2=0 then p2<="00111111";
		elsif s2=1 then p2<="00000110";
		elsif s2=2 then p2<="01011011";
		elsif s2=3 then p2<="01001111";
		elsif s2=4 then p2<="01100110";
		elsif s2=5 then p2<="01101101";
		elsif s2=6 then p2<="01111101";
		elsif s2=7 then p2<="00000111";
		elsif s2=8 then p2<="01111111";
		elsif s2=9 then p2<="01001111";
		end if;
		if c0=0 then p5<="00111111";
		elsif c0=1 then p5<="00000110";
		elsif c0=2 then p5<="01011011";
		elsif c0=3 then p5<="01001111";
		elsif c0=4 then p5<="01100110";
		elsif c0=5 then p5<="01101101";
		elsif c0=6 then p5<="01111101";
		elsif c0=7 then p5<="00000111";
		elsif c0=8 then p5<="01111111";
		elsif c0=9 then p5<="01001111";
		end if;
		if c1=0 then p6<="00111111";
		elsif c1=1 then p6<="00000110";
		elsif c1=2 then p6<="01011011";
		elsif c1=3 then p6<="01001111";
		elsif c1=4 then p6<="01100110";
		elsif c1=5 then p6<="01101101";
		elsif c1=6 then p6<="01111101";
		elsif c1=7 then p6<="00000111";
		elsif c1=8 then p6<="01111111";
		elsif c1=9 then p6<="01001111";
		end if;
		if c2=0 then p7<="10111111";
		elsif c2=1 then p7<="10000110";
		elsif c2=2 then p7<="11011011";
		elsif c2=3 then p7<="11001111";
		elsif c2=4 then p7<="11100110";
		elsif c2=5 then p7<="11101101";
		elsif c2=6 then p7<="11111101";
		elsif c2=7 then p7<="10000111";
		elsif c2=8 then p7<="11111111";
		elsif c2=9 then p7<="11001111";
		end if;
	end process;
end dac;