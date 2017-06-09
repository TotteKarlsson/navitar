#ifndef TMainFormH
#define TMainFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "mtkLogFileReader.h"
#include "TIntegerLabeledEdit.h"
#include "atNavitarMotorControl.h"
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------

class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TMemo *mInfoMemo;
	TTimer *mShutDownTimer;
	TButton *ConnectBtn;
	TGroupBox *Zoom;
	TButton *HomeZoomBtn;
	TButton *Button4;
	TIntegerLabeledEdit *CurrentPosition;
	TPanel *TopPanel;
	TSplitter *Splitter1;
	TGroupBox *ControllerInfoGB;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *ProdIdLbl;
	TLabel *HWVerLbl;
	TLabel *SWVerLbl;
	TLabel *FirmWareDateLbl;
	TButton *Button1;
	TPanel *BottomPanel;
	TPanel *InfoPanel;
	TSplitter *Splitter2;
	TTrackBar *TrackBar1;
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall mShutDownTimerTimer(TObject *Sender);
	void __fastcall ButtonClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);

private:	// User declarations
        LogFileReader                           mLogFileReader;
        void __fastcall                         logMsg();
        NavitarMotorControl						mNavitar;
        void									onNavitarConnected();
        void									onNavitarDisconnected();

public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);
};

extern PACKAGE TMainForm *MainForm;
#endif
