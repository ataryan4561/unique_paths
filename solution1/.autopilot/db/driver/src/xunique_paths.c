// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xunique_paths.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XUnique_paths_CfgInitialize(XUnique_paths *InstancePtr, XUnique_paths_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Axilites_BaseAddress = ConfigPtr->Axilites_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XUnique_paths_Start(XUnique_paths *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XUnique_paths_ReadReg(InstancePtr->Axilites_BaseAddress, XUNIQUE_PATHS_AXILITES_ADDR_AP_CTRL) & 0x80;
    XUnique_paths_WriteReg(InstancePtr->Axilites_BaseAddress, XUNIQUE_PATHS_AXILITES_ADDR_AP_CTRL, Data | 0x01);
}

u32 XUnique_paths_IsDone(XUnique_paths *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XUnique_paths_ReadReg(InstancePtr->Axilites_BaseAddress, XUNIQUE_PATHS_AXILITES_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XUnique_paths_IsIdle(XUnique_paths *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XUnique_paths_ReadReg(InstancePtr->Axilites_BaseAddress, XUNIQUE_PATHS_AXILITES_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XUnique_paths_IsReady(XUnique_paths *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XUnique_paths_ReadReg(InstancePtr->Axilites_BaseAddress, XUNIQUE_PATHS_AXILITES_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XUnique_paths_EnableAutoRestart(XUnique_paths *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XUnique_paths_WriteReg(InstancePtr->Axilites_BaseAddress, XUNIQUE_PATHS_AXILITES_ADDR_AP_CTRL, 0x80);
}

void XUnique_paths_DisableAutoRestart(XUnique_paths *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XUnique_paths_WriteReg(InstancePtr->Axilites_BaseAddress, XUNIQUE_PATHS_AXILITES_ADDR_AP_CTRL, 0);
}

void XUnique_paths_Set_n(XUnique_paths *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XUnique_paths_WriteReg(InstancePtr->Axilites_BaseAddress, XUNIQUE_PATHS_AXILITES_ADDR_N_DATA, Data);
}

u32 XUnique_paths_Get_n(XUnique_paths *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XUnique_paths_ReadReg(InstancePtr->Axilites_BaseAddress, XUNIQUE_PATHS_AXILITES_ADDR_N_DATA);
    return Data;
}

void XUnique_paths_Set_m(XUnique_paths *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XUnique_paths_WriteReg(InstancePtr->Axilites_BaseAddress, XUNIQUE_PATHS_AXILITES_ADDR_M_DATA, Data);
}

u32 XUnique_paths_Get_m(XUnique_paths *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XUnique_paths_ReadReg(InstancePtr->Axilites_BaseAddress, XUNIQUE_PATHS_AXILITES_ADDR_M_DATA);
    return Data;
}

u32 XUnique_paths_Get_ans(XUnique_paths *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XUnique_paths_ReadReg(InstancePtr->Axilites_BaseAddress, XUNIQUE_PATHS_AXILITES_ADDR_ANS_DATA);
    return Data;
}

u32 XUnique_paths_Get_ans_vld(XUnique_paths *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XUnique_paths_ReadReg(InstancePtr->Axilites_BaseAddress, XUNIQUE_PATHS_AXILITES_ADDR_ANS_CTRL);
    return Data & 0x1;
}

void XUnique_paths_InterruptGlobalEnable(XUnique_paths *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XUnique_paths_WriteReg(InstancePtr->Axilites_BaseAddress, XUNIQUE_PATHS_AXILITES_ADDR_GIE, 1);
}

void XUnique_paths_InterruptGlobalDisable(XUnique_paths *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XUnique_paths_WriteReg(InstancePtr->Axilites_BaseAddress, XUNIQUE_PATHS_AXILITES_ADDR_GIE, 0);
}

void XUnique_paths_InterruptEnable(XUnique_paths *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XUnique_paths_ReadReg(InstancePtr->Axilites_BaseAddress, XUNIQUE_PATHS_AXILITES_ADDR_IER);
    XUnique_paths_WriteReg(InstancePtr->Axilites_BaseAddress, XUNIQUE_PATHS_AXILITES_ADDR_IER, Register | Mask);
}

void XUnique_paths_InterruptDisable(XUnique_paths *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XUnique_paths_ReadReg(InstancePtr->Axilites_BaseAddress, XUNIQUE_PATHS_AXILITES_ADDR_IER);
    XUnique_paths_WriteReg(InstancePtr->Axilites_BaseAddress, XUNIQUE_PATHS_AXILITES_ADDR_IER, Register & (~Mask));
}

void XUnique_paths_InterruptClear(XUnique_paths *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XUnique_paths_WriteReg(InstancePtr->Axilites_BaseAddress, XUNIQUE_PATHS_AXILITES_ADDR_ISR, Mask);
}

u32 XUnique_paths_InterruptGetEnabled(XUnique_paths *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XUnique_paths_ReadReg(InstancePtr->Axilites_BaseAddress, XUNIQUE_PATHS_AXILITES_ADDR_IER);
}

u32 XUnique_paths_InterruptGetStatus(XUnique_paths *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XUnique_paths_ReadReg(InstancePtr->Axilites_BaseAddress, XUNIQUE_PATHS_AXILITES_ADDR_ISR);
}

