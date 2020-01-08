library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use IEEE.std_logic_unsigned.all;

entity keeptime is
port(clk,clrn,echo:in STD_LOGIC;
              dout:out std_logic_vector(15 downto 0));
end keeptime ;

architecture arc1 of keeptime  is

signal t:STD_LOGIC_VECTOR(15 downto 0);
signal js:STD_LOGIC_VECTOR(15 downto 0);
begin
   process(echo,clk,clrn,js,t)
   begin
      if clrn='1' then
         js<="0000000000000000";
      else if clk'event and clk='0' then
             if echo='1' then
                  js<=js+1;
             end if;
      end if;
      end if;
      if echo='1' then
         t<="0000000000000000";
      else
         t<=js;
      end if;
      dout<=t;
   end process;
end arc1;