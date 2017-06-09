#ifndef atNavitarMotorH
#define atNavitarMotorH
#include "atATObject.h"
//---------------------------------------------------------------------------

class NavitarMotorControl;
class NavitarMotor //://: public ATObject
{
	public:
								NavitarMotor(NavitarMotorControl& parent, int motorID);
		void					home();
		void					limit();


    protected:
		NavitarMotorControl& 	mMotorController;
        int						mMotorID;
};

#endif
