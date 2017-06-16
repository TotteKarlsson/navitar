#include <vcl.h>
#pragma hdrstop
#include "TNavatarPresetsFrame.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPresetsFrame *PresetsFrame;

//---------------------------------------------------------------------------
__fastcall TPresetsFrame::TPresetsFrame(TComponent* Owner)
	: TFrame(Owner)
{
}

