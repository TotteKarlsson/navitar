#include <vcl.h>
#pragma hdrstop
#include "TNavitarMotorFrame.h"
#include "atNavitarMotor.h"
#include "mtkLogger.h"
#include "mtkVCLUtils.h"
#pragma package(smart_init)
#pragma link "TIntegerLabeledEdit"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------

TNavitarMotorFrame *NavitarMotorFrame;

using namespace mtk;

//---------------------------------------------------------------------------
__fastcall TNavitarMotorFrame::TNavitarMotorFrame(TComponent* Owner)
	: TFrame(Owner),
    mMotor(NULL)
{
    enableDisableGroupBox(MotorGB, false);
}

//---------------------------------------------------------------------------
void TNavitarMotorFrame::populate(NavitarMotor& m)
{
	mMotor = &m;
	MotorGB->Caption = vclstr(mMotor->getLabel());
    enableDisableGroupBox(MotorGB, true);
}

void __fastcall TNavitarMotorFrame::FrameBtnClick(TObject *Sender)
{
	if(!mMotor)
    {
    	Log(lError) << "Motor is NULL in ButtonClick";
        return;
    }

	TButton* b = dynamic_cast<TButton*>(Sender);

    if (b == HomeBtn)
    {
    	Log(lError) << "Driving motor " <<mMotor->getLabel()<<" to Home";
    	mMotor->home();
    }
    else if (b == LimitBtn)
    {
    	Log(lInfo) << "Driving motor " <<mMotor->getLabel()<<" to Limit";
    	mMotor->limit();
    }
}


//---------------------------------------------------------------------------
void __fastcall TNavitarMotorFrame::MotorPositionTimerTimer(TObject *Sender)
{

	int pos = mMotor->getPosition();
	MotorPosition->setValue(pos);
}


