library ieee;
use ieee.std_logic_1164.all;

entity instr is
	port (
			EN : in std_logic;
			IR : in std_logic_vector(0 to 7);
			MOVA, MOVB, MOVC, ADD, SUB, OR0, NOT0, RSR, RSL, JMP, JZ, JC, IN0, OUT0, NOP, HALT : out std_logic
		);
end entity instr;

architecture instr_op of instr is
signal command : std_logic_vector(3 downto 0);
signal R1, R2 : std_logic_vector(1 downto 0);
begin
	command <= IR(0 to 3);
	R1 <= IR(4 to 5);
	R2 <= IR(6 to 7);
	process(IR,command,R1,R2,EN)
	begin
		MOVA <= '0';
		MOVB <= '0';
		MOVC <= '0';
		ADD <= '0';
		SUB <= '0';
		OR0 <= '0';
		NOT0 <= '0';
		RSR <= '0';
		RSL <= '0';
		JMP <= '0';
		JZ <= '0';
		JC <= '0';
		IN0 <= '0';
		OUT0 <= '0';
		NOP <= '0';
		HALT <= '0';
		if EN = '0' then 
			if command = "1111" then
				if R1 = "11" then
					MOVB <= '1';
				elsif R2 = "11" then
					MOVC <= '1';
				else
					MOVA <= '1';
				end if;
			elsif command = "1001" then
				ADD <= '1';
			elsif command = "0110" then
				SUB <= '1';
			elsif command = "1011" then
				OR0 <= '1';
			elsif command = "0101" then
				NOT0 <= '1';
			elsif command = "1010" then
				if R2 = "00" then
					RSR <= '1';
				else
					RSL <= '1';
				end if;
			elsif command = "0001" then
				if R2 = "00" then
					JMP <= '1';
				elsif R2 = "01" then
					JZ <= '1';
				elsif R2 = "10" then
					JC <= '1';
				end if;
			elsif command = "0010" then
				IN0 <= '1';
			elsif command = "0100" then
				OUT0 <= '1';
			elsif command = "0111" then
				NOP <= '1';
			elsif command = "1000" then
				HALT <= '1';
			end if;
		end if;
	end process;
end architecture instr_op;