#pragma hdrstop
#include "atNavitarMotor.h"
#include "atNavitarMotorControl.h"
#include "mtkLogger.h"
//---------------------------------------------------------------------------

using namespace mtk;




NavitarMotor::NavitarMotor(NavitarMotorControl& mc, int ID)
:
mMotorController(mc),
mMotorID(ID)
{

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


