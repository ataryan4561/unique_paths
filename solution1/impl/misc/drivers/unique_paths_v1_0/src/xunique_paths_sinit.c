// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xunique_paths.h"

extern XUnique_paths_Config XUnique_paths_ConfigTable[];

XUnique_paths_Config *XUnique_paths_LookupConfig(u16 DeviceId) {
	XUnique_paths_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XUNIQUE_PATHS_NUM_INSTANCES; Index++) {
		if (XUnique_paths_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XUnique_paths_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XUnique_paths_Initialize(XUnique_paths *InstancePtr, u16 DeviceId) {
	XUnique_paths_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XUnique_paths_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XUnique_paths_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

