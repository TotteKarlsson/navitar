#ifndef TNavatarPresetsFrameH
#define TNavatarPresetsFrameH
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------


class TPresetsFrame : public TFrame
{
    __published:
    private:

    public:
        __fastcall TPresetsFrame(TComponent* Owner);
};

extern PACKAGE TPresetsFrame *PresetsFrame;

#endif
