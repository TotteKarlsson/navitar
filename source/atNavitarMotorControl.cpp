#pragma hdrstop
#include "atNavitarMotorControl.h"
#include "mtkLogger.h"
#include "poco/DateTime.h"
//---------------------------------------------------------------------------

using namespace mtk;
using Poco::DateTime;

//---------------------------------------------------------------------------
NavitarMotorControl::NavitarMotorControl()
:
mHandle(0),
mZoom(*this, 1),
mFocus(*this,2)
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
    if(res != 1)
    {
        Log(lInfo) <<"FAILED to Find any Navitar Motor controller";
        return false;
    }

    mHandle = USBConnectionConnect(1, DEF_MOTOR_CONTROLLER);
    Log(lDebug) <<"Result from USBConnectionConnect:" << mHandle;
    Log(lDebug) <<"Handle is:" << mHandle;

    if(USBConnectionEstablished(mHandle, DEF_MOTOR_CONTROLLER))
    {
        Log(lInfo) <<"Connection established to Navitar Motor controller";
        return true;
    }
    else
    {
        Log(lInfo) <<"Connection FAILED to Navitar Motor controller";
        return false;
    }
}

//---------------------------------------------------------------------------
bool NavitarMotorControl::disConnect()
{
    return USBConnectionDisconnect(mHandle);
}

//---------------------------------------------------------------------------
bool NavitarMotorControl::isConnected()
{
	return USBConnectionEstablished(mHandle, DEF_MOTOR_CONTROLLER);
}

//---------------------------------------------------------------------------
int	NavitarMotorControl::write(const int& reg, long value)
{
	return USBConnectionWrite(mHandle, reg, &value);
}

//---------------------------------------------------------------------------
bool NavitarMotorControl::home()
{
	mZoom.home();
    mFocus.home();
}

//---------------------------------------------------------------------------
string NavitarMotorControl::getProductID()
{
	long val;
    int res = USBConnectionRead(mHandle, REG_SYS_PRODUCTID, &val);
    Log(lDebug) <<"Result from USBConnectionRead:" << res;
    Log(lDebug) <<"Read result:" << val;

    if(val == 0x4001)
    {
    	return "Motor Controller";
    }
    else if(val == 0x4000)
    {
    	return "BrightLight Controller";
    }
}

//---------------------------------------------------------------------------
string NavitarMotorControl::getDriverSoftwareBuildDate()
{
	long val;
    int res = USBConnectionRead(mHandle, REG_SYS_VERSIONDATE, &val);
    Log(lDebug) <<"Result and value from USBConnectionRead:" << res<<", "<< val;
	return parseDate(val);
}

//---------------------------------------------------------------------------
string NavitarMotorControl::getHardwareVersion()
{
	long val;
    int res = USBConnectionRead(mHandle, REG_SYS_VERSIONHW, &val);
    Log(lDebug) <<"Result and value from USBConnectionRead:" << res<<", "<< val;
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


