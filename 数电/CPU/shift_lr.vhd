library ieee;
use ieee.std_logic_1164.all;

entity shift_lr is
port (
	F_BUS,FL_BUS,FR_BUS : in std_logic;
	I : in std_logic_vector(7 downto 0);
	C : out std_logic;
	shift : out std_logic_vector(7 downto 0));
end shift_lr;

architecture beh of shift_lr is
begin
	process (F_BUS,FR_BUS,FL_BUS)
	begin
	if (F_BUS = '1') then
		shift <= I;
	elsif (FL_BUS = '1') then
		shift <= I(6 downto 0) & '0';
		C <= I(7);
	elsif (FR_BUS = '1') then
		shift <= '0' & I(7 downto 1);
		C <= I(0);
	elsif(F_BUS = '0') then
		shift <= "ZZZZZZZZ";
	end if;
end process;
end beh;