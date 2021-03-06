// encoding: UTF-8
/******************************************************************************
*                                                                             *
*                                                                             *
* Notepad3                                                                    *
*                                                                             *
* Dialogs.h                                                                   *
*   Definitions for Notepad3 dialog boxes                                     *
*   Based on code from Notepad2, (c) Florian Balmer 1996-2011                 *
*                                                                             *
*                                                  (c) Rizonesoft 2008-2020   *
*                                                    https://rizonesoft.com   *
*                                                                             *
*                                                                             *
*******************************************************************************/
#pragma once
#ifndef _NP3_DIALOGS_H_
#define _NP3_DIALOGS_H_

#include <math.h>
#include "TypeDefs.h"
#include "Scintilla.h"

INT_PTR DisplayCmdLineHelp(HWND hwnd);
bool GetDirectory(HWND hwndParent,int uiTitle,LPWSTR pszFolder,LPCWSTR pszBase,bool);
INT_PTR CALLBACK AboutDlgProc(HWND hwnd,UINT umsg,WPARAM wParam,LPARAM lParam);
INT_PTR RunDlg(HWND hwnd,LPCWSTR lpstrDefault);
bool OpenWithDlg(HWND hwnd,LPCWSTR lpstrFile);
bool FavoritesDlg(HWND hwnd,LPWSTR lpstrFile);
bool AddToFavDlg(HWND hwnd,LPCWSTR lpszName,LPCWSTR lpszTarget);
bool FileMRUDlg(HWND hwnd,LPWSTR lpstrFile);
bool ChangeNotifyDlg(HWND hwnd);
bool ColumnWrapDlg(HWND hwnd,UINT uidDlg,UINT * iNumber);
bool WordWrapSettingsDlg(HWND hwnd,UINT uidDlg,int * iNumber);
bool LongLineSettingsDlg(HWND hwnd,UINT uidDlg, LPWSTR pColList);
bool TabSettingsDlg(HWND hwnd,UINT uidDlg,int * iNumber);
bool SelectDefEncodingDlg(HWND hwnd, cpi_enc_t* pidREncoding);
bool SelectEncodingDlg(HWND hwnd, cpi_enc_t* pidREncoding);
bool RecodeDlg(HWND hwnd, cpi_enc_t* pidREncoding);
bool SelectDefLineEndingDlg(HWND hwnd,LPARAM piOption);
bool WarnLineEndingDlg(HWND hwnd, EditFileIOStatus* fioStatus);
bool WarnIndentationDlg(HWND hwnd, EditFileIOStatus* fioStatus);

bool GetMonitorInfoFromRect(const RECT* rc, MONITORINFO* hMonitorInfo);
void WinInfoToScreen(WININFO* pWinInfo);
WININFO GetMyWindowPlacement(HWND hwnd,MONITORINFO * hMonitorInfo);
void FitIntoMonitorGeometry(RECT* pRect, WININFO* pWinInfo, SCREEN_MODE mode);
WINDOWPLACEMENT WindowPlacementFromInfo(HWND hwnd, const WININFO* pWinInfo, SCREEN_MODE mode);

void DialogNewWindow(HWND hwnd, bool bSaveOnRunTools, LPCWSTR lpcwFilePath);
void DialogFileBrowse(HWND hwnd);
void DialogGrepWin(HWND hwnd, LPCWSTR searchPattern);
void DialogAdminExe(HWND hwnd,bool);

int  MessageBoxLng(HWND hwnd, UINT uType, UINT uidMsg, ...);
INT_PTR InfoBoxLng(UINT uType, LPCWSTR lpstrSetting, UINT uidMsg, ...);
DWORD MsgBoxLastError(LPCWSTR lpszMessage, DWORD dwErrID);
DWORD DbgMsgBoxLastError(LPCWSTR lpszMessage, DWORD dwErrID);

bool SetWindowTitle(HWND hwnd, UINT uIDAppName, bool bIsElevated, UINT uIDUntitled,
                    LPCWSTR lpszFile, int iFormat, bool bModified,
                    UINT uIDReadOnly, bool bReadOnly, LPCWSTR lpszExcerpt);
