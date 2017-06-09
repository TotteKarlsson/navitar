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
mHandle(0)
{
}

//---------------------------------------------------------------------------
NavitarMotorControl::~NavitarMotorControl()
{
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
bool NavitarMotorControl::home()
{
	return false;
}

//        	case 2:	readOption = REG_SYS_VERSIONDATE; 		 break;
//        	case 3:	readOption = REG_SYS_VERSIONSW;          break;
//
//        }
//        int res = USBConnectionRead(mHandle, readOption, &val);
//        Log(lInfo) <<"Result from USBConnectionRead:" << res;
//        Log(lInfo) <<"Read result:" << val;
//    }

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
    else if(val == 0x4001)
    {
    	return "BrightLight Controller";
    }
}

//---------------------------------------------------------------------------
string NavitarMotorControl::getDriverSoftwareBuildDate()
{
	long val;
    int res = USBConnectionRead(mHandle, REG_SYS_VERSIONDATE, &val);
    Log(lDebug) <<"Result from USBConnectionRead:" << res;
    Log(lDebug) <<"Read result:" << val;

//	regValue = MyController.Read(Controller.regVersionDate);
//                        major = (int)(((uint)regValue & 0xff000000) >> 24);
//                        minor = (int)(((uint)regValue & 0xff0000) >> 16);
//                        rev = (int)(((uint)regValue & 0xff00) >> 8);
//                        bug = (int)((uint)regValue & 0xff);
//                        DateTime date = new DateTime(rev + 2000, major, minor);
//                        this.labelDateOfManufacture.Text = date.ToShortDateString();

	int major 	= (int) (((uint) val & 0xff000000) >> 24);
    int minor	= (int) (((uint) val & 0xff0000) >> 16);
    int rev 	= (int) (((uint) val & 0xff00) >> 8);
    int bug 	= (int) (( uint) val & 0xff);

    DateTime dt(rev + 2000, major, minor);

	return Poco::DateTimeFormatter::format(dt, "%n/%f/%Y");
}

//---------------------------------------------------------------------------
string NavitarMotorControl::getHardwareVersion()
{
	long val;
    int res = USBConnectionRead(mHandle, REG_SYS_VERSIONHW, &val);
    Log(lDebug) <<"Result from USBConnectionRead:" << res;
    Log(lDebug) <<"Read result:" << val;


	int major 	= (int) (((uint) val & 0xff000000) >> 24);
    int minor	= (int) (((uint) val & 0xff0000) >> 16);
    int rev 	= (int) (((uint) val & 0xff00) >> 8);
    int bug 	= (int) (( uint) val & 0xff);

	stringstream str;
    str<<major<<"."<<minor<<"."<<rev<<"."<<bug;
	return str.str();
}

//---------------------------------------------------------------------------
string NavitarMotorControl::getSoftwareVersion()
{
	long val;
    int res = USBConnectionRead(mHandle, REG_SYS_VERSIONSW, &val);
    Log(lDebug) <<"Result from USBConnectionRead:" << res;
    Log(lDebug) <<"Read result:" << val;

	int major 	= (int) (((uint) val & 0xff000000) >> 24);
    int minor	= (int) (((uint) val & 0xff0000) >> 16);
    int rev 	= (int) (((uint) val & 0xff00) >> 8);
    int bug 	= (int) (( uint) val & 0xff);

	stringstream str;
    str<<major<<"."<<minor<<"."<<rev<<"."<<bug;
	return str.str();
}


