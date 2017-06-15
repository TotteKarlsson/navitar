#ifndef atNavitarMotorH
#define atNavitarMotorH
#include "atATObject.h"
//---------------------------------------------------------------------------

class NavitarMotorControl;
class NavitarMotor //://: public ATObject
{
	public:
								NavitarMotor(NavitarMotorControl& parent, int motorID);

        						//!Drive motor to home
		void					home();

        						//!Drive motor to the limit
		void					limit();

        						//!Connect to a motor
		bool					connect();

        						//!Connect to a motor
		bool					disConnect();
 //       int						getHandle(){return mHandle;}

    protected:
		NavitarMotorControl& 	mMotorController;
        int						mMotorID;

        						//!the handle is returned when connecting and used for API calls
                                //!using this motor
//        int						mHandle;

};

#endif
