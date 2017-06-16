#include <vcl.h>
#pragma hdrstop
#include "TNavitarPreset.h"
#include "atNavitarMotorControl.h"
#pragma package(smart_init)
#pragma link "TIntegerLabeledEdit"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------

TNavitarPreset *NavitarPreset;

//---------------------------------------------------------------------------
__fastcall TNavitarPreset::TNavitarPreset(TComponent* Owner)
	: TFrame(Owner)
{
}

void TNavitarPreset::populate(NavitarMotorController& c)
{
	mController = &c;
}


//---------------------------------------------------------------------------
void __fastcall TNavitarPreset::GoButtonClick(TObject *Sender)
{
	mController->setPreset(ZoomPos->getValue(), FocusPos->getValue());
}

