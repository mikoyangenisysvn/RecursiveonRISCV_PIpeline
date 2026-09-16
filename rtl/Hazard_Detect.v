//17 Hazard_detect
module hazard_detect (
  input  wire       Is_Load_E,
  input  wire [4:0] addrD_E,
  input  wire [4:0] addrA_D, addrB_D,
  input  wire       UsesRs1_D, UsesRs2_D,
  output wire       stall_load
);

  assign stall_load = Is_Load_E && (addrD_E != 5'b0) &&
    ((UsesRs1_D && (addrD_E == addrA_D)) ||
     (UsesRs2_D && (addrD_E == addrB_D)));

endmodule