void SetAdditionalTitleInfo(LPCWSTR lpszAddTitleInfo);
void AppendAdditionalTitleInfo(LPCWSTR lpszAddTitleInfo);
void SetWindowTransparentMode(HWND hwnd, bool bTransparentMode, int iOpacityLevel);
POINT GetCenterOfDlgInParent(const RECT* rcDlg, const RECT* rcParent);
void CenterDlgInParent(HWND hDlg, HWND hDlgParent);
void GetDlgPos(HWND hDlg, LPINT xDlg, LPINT yDlg);
void SetDlgPos(HWND hDlg, int xDlg, int yDlg);
//void SnapToDefaultButton(HWND);

// resize dialog directions
typedef enum { RSZ_NONE = -1, RSZ_BOTH = 0, RSZ_ONLY_X = 1, RSZ_ONLY_Y = 2 } RSZ_DLG_DIR;

void ResizeDlg_Init(HWND hwnd, int cxFrame, int cyFrame, int nIdGrip, RSZ_DLG_DIR iDirection);
void ResizeDlg_Destroy(HWND hwnd, int* cxFrame, int* cyFrame);
void ResizeDlg_Size(HWND hwnd, LPARAM lParam, int* cx, int* cy);
void ResizeDlg_GetMinMaxInfo(HWND hwnd, LPARAM lParam);

#define MAX_RESIZEDLG_ATTR_COUNT	2
void ResizeDlg_SetAttr(HWND hwnd, int index, int value);
int ResizeDlg_GetAttr(HWND hwnd, int index);

void ResizeDlg_InitY2Ex(HWND hwnd, int cxFrame, int cyFrame, int nIdGrip, RSZ_DLG_DIR iDirection, int nCtlId1, int nCtlId2);
inline void ResizeDlg_InitY2(HWND hwnd, int cxFrame, int cyFrame, int nIdGrip, int nCtlId1, int nCtlId2) {
  ResizeDlg_InitY2Ex(hwnd, cxFrame, cyFrame, nIdGrip, RSZ_BOTH, nCtlId1, nCtlId2);
}
int ResizeDlg_CalcDeltaY2(HWND hwnd, int dy, int cy, int nCtlId1, int nCtlId2);
void ResizeDlgCtl(HWND hwndDlg, int nCtlId, int dx, int dy);
HDWP DeferCtlPos(HDWP hdwp, HWND hwndDlg, int nCtlId, int dx, int dy, UINT uFlags);


void MakeBitmapButton(HWND hwnd, int nCtlId, HINSTANCE hInstance, WORD uBmpId); 
void MakeColorPickButton(HWND hwnd, int nCtlId, HINSTANCE hInstance, COLORREF crColor);
void DeleteBitmapButton(HWND hwnd, int nCtlId);


#define StatusSetSimple(hwnd,b) SendMessage(hwnd,SB_SIMPLE,(WPARAM)b,0)
void StatusSetText(HWND hwnd, UINT nPart, LPCWSTR lpszText);
bool StatusSetTextID(HWND hwnd, UINT nPart, UINT uID);

int Toolbar_GetButtons(HANDLE hwnd, int cmdBase, LPWSTR lpszButtons, int cchButtons);
int Toolbar_SetButtons(HANDLE, int, LPCWSTR, void*, int);

// ----------------------------------------------------------------------------

DPI_T GetCurrentPPI(HWND hwnd);

inline int ScaleIntToDPI_X(HWND hwnd, int val) { DPI_T const dpi = Scintilla_GetCurrentDPI(hwnd); return MulDiv((val), dpi.x, USER_DEFAULT_SCREEN_DPI); }
inline int ScaleIntToDPI_Y(HWND hwnd, int val) { DPI_T const dpi = Scintilla_GetCurrentDPI(hwnd); return MulDiv((val), dpi.y, USER_DEFAULT_SCREEN_DPI); }

inline int ScaleFloatToDPI_X(HWND hwnd, float fVal) { DPI_T const dpi = Scintilla_GetCurrentDPI(hwnd); return (int)lroundf((fVal * dpi.x) / (float)USER_DEFAULT_SCREEN_DPI); }
inline int ScaleFloatToDPI_Y(HWND hwnd, float fVal) { DPI_T const dpi = Scintilla_GetCurrentDPI(hwnd); return (int)lroundf((fVal * dpi.y) / (float)USER_DEFAULT_SCREEN_DPI); }

