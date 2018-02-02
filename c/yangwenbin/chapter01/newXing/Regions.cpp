// Regions.cpp : Defines the entry point for the application.
// Download by http://www.NewXing.com

#include "stdafx.h"
#include "resource.h"
#include	<math.h>

#define MAX_LOADSTRING 100
#define	PI		3.14159
#define	TEXT_FORMAT		(DT_SINGLELINE|DT_VCENTER|DT_CENTER)

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];								// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];								// The title bar text

// Foward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

void DoRectRegion (HWND hWnd, HDC hdc, bool bInvert = false);
void DoRoundRectRegion (HWND hWnd, HDC hdc, bool bInvert = false);
void DoCircleRegion (HWND hWnd, HDC hdc, bool bInvert = false);
void DoEllipseRegion (HWND hWnd, HDC hdc, bool bInvert = false);
void DoPolyRegion (HWND hWnd, HDC hdc, bool bStar = false, bool bInvert = false);
void DoCloverRegion (HWND hWnd, HDC hdc, bool bInvert = false);
void DrawRadials (HDC hdc, HRGN hRgn, RECT & rc, int nShadow = 4, int nStep = 1);
void DoMappingModes (HWND hWnd, HDC hdc);
void DrawRect (HDC hdc, int x, int y, int width, int depth);
void DoRectanglePath (HWND hWnd, HDC hdc);
void DoTextPath (HWND hWnd, HDC hdc);
void CreateLogFont (HDC hdc, LOGFONT & lf, int nPoints = 10, char *szFace = "Times New Roman Bold");
void DoMouseEvent (HWND hWnd, UINT message, UINT nFlags, POINT & point);
void DoMouseLine (HDC hdc, POINT & ptLineStart, POINT & ptLineEnd);

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_REGIONS, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow)) 
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_REGIONS);

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0)) 
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) 
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage is only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX); 

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, (LPCTSTR)IDI_REGIONS);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= (LPCSTR)IDC_REGIONS;
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SMALL);

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HANDLE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, unsigned, WORD, LONG)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
static int nMode = IDM_REGION_CLEAR;
int wmId, wmEvent;
PAINTSTRUCT ps;
HDC hdc;
static bool	bInvert = false;

	switch (message) 
	{
		case WM_COMMAND:
			wmId    = LOWORD(wParam); 
			wmEvent = HIWORD(wParam);
			
			// Parse the menu selections:
			switch (wmId)
			{
				case IDM_ABOUT:
				   DialogBox(hInst, (LPCTSTR)IDD_ABOUTBOX, hWnd, (DLGPROC)About);
				   break;
				case IDM_EXIT:
				   DestroyWindow(hWnd);
				   break;
				case IDM_REGION_INVERT:
					bInvert = bInvert ? false : true;
					RECT rc;
					GetClientRect(hWnd, &rc);
					InvalidateRect (hWnd, &rc, TRUE);
					break;
				case IDM_REGION_ELLIPSE:
				case IDM_REGION_CLEAR:
				case IDM_REGION_RECT:
				case IDM_REGION_ROUNDRECT:
				case IDM_REGION_CIRCLE:
				case IDM_REGION_POLY:
				case IDM_REGION_STAR:
				case IDM_REGION_CLOVER:
				case IDM_MAPPING_MODES:
				case IDM_PATHS_RECTANGLE:
				case IDM_PATHS_TEXT:
					bInvert = false;
					nMode = wmId;
					GetClientRect(hWnd, &rc);
//					rc.right /= 2;
					InvalidateRect (hWnd, &rc, TRUE);
					break;
				default:
				   return DefWindowProc(hWnd, message, wParam, lParam);
			}
			break;
		case WM_LBUTTONDOWN:
		case WM_LBUTTONUP:
		case WM_MOUSEMOVE:
			POINT point;
			point.x = LOWORD(lParam);
			point.y = HIWORD(lParam);
			DoMouseEvent (hWnd, message, wParam, point);
			break;
		case WM_SIZE:
			break;
		case WM_CREATE:
			break;
		case WM_PAINT:
			hdc = BeginPaint(hWnd, &ps);
			switch (nMode)
			{
				default:
				case IDM_REGION_CLEAR:		//	Clear screen
					break;
				case IDM_REGION_RECT:
					DoRectRegion (hWnd, hdc, bInvert);
					break;
				case IDM_REGION_ROUNDRECT:
					DoRoundRectRegion (hWnd, hdc, bInvert);
					break;
				case IDM_REGION_CIRCLE:
					DoCircleRegion (hWnd, hdc, bInvert);
					break;
				case IDM_REGION_ELLIPSE:
					DoEllipseRegion (hWnd, hdc, bInvert);
					break;
				case IDM_REGION_POLY:
					DoPolyRegion (hWnd, hdc, false, bInvert);
					break;
				case IDM_REGION_STAR:
					DoPolyRegion (hWnd, hdc, true, bInvert);
					break;
				case IDM_REGION_CLOVER:
					DoCloverRegion (hWnd, hdc, bInvert);
					break;
				case IDM_MAPPING_MODES:
					DoMappingModes (hWnd, hdc);
					break;
				case IDM_PATHS_RECTANGLE:
					DoRectanglePath (hWnd, hdc);
					break;
				case IDM_PATHS_TEXT:
					DoTextPath (hWnd, hdc);
					break;
			}

			// TODO: Add any drawing code here...
			EndPaint(hWnd, &ps);
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
   }
   return 0;
}

