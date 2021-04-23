///////////////////////////////////////////////////////////////////////////////
// EncoderVelocityTestingCtrl.h

#ifndef __ENCODERVELOCITYTESTINGCTRL_H__
#define __ENCODERVELOCITYTESTINGCTRL_H__

#include <atlbase.h>
#include <atlcom.h>


#include "resource.h"       // main symbols
#include "EncoderVelocityTestingW32.h"
#include "TcBase.h"
#include "EncoderVelocityTestingClassFactory.h"
#include "TcOCFCtrlImpl.h"

class CEncoderVelocityTestingCtrl 
	: public CComObjectRootEx<CComMultiThreadModel>
	, public CComCoClass<CEncoderVelocityTestingCtrl, &CLSID_EncoderVelocityTestingCtrl>
	, public IEncoderVelocityTestingCtrl
	, public ITcOCFCtrlImpl<CEncoderVelocityTestingCtrl, CEncoderVelocityTestingClassFactory>
{
public:
	CEncoderVelocityTestingCtrl();
	virtual ~CEncoderVelocityTestingCtrl();

DECLARE_REGISTRY_RESOURCEID(IDR_ENCODERVELOCITYTESTINGCTRL)
DECLARE_NOT_AGGREGATABLE(CEncoderVelocityTestingCtrl)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CEncoderVelocityTestingCtrl)
	COM_INTERFACE_ENTRY(IEncoderVelocityTestingCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl2)
END_COM_MAP()

};

#endif // #ifndef __ENCODERVELOCITYTESTINGCTRL_H__
