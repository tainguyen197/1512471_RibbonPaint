﻿// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved.
#include "Paint_Plus_1.h"
#include "stdafx.h"
#include <string>
#include <UIRibbon.h>
#include "CommandHandler.h"
#include "RibbonIDs.h"
#include "RibbonFramework.h"
#include <windows.h>
#include <Commdlg.h>
using namespace std;

// Static method to create an instance of the object.
HRESULT CCommandHandler::CreateInstance(IUICommandHandler **ppCommandHandler)
{
	if (!ppCommandHandler)
	{
		return E_POINTER;
	}

	*ppCommandHandler = NULL;

	HRESULT hr = S_OK;

	CCommandHandler* pCommandHandler = new CCommandHandler();

	if (pCommandHandler != NULL)
	{
		*ppCommandHandler = static_cast<IUICommandHandler *>(pCommandHandler);
	}
	else
	{
		hr = E_OUTOFMEMORY;
	}

	return hr;
}

// IUnknown method implementations.
STDMETHODIMP_(ULONG) CCommandHandler::AddRef()
{
	return InterlockedIncrement(&m_cRef);
}

STDMETHODIMP_(ULONG) CCommandHandler::Release()
{
	LONG cRef = InterlockedDecrement(&m_cRef);
	if (cRef == 0)
	{
		delete this;
	}

	return cRef;
}

STDMETHODIMP CCommandHandler::QueryInterface(REFIID iid, void** ppv)
{
	if (iid == __uuidof(IUnknown))
	{
		*ppv = static_cast<IUnknown*>(this);
	}
	else if (iid == __uuidof(IUICommandHandler))
	{
		*ppv = static_cast<IUICommandHandler*>(this);
	}
	else
	{
		*ppv = NULL;
		return E_NOINTERFACE;
	}

	AddRef();
	return S_OK;
}

//
//  FUNCTION: UpdateProperty()
//
//  PURPOSE: Called by the Ribbon framework when a command property (PKEY) needs to be updated.
//
//  COMMENTS:
//
//    This function is used to provide new command property values, such as labels, icons, or
//    tooltip information, when requested by the Ribbon framework.  
//    
//    In this SimpleRibbon sample, the method is not implemented.  
//
STDMETHODIMP CCommandHandler::UpdateProperty(
	UINT nCmdID,
	REFPROPERTYKEY key,
	const PROPVARIANT* ppropvarCurrentValue,
	PROPVARIANT* ppropvarNewValue)
{
	UNREFERENCED_PARAMETER(nCmdID);
	UNREFERENCED_PARAMETER(key);
	UNREFERENCED_PARAMETER(ppropvarCurrentValue);
	UNREFERENCED_PARAMETER(ppropvarNewValue);

	return E_NOTIMPL;
}

//
//  FUNCTION: Execute()
//
//  PURPOSE: Called by the Ribbon framework when a command is executed by the user.  For example, when
//           a button is pressed.
//
int shape;
bool clrscr;
string s;
WCHAR f[256];
STDMETHODIMP CCommandHandler::Execute(
	UINT nCmdID,
	UI_EXECUTIONVERB verb,
	const PROPERTYKEY* key,
	const PROPVARIANT* ppropvarValue,
	IUISimplePropertySet* pCommandExecutionProperties)
{
	if (nCmdID == ID_BTN_LINE)
		shape = 0;
	if (nCmdID == ID_BTN_RECTANGLE)
		shape = 1;
	if (nCmdID == ID_BTN_ELLIPSE)
		shape = 2;
	if (nCmdID == ID_BTN_OPEN){
	}
	if (nCmdID == ID_BTN_SAVE)
	return S_OK;
}

