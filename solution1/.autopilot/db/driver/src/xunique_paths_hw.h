// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
// AXILiteS
// 0x00 : Control signals
//        bit 0  - ap_start (Read/Write/COH)
//        bit 1  - ap_done (Read/COR)
//        bit 2  - ap_idle (Read)
//        bit 3  - ap_ready (Read)
//        bit 7  - auto_restart (Read/Write)
//        others - reserved
// 0x04 : Global Interrupt Enable Register
//        bit 0  - Global Interrupt Enable (Read/Write)
//        others - reserved
// 0x08 : IP Interrupt Enable Register (Read/Write)
//        bit 0  - Channel 0 (ap_done)
//        bit 1  - Channel 1 (ap_ready)
//        others - reserved
// 0x0c : IP Interrupt Status Register (Read/TOW)
//        bit 0  - Channel 0 (ap_done)
//        bit 1  - Channel 1 (ap_ready)
//        others - reserved
// 0x10 : Data signal of n
//        bit 31~0 - n[31:0] (Read/Write)
// 0x14 : reserved
// 0x18 : Data signal of m
//        bit 31~0 - m[31:0] (Read/Write)
// 0x1c : reserved
// 0x20 : Data signal of ans
//        bit 31~0 - ans[31:0] (Read)
// 0x24 : Control signal of ans
//        bit 0  - ans_ap_vld (Read/COR)
//        others - reserved
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#define XUNIQUE_PATHS_AXILITES_ADDR_AP_CTRL  0x00
#define XUNIQUE_PATHS_AXILITES_ADDR_GIE      0x04
#define XUNIQUE_PATHS_AXILITES_ADDR_IER      0x08
#define XUNIQUE_PATHS_AXILITES_ADDR_ISR      0x0c
#define XUNIQUE_PATHS_AXILITES_ADDR_N_DATA   0x10
#define XUNIQUE_PATHS_AXILITES_BITS_N_DATA   32
#define XUNIQUE_PATHS_AXILITES_ADDR_M_DATA   0x18
#define XUNIQUE_PATHS_AXILITES_BITS_M_DATA   32
#define XUNIQUE_PATHS_AXILITES_ADDR_ANS_DATA 0x20
#define XUNIQUE_PATHS_AXILITES_BITS_ANS_DATA 32
#define XUNIQUE_PATHS_AXILITES_ADDR_ANS_CTRL 0x24

