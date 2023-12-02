// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XUNIQUE_PATHS_H
#define XUNIQUE_PATHS_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xunique_paths_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#else
typedef struct {
    u16 DeviceId;
    u32 Axilites_BaseAddress;
} XUnique_paths_Config;
#endif

typedef struct {
    u32 Axilites_BaseAddress;
    u32 IsReady;
} XUnique_paths;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XUnique_paths_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XUnique_paths_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XUnique_paths_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XUnique_paths_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XUnique_paths_Initialize(XUnique_paths *InstancePtr, u16 DeviceId);
XUnique_paths_Config* XUnique_paths_LookupConfig(u16 DeviceId);
int XUnique_paths_CfgInitialize(XUnique_paths *InstancePtr, XUnique_paths_Config *ConfigPtr);
#else
int XUnique_paths_Initialize(XUnique_paths *InstancePtr, const char* InstanceName);
int XUnique_paths_Release(XUnique_paths *InstancePtr);
#endif

void XUnique_paths_Start(XUnique_paths *InstancePtr);
u32 XUnique_paths_IsDone(XUnique_paths *InstancePtr);
u32 XUnique_paths_IsIdle(XUnique_paths *InstancePtr);
u32 XUnique_paths_IsReady(XUnique_paths *InstancePtr);
void XUnique_paths_EnableAutoRestart(XUnique_paths *InstancePtr);
void XUnique_paths_DisableAutoRestart(XUnique_paths *InstancePtr);

void XUnique_paths_Set_n(XUnique_paths *InstancePtr, u32 Data);
u32 XUnique_paths_Get_n(XUnique_paths *InstancePtr);
void XUnique_paths_Set_m(XUnique_paths *InstancePtr, u32 Data);
u32 XUnique_paths_Get_m(XUnique_paths *InstancePtr);
u32 XUnique_paths_Get_ans(XUnique_paths *InstancePtr);
u32 XUnique_paths_Get_ans_vld(XUnique_paths *InstancePtr);

void XUnique_paths_InterruptGlobalEnable(XUnique_paths *InstancePtr);
void XUnique_paths_InterruptGlobalDisable(XUnique_paths *InstancePtr);
void XUnique_paths_InterruptEnable(XUnique_paths *InstancePtr, u32 Mask);
void XUnique_paths_InterruptDisable(XUnique_paths *InstancePtr, u32 Mask);
void XUnique_paths_InterruptClear(XUnique_paths *InstancePtr, u32 Mask);
u32 XUnique_paths_InterruptGetEnabled(XUnique_paths *InstancePtr);
u32 XUnique_paths_InterruptGetStatus(XUnique_paths *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
