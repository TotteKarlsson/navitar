#ifndef TNavitarMotorFrameH
#define TNavitarMotorFrameH
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "TIntegerLabeledEdit.h"
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
class NavitarMotor;

class TNavitarMotorFrame : public TFrame
{
    __published:
	TGroupBox *MotorGB;
        TButton *HomeZoomBtn;
        TButton *LimitBtn;
        TIntegerLabeledEdit *CurrentPosition;
        TTrackBar *TrackBar1;
        TTimer *MotorPositionTimer;
	void __fastcall ButtonClick(TObject *Sender);
    private:
		NavitarMotor*			mMotor;

    public:
        						__fastcall TNavitarMotorFrame(TComponent* Owner);
		void					populate(NavitarMotor& m);
};


extern PACKAGE TNavitarMotorFrame *NavitarMotorFrame;
#endif