// Mesage handler for about box.
LRESULT CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_INITDIALOG:
				return TRUE;

		case WM_COMMAND:
			if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) 
			{
				EndDialog(hDlg, LOWORD(wParam));
				return TRUE;
			}
			break;
	}
    return FALSE;
}


void DoRectRegion (HWND hWnd, HDC hdc, bool bInvert)
{
RECT	rcRegion, rcClient;
HRGN	hRgn;

	GetClientRect (hWnd, &rcClient);
	rcRegion.top = rcClient.bottom / 4;
	rcRegion.bottom = rcRegion.top * 3;
	rcRegion.left = rcClient.right / 4;
	rcRegion.right = rcRegion.left * 3;
	hRgn = CreateRectRgnIndirect (&rcRegion);

	DrawRadials (hdc, hRgn, rcClient);
	if (bInvert)
		InvertRgn (hdc, hRgn);
	DeleteObject (hRgn);
}

void DoRoundRectRegion (HWND hWnd, HDC hdc, bool bInvert)
{
RECT	rcRegion, rcClient;
HRGN	hRgn;

	GetClientRect (hWnd, &rcClient);
	rcRegion.top = rcClient.bottom / 4;
	rcRegion.bottom = rcRegion.top * 3;
	rcRegion.left = rcClient.right / 4;
	rcRegion.right = rcRegion.left * 3;
	hRgn = CreateRoundRectRgn (rcRegion.left, rcRegion.top,
							   rcRegion.right, rcRegion.bottom, 10, 10);

	DrawRadials (hdc, hRgn, rcClient);
	if (bInvert)
		InvertRgn (hdc, hRgn);
	DeleteObject (hRgn);
}

void DoCircleRegion (HWND hWnd, HDC hdc, bool bInvert)
{
RECT	rcRegion, rcClient;
HRGN	hRgn;

	GetClientRect (hWnd, &rcClient);
	int nSide = rcClient.bottom / 2;
	rcRegion.top = (rcClient.bottom - nSide) / 2 ;
	rcRegion.bottom = rcRegion.top + nSide;
	rcRegion.left = (rcClient.right - nSide) / 2;
	rcRegion.right = rcRegion.left + nSide;
	hRgn = CreateEllipticRgnIndirect (&rcRegion);

	DrawRadials (hdc, hRgn, rcClient);
	if (bInvert)
		InvertRgn (hdc, hRgn);
	DeleteObject (hRgn);
}

