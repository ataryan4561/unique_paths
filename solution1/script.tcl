############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project unique_paths
set_top unique_paths
add_files unique_paths/header.h
add_files unique_paths/main.c
add_files -tb unique_paths/test.c
open_solution "solution1"
set_part {xc7z020clg484-1} -tool vivado
create_clock -period 10 -name default
set_clock_uncertainty 1.25
#source "./unique_paths/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
