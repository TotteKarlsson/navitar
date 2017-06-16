#ifndef TMainFormH
#define TMainFormH
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
#include "TNavitarMotorFrame.h"
#include "TNavatarPresetsFrame.h"
//---------------------------------------------------------------------------

class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TMemo *mInfoMemo;
	TTimer *mShutDownTimer;
	TPanel *TopPanel;
	TSplitter *Splitter1;
	TButton *Button1;
	TPanel *BottomPanel;
	TPanel *InfoPanel;
	TSplitter *Splitter2;
	TNavitarMotorFrame *TNavitarMotorFrame1;
	TNavitarMotorFrame *TNavitarMotorFrame2;
	TPresetsFrame *TPresetsFrame1;
	TGroupBox *LeftPanel;
	TButton *ConnectBtn;
	TGroupBox *ControllerInfoGB;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *ProdIdLbl;
	TLabel *HWVerLbl;
	TLabel *SWVerLbl;
	TLabel *FirmWareDateLbl;
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