void DoEllipseRegion (HWND hWnd, HDC hdc, bool bInvert)
{
RECT	rcRegion, rcClient;
HRGN	hRgn;

	GetClientRect (hWnd, &rcClient);
	rcRegion.top = rcClient.bottom / 4;
	rcRegion.bottom = rcRegion.top * 3;
	rcRegion.left = rcClient.right / 4;
	rcRegion.right = rcRegion.left * 3;
	hRgn = CreateEllipticRgnIndirect (&rcRegion);

	DrawRadials (hdc, hRgn, rcClient);
	if (bInvert)
		InvertRgn (hdc, hRgn);
	DeleteObject (hRgn);
}

void DoPolyRegion (HWND hWnd, HDC hdc, bool bStar, bool bInvert)
{
RECT	rcClient;
POINT	point[5];
double	fAngle;
int		i;
HRGN hRgn;


//2 * PI / 360

	GetClientRect (hWnd, &rcClient);
	int nArm = rcClient.bottom / 3;
	for (fAngle = PI / 2, i = 0; i < 5; fAngle += 2 * PI / 5, ++i)
	{
		point[i].x = rcClient.right / 2 + (int) (cos (fAngle) * nArm);
		point[i].y = rcClient.bottom / 2 - (int) (sin (fAngle) * nArm);
	}
	if (bStar)
	{
	POINT temp, temp1;
	HRGN	hLeft, hRight;

		temp = point[1];
		point[1] = point[3];
		temp1 = point[2];
		point[2] = temp;
		temp = point[4];
		point[4] = temp1;
		point[3] = temp;
		hLeft = CreatePolygonRgn (point, 5, ALTERNATE);
		OffsetRgn (hLeft, -rcClient.right / 4, 0);
		hRight = CreatePolygonRgn (point, 5, WINDING);
		OffsetRgn (hRight, rcClient.right / 4, 0);
		HRGN hRgn = CreateRectRgn (0, 0, 1, 1);
		CombineRgn (hRgn, hRight, hLeft, RGN_OR);
		DeleteObject (hLeft);
		DeleteObject (hRight);
		DrawRadials (hdc, hRgn, rcClient);
	}
	else
	{
		hRgn = CreatePolygonRgn (point, 5, ALTERNATE);
		DrawRadials (hdc, hRgn, rcClient);
	}
	if (bInvert)
		InvertRgn (hdc, hRgn);
	DeleteObject (hRgn);
}

void DoCloverRegion (HWND hWnd, HDC hdc, bool bInvert)
{
HRGN hRgn, hTemp[6];
RECT	rcClient;

	GetClientRect (hWnd, &rcClient);
	hTemp[0] = CreateEllipticRgn (0, rcClient.bottom / 3,
									rcClient.right /  2, 2 * rcClient.bottom / 3); 
	hTemp[1] = CreateEllipticRgn (rcClient.right / 2, rcClient.bottom / 3,
									rcClient.right, 2 * rcClient.bottom / 3); 
	hTemp[2] = CreateEllipticRgn (rcClient.right / 3, 0,
									2 * rcClient.right /  3, rcClient.bottom / 2); 
	hTemp[3] = CreateEllipticRgn (rcClient.right / 3, rcClient.bottom / 2,
									2 * rcClient.right /  3, rcClient.bottom); 
	hTemp[4] = CreateRectRgn (0, 0, 1, 1);
	hTemp[5] = CreateRectRgn (0, 0, 1, 1);

	hRgn = CreateRectRgn (0, 0, 1, 1);
	CombineRgn (hTemp[4], hTemp[0], hTemp[1], RGN_OR);
	CombineRgn (hTemp[5], hTemp[2], hTemp[3], RGN_OR);
	CombineRgn (hRgn, hTemp[4], hTemp[5], RGN_XOR);

	for (int i = 0; i < 6; ++i)
		DeleteObject (hTemp[i]);
	DrawRadials (hdc, hRgn, rcClient, 0);
	if (bInvert)
		InvertRgn (hdc, hRgn);
	DeleteObject (hRgn);
}

