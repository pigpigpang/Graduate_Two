library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
entity echo_count is
port( clk,echo : in std_logic;
	  cc : out std_logic;
	  ccc: out integer;
	  time_out : out std_logic_vector(7 downto 0));
end entity echo_count;
architecture bhv of echo_count is
signal t : integer range 0 to 2097152:=0;
signal c : std_logic:='0';
signal temp : std_logic_vector(8 downto 0):="000000000";
begin
	process(clk,echo)
	begin
		if(clk'event and clk = '1') then
			if(echo = '1') then
				t<= t+1;
				c<='1';
			elsif(c<='1' and echo='0') then
				temp <= conv_std_logic_vector(t/4800,9);
				c<='0';
				t<=0;
			end if;
		end if;
	end process;
	time_out<=temp(7 downto 0);
	cc <= c;
	ccc<=t;
end bhv;