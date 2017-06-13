#pragma hdrstop
#include "atNavitarMotor.h"
#include "atNavitarMotorControl.h"
#include "mtkLogger.h"
//---------------------------------------------------------------------------

using namespace mtk;

NavitarMotor::NavitarMotor(NavitarMotorControl& mc, int ID)
:
mMotorController(mc),
mMotorID(ID),
mHandle(0)
{
}

bool NavitarMotor::connect()
{
    Log(lDebug) <<"Connecting motor with ID: "<<mMotorID;

	mHandle = USBConnectionConnect(mMotorID, DEF_MOTOR_CONTROLLER);

    Log(lDebug) <<"Handle returned:" << mHandle;


    if(mHandle && USBConnectionEstablished(mHandle, DEF_MOTOR_CONTROLLER))
    {
        Log(lInfo) <<"Connection established to Navitar Motor controller with ID: "<<mMotorID;
        return true;
    }
    else
    {
        Log(lInfo) <<"Connection FAILED to Navitar Motor controller with ID: "<<mMotorID;
        return false;
    }
}

bool NavitarMotor::disConnect()
{
	Log(lInfo) << "Disconnecting motor with ID:" << mMotorID;
	if(mHandle)
	{
		USBConnectionDisconnect(mHandle);
    }

    mHandle = 0;
    return true;
}

void NavitarMotor::home()
{
	long temp = 0;
	if(mMotorID == 1)
    {
		mMotorController.write(REG_USER_LIMIT_1, temp);
    }
    else if(mMotorID == 2)
    {
		mMotorController.write(REG_USER_LIMIT_2, temp);
    }
    else
    {
    	Log(lError) << "No such motor. ID was: "<<mMotorID;
    }
}

void NavitarMotor::limit()
{
	long temp = 1;
	if(mMotorID == 1)
    {
		mMotorController.write(REG_USER_LIMIT_1, temp);
    }
    else if(mMotorID == 2)
    {
		mMotorController.write(REG_USER_LIMIT_2, temp);
    }
    else
    {
    	Log(lError) << "No such motor. ID was: "<<mMotorID;
    }
}


