#include "controller.h"
#include <io.h>
#include <stdio.h>
#include <windows.h>



LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {



	
	//����һ������̨
	if (::AllocConsole()) {
		FILE* unused;
		if (freopen_s(&unused, "CONOUT$", "w", stdout)) {
			_dup2(_fileno(stdout), 1);
		}
		if (freopen_s(&unused, "CONOUT$", "w", stderr)) {
			_dup2(_fileno(stdout), 2);
		}
		std::ios::sync_with_stdio();
		FlutterDesktopResyncOutputStreams();
	}

	//������������
	FlutterDesktopEngineProperties property = {};
	std::cout << "go !"<< std::endl;
	std::wstring s0 = L"D:/src/custom_flutter_engine/share_texture/build/flutter_assets";
	std::wstring s1 = L"D:/src/custom_flutter_engine/engine/src/out/win_debug_unopt/icudtl.dat";
	std::wstring s2 = L"D:/src/custom_flutter_engine/engine/src/out/win_debug_unopt/dart - sdk/bin/snapshots";
	
	property.assets_path = s0.c_str();
	property.icu_data_path = s1.c_str();
	property.aot_library_path = NULL;
	property.dart_entrypoint_argc = 0;
	property.dart_entrypoint_argv = NULL;

	

	
	//��������
	FlutterDesktopEngineRef engine_ = FlutterDesktopEngineCreate(&property);
	if (!engine_) {
		return -3;
	}



	/*
	 �������ֻ���� engine��renderConfig���ú��������������������ٷ���GFLW����
	//��������
	bool result = FlutterDesktopEngineRun(engine_,NULL);
	if (!result) {
		return -2;
	}
	*/
	
	
	
	
	//����View��Ⱦ����
	FlutterDesktopViewControllerRef ctrl = FlutterDesktopViewControllerCreate(800, 600, engine_);

	if (!ctrl) {
		return -777;
	}


	

		//�õ�View Ϊ�˵õ�HWND
		FlutterDesktopViewRef view_ = FlutterDesktopViewControllerGetView(ctrl);
		HWND id = FlutterDesktopViewGetHWND(view_);

		
		if (!view_) {
			return -666;
		}

		

		
		//����ΪWin32�������ڵĴ���

		// Register the window class.
		const wchar_t CLASS_NAME[] =L"Flutter";
		
		WNDCLASS wc = { };

		wc.lpfnWndProc = WindowProc;
		wc.hInstance = hInstance;
		wc.lpszClassName = CLASS_NAME;

		RegisterClass(&wc);

		// Create the window.

		HWND hwnd = CreateWindowEx(
			0,                              // Optional window styles.
			CLASS_NAME,                     // Window class
			L"Learn to Flutter for Windows",    // Window text
			WS_OVERLAPPEDWINDOW,            // Window style

			// Size and position
			10, 10, 800, 600,

			NULL,       // Parent window    
			NULL,       // Menu
			hInstance,  // Instance handle
			NULL        // Additional application data
		);

		if (hwnd == NULL)
		{
			return 0;
		}

		ShowWindow(hwnd, nCmdShow);

		//��Flutter Engine����Ⱦ����ŵ�
		SetParent(id, hwnd);
		MoveWindow(id,10,10,800,600,1);
		SetFocus(id);

		// Run the message loop.

		MSG msg = { };
		while (GetMessage(&msg, NULL, 0, 0))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}


		
	
	
		
		
	

	return 0;
}



LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);



		FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

		EndPaint(hwnd, &ps);
	}
	return 0;

	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}