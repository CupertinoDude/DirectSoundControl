//////////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2003-2007, Arne Bockholdt, github@bockholdt.info
//
// This file is part of Direct Sound Control.
//
// Direct Sound Control is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Direct Sound Control is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Direct Sound Control.  If not, see <http://www.gnu.org/licenses/>.
//
//////////////////////////////////////////////////////////////////////////////////////////////
//
// DSoundCtrl.h : main header file for the DSoundCtrl DLL
//
//////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

//////////////////////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus

extern "C" {  // only need to export C interface if
              // used by C++ source code
#endif

//////////////////////////////////////////////////////////////////////////////////////////////

DirectSoundCreate8func				g_pDirectSoundCreate8 = NULL;
DirectSoundCreatefunc				g_pDirectSoundCreate = NULL;
GetDeviceIDfunc						g_pGetDeviceIDfunc = NULL;
DirectSoundEnumerateAfunc			g_pDirectSoundEnumerateAfunc = NULL;
DirectSoundEnumerateWfunc			g_pDirectSoundEnumerateWfunc = NULL;
DirectSoundCaptureCreatefunc		g_pDirectSoundCaptureCreatefunc = NULL;
DirectSoundCaptureEnumerateAfunc	g_pDirectSoundCaptureEnumerateAfunc = NULL;
DirectSoundCaptureEnumerateWfunc	g_pDirectSoundCaptureEnumerateWfunc = NULL;
DirectSoundCaptureCreate8func		g_pDirectSoundCaptureCreate8func = NULL;
DirectSoundFullDuplexCreatefunc		g_pDirectSoundFullDuplexCreatefunc = NULL;
DllGetClassObjectfunc				g_pDllGetClassObjectfunc = NULL;
DllCanUnloadNowfunc					g_pDllCanUnloadNowfunc = NULL;

//////////////////////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif

#include "IDirectSoundEx.h"
#include "IDirectSoundBufferEx.h"

//////////////////////////////////////////////////////////////////////////////////////////////

#define CDSOUNDCTRLAPP_CLASS_NAME	"CDSoundCtrlApp"

//////////////////////////////////////////////////////////////////////////////////////////////

#ifdef ENABLE_LOG
extern void LogMessage(const char* szClassName, void* pInstance, char* szMessage );
#endif //ENABLE_LOG

//////////////////////////////////////////////////////////////////////////////////////////////

HMODULE			g_hDLL					=	NULL;

//////////////////////////////////////////////////////////////////////////////////////////////

int				g_nNum2DBuffers					=	0;
int				g_nNum3DBuffers					=	0;
bool			g_bForceCertification			=	false;
bool			g_bForceSoftwareMixing			=	false;
bool			g_bForceHardwareMixing			=	false;
bool			g_bPreventSpeakerSetup			=	false;
bool			g_bForceExclusiveMode			=	false;
bool			g_bForceHQSoftware3D			=	false;
bool			g_bForceNonStatic				=	false;
bool			g_bForceVoiceManagement			=	false;
bool			g_bForcePrimaryBufferFormat		=	false;
int				g_nPrimaryBufferBits			=	16;
int				g_nPrimaryBufferSamples			=	44100;
int				g_nPrimaryBufferChannels		=	2;

bool			g_bForceSpeakerConfig			=	false;
int				g_nSpeakerConfig				=	DSSPEAKER_5POINT1;

bool			g_bStoppedDriverWorkaround		=	false;

#ifdef ENABLE_LOG
DWORD			g_dwStartTime					=	0;
bool			g_bLogSystem					=	true;
bool			g_bLogDirectSound				=	true;
bool			g_bLogDirectSoundBuffer			=	true;
bool			g_bLogDirectSound3DBuffer		=	true;
bool			g_bLogDirectSound3DListener		=	true;
bool			g_bDebugBeep					=	true;
#endif // ENABLE_LOG

//////////////////////////////////////////////////////////////////////////////////////////////

// CDSoundCtrlApp
// See DSoundCtrl.cpp for the implementation of this class
//

class CDSoundCtrlApp : public CWinApp
{
public:
	CDSoundCtrlApp();
	virtual ~CDSoundCtrlApp();

// Overrides
public:
	virtual BOOL InitInstance();

#ifdef ENABLE_LOG
	bool EnumCallback( LPGUID  lpGuid,    LPCSTR  lpcstrDescription,  LPCSTR  lpcstrModule );
#endif // ENABLE_LOG

	DECLARE_MESSAGE_MAP()
	// Reads a configuration value from INI File
	int ReadConfig(char* szSection, char* szKey, int nDefault);
	
	// Writes a configuration value to INI File
	int WriteConfig(char* szSection, char* szKey, int nVal);

protected : 
#ifdef ENABLE_LOG
	const char* m_cszClassName;
#endif // ENABLE_LOG
};

//////////////////////////////////////////////////////////////////////////////////////////////
