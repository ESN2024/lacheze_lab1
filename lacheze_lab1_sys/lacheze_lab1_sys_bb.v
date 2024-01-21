
module lacheze_lab1_sys (
	clk_clk,
	piobp_external_connection_export,
	pioled_external_connection_export,
	reset_reset_n);	

	input		clk_clk;
	input	[7:0]	piobp_external_connection_export;
	output	[7:0]	pioled_external_connection_export;
	input		reset_reset_n;
endmodule
