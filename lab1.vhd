
library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
use ieee.numeric_std.all;

entity lab1 is Port(
    clk,reset : in std_logic;
    bp : in std_logic_vector(7 downto 0);
    led : out std_logic_vector(7 downto 0)
    );
end entity;

architecture arch of lab1 is

 
    
    component lacheze_lab1_sys is
        port (
            clk_clk                           : in  std_logic                    := 'X';             -- clk
            piobp_external_connection_export  : in  std_logic_vector(7 downto 0) := (others => 'X'); -- export
            pioled_external_connection_export : out std_logic_vector(7 downto 0);                    -- export
            reset_reset_n                     : in  std_logic                    := 'X'              -- reset_n
        );
    end component lacheze_lab1_sys;
begin
    u0 : component lacheze_lab1_sys
        port map (
            clk_clk                           => clk,                           --                        clk.clk
            piobp_external_connection_export  => bp,  --  piobp_external_connection.export
            pioled_external_connection_export => led, -- pioled_external_connection.export
            reset_reset_n                     => reset                      --                      reset.reset_n
        );



      end architecture;