///////////////////////////////////////////////////////////////////////////////
// EncoderVelocityTestingDriver.h

#ifndef __ENCODERVELOCITYTESTINGDRIVER_H__
#define __ENCODERVELOCITYTESTINGDRIVER_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TcBase.h"

#define ENCODERVELOCITYTESTINGDRV_NAME        "ENCODERVELOCITYTESTING"
#define ENCODERVELOCITYTESTINGDRV_Major       1
#define ENCODERVELOCITYTESTINGDRV_Minor       0

#define DEVICE_CLASS CEncoderVelocityTestingDriver

#include "ObjDriver.h"

class CEncoderVelocityTestingDriver : public CObjDriver
{
public:
	virtual IOSTATUS	OnLoad();
	virtual VOID		OnUnLoad();

	//////////////////////////////////////////////////////
	// VxD-Services exported by this driver
	static unsigned long	_cdecl ENCODERVELOCITYTESTINGDRV_GetVersion();
	//////////////////////////////////////////////////////
	
};

Begin_VxD_Service_Table(ENCODERVELOCITYTESTINGDRV)
	VxD_Service( ENCODERVELOCITYTESTINGDRV_GetVersion )
End_VxD_Service_Table


#endif // ifndef __ENCODERVELOCITYTESTINGDRIVER_H__