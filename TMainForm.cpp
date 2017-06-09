#include <vcl.h>
#pragma hdrstop
#include "mtkUtils.h"
#include "mtkVCLUtils.h"
#include "TMainForm.h"
#include "mtkLogger.h"
#include "navitar/navserAPI.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TIntegerLabeledEdit"
#pragma resource "*.dfm"
TForm1 *Form1;

extern string gLogFileName;
extern string gApplicationRegistryRoot;
extern string gLogFileLocation;
extern string gLogFileName;
extern string gAppDataFolder;
extern bool   gAppIsStartingUp;

using namespace mtk;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner),
    mLogFileReader(gLogFileName, &logMsg),
    mHandle(0)

{
   	mLogFileReader.start(true);
}

//This one is called from the reader thread
void __fastcall TForm1::logMsg()
{
    mInfoMemo->Lines->Insert(0, (vclstr(mLogFileReader.getData())));
    mLogFileReader.purge();
}

//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if(Key == vkEscape)
    {
    	Close();
    }
}

//---------------------------------------------------------------------------
void __fastcall TForm1::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	if(mLogFileReader.isRunning())
    {
        CanClose = false;
        mShutDownTimer->Enabled = true;
        return;
    }

    CanClose = true;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::mShutDownTimerTimer(TObject *Sender)
{
    mShutDownTimer->Enabled = false;
	if(mLogFileReader.isRunning())
    {
		mLogFileReader.stop();
    }

    Close();
}

//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonClick(TObject *Sender)
{

	TButton* b = dynamic_cast<TButton*>(Sender);

    if(b == FindConnectedDevicesBtn)
    {
        //Check for connected devices
//        int res = SerUSBFindUSBinterfaces();
//        Log(lInfo) <<"Result from USBFindUSBinterfaces:" << res;
    }
    else if(b == ConnectBtn)
    {
        mHandle = SerConnectionConnect(1, DEF_MOTOR_CONTROLLER);
        Log(lInfo) <<"Result from USBConnectionConnect:" << mHandle;
        Log(lInfo) <<"Handle is:" << mHandle;
    }
    else if(b == ReadBtn)
    {
    	long val = 0;
        int res = SerConnectionRead(mHandle, REG_SYS_PRODUCTID, &val);
        Log(lInfo) <<"Result from USBConnectionRead:" << res;
        Log(lInfo) <<"Read result:" << val;
    }
    else if(b == ConnectionEstablishedBtn)
    {
//        int res = USBConnectionEstablished(mHandle, DEF_MOTOR_CONTROLLER);
//        Log(lInfo) <<"Result from USBConnectionEstablished:" << res;
    }


}


