#pragma hdrstop
#include "atNavitarMotorControl.h"
#include "mtkLogger.h"
#include "poco/DateTime.h"

#include "mtkUtils.h"

using namespace mtk;

//---------------------------------------------------------------------------
using namespace mtk;
using Poco::DateTime;

//---------------------------------------------------------------------------
NavitarMotorControl::NavitarMotorControl()
:
mHandle(0),
mZoom( *this,2),
mFocus(*this,1)
{
}

//---------------------------------------------------------------------------
NavitarMotorControl::~NavitarMotorControl()
{
}

NavitarMotor& NavitarMotorControl::getZoom()
{
	return mZoom;
}

NavitarMotor& NavitarMotorControl::getFocus()
{
	return mFocus;
}

//---------------------------------------------------------------------------
bool NavitarMotorControl::connect()
{

    //Check for connected devices
    int res = USBFindUSBinterfaces();

//	Log(lDebug) <<"Connecting motor with ID: "<<mMotorID;
	mHandle = USBConnectionConnect(1, DEF_MOTOR_CONTROLLER);


    if(res != 1)
    {
        Log(lInfo) <<"FAILED to Find any Navitar Motor controller";
        return false;
    }

    //Move on and connect motors
    if(!mZoom.connect())
    {
    	Log(lError) << "Failed to connect to zoom motor";
    }
    else
    {
    	Log(lInfo) << "Motor 1 is connected";
//	    mHandle = mZoom.getHandle();
    }

    if(!mFocus.connect())
    {
    	Log(lError) << "Failed to connect to Focus motor";
    }
    else
    {
    	Log(lInfo) << "Motor 2 is connected";
//    	mHandle = mZoom.getHandle();
    }
	return true;
}

//---------------------------------------------------------------------------
bool NavitarMotorControl::disConnect()
{
	mZoom.disConnect();
    mFocus.disConnect();
    return true;
}

//---------------------------------------------------------------------------
bool NavitarMotorControl::isConnected()
{
	return false;
}

//---------------------------------------------------------------------------
int	NavitarMotorControl::write(const int& reg, long value)
{
	if(mHandle)
    {
		int res = USBConnectionWrite(mHandle, reg, &value);
    }
    return 0;
}

//---------------------------------------------------------------------------
bool NavitarMotorControl::home()
{
	mZoom.home();
    mFocus.home();
    return true;
}

//---------------------------------------------------------------------------
string NavitarMotorControl::getProductID()
{
    if(!mHandle)
    {
    	return "UNDEFINED PRODUCT ID";
    }

	long val;
    int res = USBConnectionRead(mHandle, REG_SYS_PRODUCTID, &val);
    Log(lDebug) <<"Reading Product ID:" << res;
    Log(lDebug) <<"Read result:" << val;

    if(val == 0x4001)
    {
    	return "Motor Controller";
    }
    else if(val == 0x4000)
    {
    	return "BrightLight Controller";
    }
    else
    {
    	return "UNDEFINED";
    }
}

//---------------------------------------------------------------------------
string NavitarMotorControl::getDriverSoftwareBuildDate()
{
    if(!mHandle)
    {
    	return "UNDEFINED SW BUILD DATE";
    }

	long val;
    int res = USBConnectionRead(mHandle, REG_SYS_VERSIONDATE, &val);
    Log(lDebug) <<"Reading version date:" << res<<", "<< val;
	return parseDate(val);
}

//---------------------------------------------------------------------------
string NavitarMotorControl::getHardwareVersion()
{
    if(!mHandle)
    {
    	return "UNDEFINED HW VERSION";
    }

	long val;
    int res = USBConnectionRead(mHandle, REG_SYS_VERSIONHW, &val);
    Log(lDebug) <<"Reading hardware version:" << res<<", "<< val;
	return parseVersion(val);
}

//---------------------------------------------------------------------------
string NavitarMotorControl::getSoftwareVersion()
{
	long val;
    int res = USBConnectionRead(mHandle, REG_SYS_VERSIONSW, &val);
    Log(lDebug) <<"Result and value from USBConnectionRead:" << res<<", "<< val;
	return parseVersion(val);
}

//---------------------------------------------------------------------------
string NavitarMotorControl::parseVersion(long val)
{
	int major 	= (int) (((uint) val & 0xff000000) >> 24);
    int minor	= (int) (((uint) val & 0xff0000) >> 16);
    int rev 	= (int) (((uint) val & 0xff00) >> 8);
    int bug 	= (int) (( uint) val & 0xff);

	stringstream str;
    str<<major<<"."<<minor<<"."<<rev<<"."<<bug;
	return str.str();
}

//---------------------------------------------------------------------------
string NavitarMotorControl::parseDate(long val)
{
	int major 	= (int) (((uint) val & 0xff000000) >> 24);
    int minor	= (int) (((uint) val & 0xff0000) >> 16);
    int rev 	= (int) (((uint) val & 0xff00) >> 8);
    int bug 	= (int) (( uint) val & 0xff);

    DateTime dt(rev + 2000, major, minor);
	return Poco::DateTimeFormatter::format(dt, "%n/%f/%Y");
}


