library ieee;
use ieee.std_logic_1164.all;

entity all_add is
port(x, y, z : in std_logic;
	 s, c : out std_logic);
end;

architecture add of all_add is
begin
	s <= (x xor y) xor z;
	c <= (x and y) or (z and (x xor y));
end add;