#pragma hdrstop
#include "atNavitarMotor.h"
#include "atNavitarMotorControl.h"
#include "mtkLogger.h"
//---------------------------------------------------------------------------

using namespace mtk;

NavitarMotor::NavitarMotor(NavitarMotorControl& mc, int ID)
:
mMotorController(mc),
mID(ID),
mLabel(ID == 1 ? "Focus" : "Zoom")
{}


string NavitarMotor::getLabel()
{
	return mLabel;
}

void NavitarMotor::home()
{
	long temp = 0;
	if(mID == 1)
    {
		mMotorController.write(REG_USER_LIMIT_1, temp);
    }
    else if(mID == 2)
    {
		mMotorController.write(REG_USER_LIMIT_2, temp);
    }
    else
    {
    	Log(lError) << "No such motor. ID was: "<<mID;
    }
}

void NavitarMotor::limit()
{
	long temp = 1;
	if(mID == 1)
    {
		mMotorController.write(REG_USER_LIMIT_1, temp);
    }
    else if(mID == 2)
    {
		mMotorController.write(REG_USER_LIMIT_2, temp);
    }
    else
    {
    	Log(lError) << "No such motor. ID was: "<<mID;
    }
}

int	NavitarMotor::getPosition()
{
	long pos;
	if(mID == 1)
    {
		mMotorController.read(REG_USER_CURRENT_1, pos);
    }
    else if(mID == 2)
    {
		mMotorController.read(REG_USER_CURRENT_2, pos);
    }
    else
    {
    	Log(lError) << "No such motor. ID was: "<<mID;
        return -1;
    }

    return pos;
}