void DoMappingModes (HWND hWnd, HDC hdc)
{
int nOldMapMode;
int nMapMode;
RECT	rcClient, rcText;
HPEN	hPen;
LOGFONT	lf;
HFONT	hFont;
int nHorzSide, nVertSide, nOrigin;
int nModes[] =  {MM_TEXT, MM_HIMETRIC, MM_LOMETRIC,
				 MM_HIENGLISH, MM_LOENGLISH, MM_TWIPS};
char *szLabels[] = 
	{
		"MM_TEXT",
		"MM_HIMETRIC",
		"MM_LOMETRIC",
		"MM_HIENGLISH",
		"MM_LOENGLISH",
		"MM_TWIPS"
	};

	GetClientRect (hWnd, &rcClient);
	nVertSide = rcClient.bottom / 3;
	nHorzSide = nVertSide;

//	int nOldROP = SetROP2 (hdc, R2_MASKPEN);
//	int nOldROP = SetROP2 (hdc, R2_NOTXORPEN);
//	int nOldROP = SetROP2 (hdc, R2_NOTMASKPEN);

	CreateLogFont (hdc, lf, 14);
	hFont = CreateFontIndirect (&lf);

	rcText.right = rcClient.right;
	rcText.left = 3 * nHorzSide + 20;

	nOldMapMode = GetMapMode (hdc);
	for (int i = 0; i < 6; ++i)
	{
		nVertSide = rcClient.bottom - 10;
		nHorzSide = nVertSide;
		nMapMode = SetMapMode (hdc, nModes[i]);
		rcText.top = rcClient.top + 20 * (i + 1) + lf.lfHeight;
		rcText.bottom = rcText.top + lf.lfHeight;
		switch (nModes[i])
		{
			case MM_TEXT:
				hPen = CreatePen (PS_SOLID, 2, 0);
				SelectObject (hdc, hPen);
				nOrigin = 0;
				SetTextColor (hdc, 0);
				break;
			case MM_HIMETRIC:
				hPen = CreatePen (PS_SOLID, 2, 0x00ff0000);
				SelectObject (hdc, hPen);
				nVertSide *= -1;
				nOrigin = 100;
				SetTextColor (hdc, 0x00ff0000);
				break;
			case MM_LOMETRIC:
				hPen = CreatePen (PS_SOLID, 2, 0x0000ff00);
				SelectObject (hdc, hPen);
				nVertSide *= -1;
				nOrigin = 10;
				SetTextColor (hdc, 0x0000ff00);
				break;
			case MM_HIENGLISH:
				hPen = CreatePen (PS_SOLID, 2, 0x000000ff);
				SelectObject (hdc, hPen);
				nVertSide *= -1;
				nHorzSide *= 1;
				nOrigin = 30;
				SetTextColor (hdc, 0x000000ff);
				break;
			case MM_LOENGLISH:
				hPen = CreatePen (PS_SOLID, 2, 0x00ff00ff);
				SelectObject (hdc, hPen);
				nVertSide *= -1;
				nHorzSide *= 1;
				nOrigin = 100;
				SetTextColor (hdc, 0x00ff00ff);
				break;
			case MM_TWIPS:
				hPen = CreatePen (PS_SOLID, 2, 0x00ffff00);
				SelectObject (hdc, hPen);
				nVertSide *= -1;
				nHorzSide *= 1;
				nOrigin = 50;
				SetTextColor (hdc, 0x00ffff00);
				break;
		}
		DrawRect (hdc, nOrigin, -nOrigin, nHorzSide, nVertSide);
		SetMapMode (hdc, MM_TEXT);
		DrawText (hdc, szLabels[i], strlen (szLabels[i]), &rcText, TEXT_FORMAT & ~DT_CENTER);
		DeleteObject (hPen);
	}
	SetMapMode (hdc, nOldMapMode);
//	SetROP2 (hdc, nOldROP);
}

void DrawRect (HDC hdc, int x, int y, int width, int depth)
{
	Rectangle (hdc, x, y, x + width, y + depth);
}

