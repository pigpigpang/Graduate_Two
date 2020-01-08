LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_unsigned.ALL;
ENTITY average IS
    PORT(
        dis: in integer range 0 to 500;
        newclk: in std_logic;
        average: out integer range 0 to 500
        );
END ENTITY average ;
ARCHITECTURE average_arch OF average  IS 
signal n:integer range 0 to 20;
signal count:integer range 0 to 12000;
begin 
process(newclk)
begin
if(newclk'event and newclk='1') then
  if(n=20) then 
     n<=0;average<=count/19;
  elsif(n=0) then n<=n+1;count<=0;--numout<=0;
  else n<=n+1;count<=dis+count;--numout<=1;
  end if;
end if;
end process;
end average_arch;