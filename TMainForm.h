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
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TMemo *mInfoMemo;
	TTimer *mShutDownTimer;
	TButton *FindConnectedDevicesBtn;
	TButton *ConnectBtn;
	TIntegerLabeledEdit *ProductID;
	TIntegerLabeledEdit *DeviceID;
	TGroupBox *GroupBox1;
	TGroupBox *Zoom;
	TButton *Button3;
	TButton *Button4;
	TIntegerLabeledEdit *CurrentPosition;
	TPanel *TopPanel;
	TSplitter *Splitter1;
	TButton *ReadBtn;
	TButton *ConnectionEstablishedBtn;
	TRadioGroup *ReadOptions;
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall mShutDownTimerTimer(TObject *Sender);
	void __fastcall ButtonClick(TObject *Sender);

private:	// User declarations
        LogFileReader                           mLogFileReader;
        void __fastcall                         logMsg();
		int										mHandle;

public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};

extern PACKAGE TForm1 *Form1;
#endif