void DoRectanglePath (HWND hWnd, HDC hdc)
{
RECT	rcClient;
POINT	pt;
LOGBRUSH	lb;
HBRUSH hGrayBrush, hWhiteBrush;

	GetClientRect (hWnd, &rcClient);
	lb.lbStyle = BS_SOLID;
	lb.lbColor = RGB(0x77, 0x77, 0x77);
	lb.lbHatch = 0;
	hGrayBrush = CreateBrushIndirect (&lb);
	lb.lbColor = RGB(0xff, 0xff, 0xff);
	hWhiteBrush = CreateBrushIndirect (&lb);

	BeginPath (hdc);
	Rectangle (hdc, rcClient.bottom / 4, rcClient.bottom / 4, 
                    3 * rcClient.bottom / 4, 3 * rcClient.bottom / 4);
	CloseFigure (hdc);
	EndPath (hdc);
	HPEN hPen = CreatePen (PS_SOLID, 1, 0);
	SelectObject (hdc, hPen);
	SelectObject (hdc, hGrayBrush);
	StrokeAndFillPath (hdc);
	BOOL bResult = SetViewportOrgEx (hdc, 20, 20, &pt);
	SelectObject (hdc, hWhiteBrush);
	StrokeAndFillPath (hdc);
	SetViewportOrgEx (hdc, pt.x, pt.y, NULL);

	DeleteObject (hPen);
	DeleteObject (hGrayBrush);
	DeleteObject (hWhiteBrush);

}

void DoTextPath (HWND hWnd, HDC hdc)
{
RECT	rcClient;
LOGFONT	lf;
HRGN	hRgn;
LOGBRUSH	lb;
HBRUSH hGrayBrush, hBlackBrush;

	GetClientRect (hWnd, &rcClient);
	lb.lbStyle = BS_SOLID;
	lb.lbColor = RGB(0x77, 0x77, 0x77);
	lb.lbHatch = 0;
	hGrayBrush = CreateBrushIndirect (&lb);
	lb.lbColor = RGB(0x0, 0x0, 0x0);
	hBlackBrush = CreateBrushIndirect (&lb);

	CreateLogFont (hdc, lf, 120);
	lf.lfHeight = -lf.lfHeight;
	HFONT hFont = CreateFontIndirect(&lf);
	SelectObject (hdc, hFont);
	BeginPath (hdc);
	DrawText (hdc, "HEY!", 4, &rcClient, TEXT_FORMAT);
	EndPath (hdc);

	HRGN hTemp1, hTemp2;
	RECT rcText;
	hTemp1 = PathToRegion (hdc);
	GetRgnBox (hTemp1, &rcText);
	hTemp2 = CreateRectRgnIndirect (&rcText);
	hRgn = CreateRectRgn (0, 0, 1, 1);
	CombineRgn (hRgn, hTemp1, hTemp2, RGN_XOR);
	DeleteObject (hTemp1);
	DeleteObject (hTemp2);

	OffsetRgn (hRgn, 20, 20);
	FillRgn (hdc, hRgn, hGrayBrush);
	OffsetRgn (hRgn, -20, -20);
	FillRgn (hdc, hRgn, hBlackBrush);
	DeleteObject (hRgn);
	DeleteObject (hGrayBrush);
	DeleteObject (hBlackBrush);
	DeleteObject (hFont);
}

