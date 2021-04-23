///////////////////////////////////////////////////////////////////////////////
// EncoderVelocityTestingDriver.cpp
#include "TcPch.h"
#pragma hdrstop

#include "EncoderVelocityTestingDriver.h"
#include "EncoderVelocityTestingClassFactory.h"

DECLARE_GENERIC_DEVICE(ENCODERVELOCITYTESTINGDRV)

IOSTATUS CEncoderVelocityTestingDriver::OnLoad( )
{
	TRACE(_T("CObjClassFactory::OnLoad()\n") );
	m_pObjClassFactory = new CEncoderVelocityTestingClassFactory();

	return IOSTATUS_SUCCESS;
}

VOID CEncoderVelocityTestingDriver::OnUnLoad( )
{
	delete m_pObjClassFactory;
}

unsigned long _cdecl CEncoderVelocityTestingDriver::ENCODERVELOCITYTESTINGDRV_GetVersion( )
{
	return( (ENCODERVELOCITYTESTINGDRV_Major << 8) | ENCODERVELOCITYTESTINGDRV_Minor );
}

