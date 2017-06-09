#ifndef atNavitarMotorControlH
#define atNavitarMotorControlH
#include "navitar/navusbAPI.h"
#include "atATObject.h"
//---------------------------------------------------------------------------

//!The NavitarMotorControl class is a Wrapper class for the Navitar USB motor controller API
class AT_CORE NavitarMotorControl //: public ATObject
{
	public:
							NavitarMotorControl();
							~NavitarMotorControl();
		bool				connect();
        bool				disConnect();
        bool				isConnected();

		bool				home();


		string				getProductID();
		string				getDriverSoftwareBuildDate();
        string              getHardwareVersion();
        string              getSoftwareVersion();

	private:
    	int					mHandle;

};


#endif
