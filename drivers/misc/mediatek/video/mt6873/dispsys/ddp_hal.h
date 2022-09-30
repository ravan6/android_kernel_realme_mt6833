/*
 * Copyright (C) 2015 MediaTek Inc.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#ifndef _H_DDP_HAL_
#define _H_DDP_HAL_

/* DISP Mutex */
#define DISP_MUTEX_TOTAL      (16)
#define DISP_MUTEX_DDP_FIRST  (0)
/* modify from 4 to 3, cause 4 is used for OVL0/OVL1 SW trigger */
#define DISP_MUTEX_DDP_LAST   (3)
#define DISP_MUTEX_DDP_COUNT  (DISP_MUTEX_DDP_LAST - DISP_MUTEX_DDP_FIRST + 1)
#define DISP_MUTEX_MDP_FIRST  (DISP_MUTEX_DDP_LAST + 1)
#define DISP_MUTEX_MDP_COUNT  (3)
#define __DISP_MUTEX_INT_MSK	((1 << (DISP_MUTEX_DDP_COUNT)) - 1)
#define DISP_MUTEX_INT_MSK	\
	((__DISP_MUTEX_INT_MSK << DISP_MUTEX_TOTAL) | __DISP_MUTEX_INT_MSK)

/* DISP MODULE */
enum DISP_MODULE_ENUM {
	/* must start from 0 */
	DISP_MODULE_CONFIG = 0,
	DISP_MODULE_MUTEX,
	DISP_MODULE_SMI_COMMON,
	DISP_MODULE_SMI_LARB0,
	DISP_MODULE_SMI_LARB1,

	DISP_MODULE_OVL0,
	DISP_MODULE_OVL0_2L,
	DISP_MODULE_RDMA0,
	DISP_MODULE_RSZ0,
	DISP_MODULE_COLOR0,

	DISP_MODULE_CCORR0,
	DISP_MODULE_AAL0,
	DISP_MODULE_GAMMA0,
	DISP_MODULE_POSTMASK0,
	DISP_MODULE_DITHER0,

	DISP_MODULE_DSC_WRAP0_CORE0,
	DISP_MODULE_DSC_WRAP0_CORE1,
	DISP_MODULE_DSI0,
	DISP_MODULE_WDMA0,
	DISP_MODULE_UFBC_WDMA0,

	DISP_MODULE_OVL2_2L,
	DISP_MODULE_RDMA4,
	DISP_MODULE_DPI,
	DISP_MODULE_MDP_RDMA4,
	DISP_MODULE_MDP_HDR4,

	DISP_MODULE_MDP_RSZ4,
	DISP_MODULE_MDP_AAL4,
	DISP_MODULE_MDP_TDSHP4,
	DISP_MODULE_MDP_COLOR4,
	DISP_MODULE_Y2R0,

	DISP_MODULE_PWM0,
	DISP_MODULE_DSIDUAL,
	DISP_MODULE_DSI1,
	DISP_MODULE_MIPI0,
	DISP_MODULE_MIPI1,

	/* TODO : add virturl module for connect path*/
	DISP_MODULE_OVL0_2L_VIRTUAL0,
	DISP_MODULE_OVL0_VIRTUAL0,
	DISP_MODULE_OVL0_OVL0_2L_VIRTUAL,
	DISP_MODULE_RDMA2_VIRTUAL,
	DISP_MODULE_DMDP_TDSHP4_SOUT,

	DISP_MODULE_SPLIT0,
	DISP_MODULE_UNKNOWN,
	DISP_MODULE_NUM
};


/* DISP MODULE */
enum DISP_MODULE_TYPE_ENUM {
	DISP_T_OVL = 0, /* must start from 0 */
	DISP_T_RSZ,
	DISP_T_RDMA,
	DISP_T_WDMA,
	DISP_T_COLOR,

	DISP_T_CCORR, /* 5 */
	DISP_T_AAL,
	DISP_T_GAMMA,
	DISP_T_DITHER,
	DISP_T_SPLIT,

	DISP_T_DSI,  /* 10 */
	DISP_T_PWM,
	DISP_T_DPI,
	DISP_T_POSTMASK,
	DISP_T_UNKNOWN,
	DISP_T_NUM,

};

enum dst_module_type {
	DST_MOD_REAL_TIME,
	DST_MOD_WDMA,
};

enum DISP_SLOT_ENUM {
	DISP_SLOT_IS_DC,
	DISP_SLOT_OVL0_BW,
	DISP_SLOT_OVL0_2L_BW,
	DISP_SLOT_RDMA0_BW,
	DISP_SLOT_WDMA0_BW,
	DISP_SLOT_NUM,
};

enum OVL_LAYER_SOURCE {
	OVL_LAYER_SOURCE_MEM = 0,
	OVL_LAYER_SOURCE_RESERVED = 1,
	OVL_LAYER_SOURCE_SCL = 2,
	OVL_LAYER_SOURCE_PQ = 3,
};

enum OVL_LAYER_SECURE_MODE {
	OVL_LAYER_NORMAL_BUFFER = 0,
	OVL_LAYER_SECURE_BUFFER = 1,
	OVL_LAYER_PROTECTED_BUFFER = 2
};

enum CMDQ_SWITCH {
	CMDQ_DISABLE = 0,
	CMDQ_ENABLE
};

enum CMDQ_STATE {
	CMDQ_WAIT_LCM_TE,
	CMDQ_BEFORE_STREAM_SOF,
	CMDQ_WAIT_STREAM_EOF_EVENT,
	CMDQ_CHECK_IDLE_AFTER_STREAM_EOF,
	CMDQ_AFTER_STREAM_EOF,
	CMDQ_ESD_CHECK_READ,
	CMDQ_ESD_CHECK_CMP,
	CMDQ_ESD_ALLC_SLOT,
	CMDQ_ESD_FREE_SLOT,
	CMDQ_STOP_VDO_MODE,
	CMDQ_START_VDO_MODE,
	CMDQ_DSI_RESET,
	CMDQ_AFTER_STREAM_SOF,
	CMDQ_DSI_LFR_MODE,
	CMDQ_RESET_AFTER_STREAM_EOF,
};

enum DDP_IRQ_LEVEL {
	DDP_IRQ_LEVEL_ALL = 0,
	DDP_IRQ_LEVEL_NONE,
	DDP_IRQ_LEVEL_ERROR
};


#endif