void DrawRadials (HDC hdc, HRGN hRgn, RECT & rc, int nShadow, int nStep)
{
double	fAngle, fRadius;
HPEN	hPen, hOldPen;
HBRUSH	hbrGray, hbrBlack, hbrWhite;

	hbrGray = CreateSolidBrush (RGB(0x77, 0x77, 0x77));
	hbrBlack = CreateSolidBrush (RGB(0x0, 0x0, 0x0));
	hbrWhite = CreateSolidBrush (RGB(0xff, 0xff, 0xff));

	if (nShadow)
	{
		OffsetRgn (hRgn, nShadow, nShadow);
//
//	To create our shadow, you may use one of two methods. In the first
//	you select the brush into the device context, then call PaintRegion().
//	In the second method, you call FillRgn with the brush you want to
//	fill the region with.
		SelectObject (hdc, hbrGray);
		PaintRgn (hdc, hRgn);
//	FillRgn (hdc, hRgn, hbrGray);

//	Draw a black frame around the shadow.
		FrameRgn (hdc, hRgn, hbrBlack, 1, 1);

		OffsetRgn (hRgn, -nShadow, -nShadow);
//
//	Regions are transparent, so we want to erase the portion of the
//	shadow below our image. See the note above abouit filling and painting.
		FillRgn (hdc, hRgn, hbrWhite);
	}
//	Draw a black frame around the image.
	FrameRgn (hdc, hRgn, hbrBlack, 1, 1);

//	We'll draw long lines and let the region clip them
	fRadius = _hypot (rc.right / 2.0, rc.bottom / 2.0);

//	Set the viewport origin to the center of the rectangle
	POINT pOldOrigin;
	SetViewportOrgEx (hdc, rc.right / 2, rc.bottom / 2, &pOldOrigin);
//	Select the region as our clipping area
	SelectClipRgn (hdc, hRgn);
//	Create and select our pen
	hPen = CreatePen (PS_SOLID, 1, RGB(0x00, 0x00, 0x00));
	hOldPen = (HPEN) SelectObject (hdc, hPen);

//	Draw the radials from the viewport origin.
	for (fAngle = 0; fAngle < 2 * PI; fAngle += nStep * 2 * PI / 360)
	{
		MoveToEx (hdc, 0, 0, NULL);
		LineTo (hdc, (int) (fRadius * cos (fAngle) + 0.5),
					 (int) (-fRadius * sin (fAngle) + 0.5));
	}
//	Reselect the old pen and delete the one we created.
	SelectObject (hdc, hOldPen);
	DeleteObject (hPen);
//	Get rid of the brushes we created.
	DeleteObject (hbrBlack);
	DeleteObject (hbrGray);
	DeleteObject (hbrWhite);
	SetViewportOrgEx (hdc, pOldOrigin.x, pOldOrigin.y, NULL);
}

void CreateLogFont (HDC hdc, LOGFONT & lf, int nPoints, char *szFace)
{
	memset (&lf, '\0', sizeof (LOGFONT));
	lf.lfCharSet = DEFAULT_CHARSET;
	lf.lfClipPrecision = OUT_TT_PRECIS;
	lf.lfQuality = DEFAULT_QUALITY;
	lf.lfPitchAndFamily = DEFAULT_PITCH | FF_ROMAN;
	lf.lfHeight = MulDiv(nPoints, GetDeviceCaps(hdc, LOGPIXELSY), 72);
	strcpy (lf.lfFaceName, szFace);
}

void DoMouseEvent (HWND hWnd, UINT message, UINT nFlags, POINT & point)
{
static bool	bTracking = false;
static POINT	ptLineStart = {0, 0};
static POINT	ptLineEnd = {0, 0};

	switch (message)
	{
		case WM_LBUTTONDOWN:
			ptLineStart = point;
			break;
		case WM_LBUTTONUP:
			bTracking = false;
			ptLineStart.x = 0;
			ptLineStart.y = 0;
			break;
		case WM_MOUSEMOVE:
			if (!(nFlags & MK_LBUTTON))
				return;
			if (bTracking)
			{
			HDC hdc;
				POINT pt;
				pt = point;
				hdc = GetDC (hWnd);
				DoMouseLine (hdc, ptLineStart, ptLineEnd);
				DoMouseLine (hdc, ptLineStart, pt);
				ReleaseDC (hWnd, hdc);
			}
			ptLineEnd = point;
			bTracking = true;
			break;
	}
}

void DoMouseLine (HDC hdc, POINT & ptLineStart, POINT & ptLineEnd)
{
	HPEN hPen = CreatePen (PS_SOLID, 2, 0);
	int nOldMode = SetROP2 (hdc, R2_NOT);
	MoveToEx (hdc, ptLineStart.x, ptLineStart.y, NULL);
	SelectObject (hdc, hPen);
	LineTo (hdc, ptLineEnd.x, ptLineEnd.y);
	SetROP2 (hdc, nOldMode);
	DeleteObject (hPen);
}
