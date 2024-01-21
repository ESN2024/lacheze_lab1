	component lacheze_lab1_sys is
		port (
			clk_clk                           : in  std_logic                    := 'X';             -- clk
			piobp_external_connection_export  : in  std_logic_vector(7 downto 0) := (others => 'X'); -- export
			pioled_external_connection_export : out std_logic_vector(7 downto 0);                    -- export
			reset_reset_n                     : in  std_logic                    := 'X'              -- reset_n
		);
	end component lacheze_lab1_sys;

	u0 : component lacheze_lab1_sys
		port map (
			clk_clk                           => CONNECTED_TO_clk_clk,                           --                        clk.clk
			piobp_external_connection_export  => CONNECTED_TO_piobp_external_connection_export,  --  piobp_external_connection.export
			pioled_external_connection_export => CONNECTED_TO_pioled_external_connection_export, -- pioled_external_connection.export
			reset_reset_n                     => CONNECTED_TO_reset_reset_n                      --                      reset.reset_n
		);

