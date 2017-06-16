#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>
#include <string>
#include "mtkUtils.h"
#include "mtkVCLUtils.h"
#include "mtkWin32Utils.h"
#include "mtkLogger.h"
//---------------------------------------------------------------------------
USEFORM("frames\TNavatarPresetsFrame.cpp", PresetsFrame); /* TFrame: File Type */
USEFORM("frames\TNavitarMotorFrame.cpp", NavitarMotorFrame); /* TFrame: File Type */
USEFORM("TMainForm.cpp", MainForm);
USEFORM("frames\TNavitarPreset.cpp", NavitarPreset); /* TFrame: File Type */
//---------------------------------------------------------------------------
using std::string;
using namespace mtk;

string      gLogFileName                = "atNavitar.log";
string		gAppName					= "atNavitar";
string		gAppDataFolder 				= joinPath(getSpecialFolder(CSIDL_LOCAL_APPDATA), gAppName);;
void setupLogging();

int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		setupLogging();
		TStyleManager::TrySetStyle("Iceberg Classico");
		Application->CreateForm(__classid(TMainForm), &MainForm);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------

void setupLogging()
{
	//Get Application folder
	string fldr =  gAppDataFolder;
	if(!folderExists(fldr))
	{
		createFolder(fldr);
	}

	string fullLogFileName(joinPath(fldr, gLogFileName));
	clearFile(fullLogFileName);
	mtk::gLogger.logToFile(fullLogFileName);
    mtk::gLogger.setLogLevel(lDebug5);
	LogOutput::mShowLogLevel = true;
	LogOutput::mShowLogTime = true;
	LogOutput::mUseLogTabs 	= true;
	Log(lInfo) << "Logger was setup";
}

//---------------------------------------------------------------------------
#if defined DSL_STATIC
	#pragma comment(lib, "mtkCommon-static.lib")
	#pragma comment(lib, "mtkMath-static.lib")
	#pragma comment(lib, "mtkIPC-static.lib")
#else
	#pragma comment(lib, "mtkCommon.lib")
	#pragma comment(lib, "mtkMath.lib")
	#pragma comment(lib, "mtkIPC.lib")
#endif

//#pragma comment(lib, "atCore.lib")
//#pragma comment(lib, "atResources.lib")
#pragma comment(lib, "poco_foundation-static.lib")
#pragma comment(lib, "navusbAPI_B1.lib")


#pragma comment(lib, "VCLCommon.bpi")
#pragma comment(lib, "DuneForms.bpi")

