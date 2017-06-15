#ifndef atNavitarMotorControlH
#define atNavitarMotorControlH
#include "navitar/navusbAPI.h"
#include <string>
//#include "atATObject.h"
#include "atNavitarMotor.h"
//---------------------------------------------------------------------------

using std::string;
//!The NavitarMotorControl class is a Wrapper class for the Navitar USB motor controller API
class NavitarMotorControl //: public ATObject
{
   	friend NavitarMotor;
	public:

							            NavitarMotorControl();
							            ~NavitarMotorControl();
		bool				            connect();
        bool				            disConnect();
        bool				            isConnected();

		bool				            home();

        NavitarMotor&                   getZoom();
        NavitarMotor&                   getFocus();
		string				            getProductID();
		string				            getDriverSoftwareBuildDate();
        string                          getHardwareVersion();
        string                          getSoftwareVersion();
        int								getHandle(){return mHandle;}

	protected:
    	int					            mHandle;
        NavitarMotor		            mZoom;
		NavitarMotor		            mFocus;

 		string 				            parseVersion(long val);
 		string 				            parseDate(long val);
        int								write(const int& reg, long value);

};


#endif
