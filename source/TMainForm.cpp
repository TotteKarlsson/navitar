#include <vcl.h>
#pragma hdrstop
#include "mtkUtils.h"
#include "mtkVCLUtils.h"
#include "TMainForm.h"
#include "mtkLogger.h"
#include "navitar/navusbAPI.h"
#include "mtkVCLUtils.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TIntegerLabeledEdit"
#pragma link "TNavitarMotorFrame"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------

TMainForm *MainForm;

extern string gLogFileName;
extern string gApplicationRegistryRoot;
extern string gLogFileLocation;
extern string gLogFileName;
extern string gAppDataFolder;
extern bool   gAppIsStartingUp;

using namespace mtk;

//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner),
    mLogFileReader(joinPath(getSpecialFolder(CSIDL_LOCAL_APPDATA), "atNavitar", gLogFileName), &logMsg)
{
   	mLogFileReader.start(true);
}

//This one is called from the reader thread
void __fastcall TMainForm::logMsg()
{
    mInfoMemo->Lines->Insert(0, (vclstr(mLogFileReader.getData())));
    mLogFileReader.purge();
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if(Key == vkEscape)
    {
    	Close();
    }
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::FormCloseQuery(TObject *Sender, bool &CanClose)
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
void __fastcall TMainForm::mShutDownTimerTimer(TObject *Sender)
{
    mShutDownTimer->Enabled = false;
	if(mLogFileReader.isRunning())
    {
		mLogFileReader.stop();
    }

    Close();
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::ButtonClick(TObject *Sender)
{
	TButton* b = dynamic_cast<TButton*>(Sender);

    if(b == ConnectBtn)
    {
        if(!mNavitar.isConnected())
        {
            if(mNavitar.connect())
            {
            	onNavitarConnected();
            }
        }
        else
        {
            if(mNavitar.disConnect())
            {
            	onNavitarDisconnected();
            }
        }
    }
}

void  TMainForm::onNavitarConnected()
{
	ConnectBtn->Caption         = "Disconnect";
    ProdIdLbl->Caption 	        = vclstr(mNavitar.getProductID());
	HWVerLbl->Caption           = vclstr(mNavitar.getHardwareVersion());
   	SWVerLbl->Caption           = vclstr(mNavitar.getSoftwareVersion());
    FirmWareDateLbl->Caption   	= vclstr(mNavitar.getDriverSoftwareBuildDate());

    TNavitarMotorFrame1->populate(mNavitar.getZoom());
    TNavitarMotorFrame2->populate(mNavitar.getFocus());

    enableDisableGroupBox(ControllerInfoGB, true);

}

void  TMainForm::onNavitarDisconnected()
{
	ConnectBtn->Caption = "Connect";
    ProdIdLbl->Caption 	        = "N/A";
	HWVerLbl->Caption           = "N/A";
   	SWVerLbl->Caption           = "N/A";
    FirmWareDateLbl->Caption   	= "N/A";

    enableDisableGroupBox(ControllerInfoGB, false);

    TNavitarMotorFrame1->dePopulate();
    TNavitarMotorFrame2->dePopulate();
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::FormCreate(TObject *Sender)
{
    enableDisableGroupBox(ControllerInfoGB, false);
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::Button1Click(TObject *Sender)
{
	mInfoMemo->Clear();
}




