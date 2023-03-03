/*
 * EX_INT_Private.h
 *
 * Created: 2/24/2023 9:50:38 AM
 *  Author: amrba
 */ 


#ifndef EX_INT_PRIVATE_H_
#define EX_INT_PRIVATE_H_
#include "../../STD_TYPES.h"

  


#define MCUCReg  *((u8*)0x55)
#define MCUCSReg *((u8*)0x54)
#define GICReg   *((u8*)0x5B)
#define GIFReg   *((u8*)0x5A)

#endif /* EX_INT_PRIVATE_H_ */