inline int ScaleIntFontSizeWidth(HWND hwnd, int val) { 
  DPI_T const dpi = Scintilla_GetCurrentDPI(hwnd);
  DPI_T const ppi = GetCurrentPPI(hwnd);  
  return MulDiv((val), dpi.x, ppi.x); 
}

inline int ScaleIntFontSizeHeight(HWND hwnd, int val) { 
  DPI_T const dpi = Scintilla_GetCurrentDPI(hwnd);
  DPI_T const ppi = GetCurrentPPI(hwnd);  
  return MulDiv((val), dpi.y, ppi.y); 
}

inline int ScaleFloatFontSize(HWND hwnd, float fSize) { 
  DPI_T const dpi = Scintilla_GetCurrentDPI(hwnd);
  DPI_T const ppi = GetCurrentPPI(hwnd);
  return (int)lroundf((fSize * (float)dpi.y) / (float)ppi.y);
}

inline int ScaleFractionalFontSize(HWND hwnd, float fSize) { 
  DPI_T const dpi = Scintilla_GetCurrentDPI(hwnd);
  DPI_T const ppi = GetCurrentPPI(hwnd);
  return (int)lroundf((fSize * (float)dpi.y) / (float)ppi.y) * SC_FONT_SIZE_MULTIPLIER;
}

// ----------------------------------------------------------------------------

HBITMAP ConvertIconToBitmap(const HICON hIcon, const int cx, const int cy);
void SetUACIcon(const HMENU hMenu, const UINT nItem);
void UpdateWindowLayoutForDPI(HWND hWnd, int x_96dpi, int y_96dpi, int w_96dpi, int h_96dpi);
HBITMAP ResizeImageForCurrentDPI(HWND hwnd, HBITMAP hbmp);
LRESULT SendWMSize(HWND hwnd, RECT* rc);

// ----------------------------------------------------------------------------

inline void SimpleBeep() { if (!Settings.MuteMessageBeep) { MessageBeep(0xFFFFFFFF); } }
inline void AttentionBeep(UINT uType) { if (!Settings.MuteMessageBeep) { MessageBeep(uType & MB_ICONMASK); } }

#define DialogEnableControl(hdlg, id, b) { HWND hctrl = GetDlgItem((hdlg),(id)); if (!(b)) { \
  if (GetFocus() == hctrl) { SendMessage((hdlg), WM_NEXTDLGCTL, 0, false); } }; EnableWindow(hctrl, (b)); }

#define DialogHideControl(hdlg, id, b) { HWND hctrl = GetDlgItem((hdlg),(id)); if (!(b)) { \
  if (GetFocus() == hctrl) { SendMessage((hdlg), WM_NEXTDLGCTL, 0, false); } }; ShowWindow(hctrl, (b)?SW_HIDE:SW_SHOW); }

inline bool IsDialogItemEnabled(HWND hdlg, int id) { return IsWindowEnabled(GetDlgItem(hdlg, id)); }

// --- Themed Dialogs ---------------------------------------------------------

#ifndef DLGTEMPLATEEX
#pragma pack(push, 1)
typedef struct {
  WORD      dlgVer;
  WORD      signature;
  DWORD     helpID;
  DWORD     exStyle;
  DWORD     style;
  WORD      cDlgItems;
  short     x;
  short     y;
  short     cx;
  short     cy;
} DLGTEMPLATEEX;
#pragma pack(pop)
#endif

bool GetThemedDialogFont(LPWSTR lpFaceName, WORD* wSize);
DLGTEMPLATE* LoadThemedDialogTemplate(LPCTSTR lpDialogTemplateID, HINSTANCE hInstance);
#define ThemedDialogBox(hInstance,lpTemplate,hWndParent,lpDialogFunc) ThemedDialogBoxParam(hInstance,lpTemplate,hWndParent,lpDialogFunc,0)
INT_PTR ThemedDialogBoxParam(HINSTANCE hInstance, LPCTSTR lpTemplate, HWND hWndParent, DLGPROC lpDialogFunc, LPARAM dwInitParam);
HWND    CreateThemedDialogParam(HINSTANCE hInstance, LPCTSTR lpTemplate, HWND hWndParent, DLGPROC lpDialogFunc, LPARAM dwInitParam);

// ----------------------------------------------------------------------------

#endif //_NP3_DIALOGS_H_
