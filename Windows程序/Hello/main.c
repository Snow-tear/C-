#include <Windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {
	MessageBox(NULL, TEXT("Hello, Win32!"), TEXT("HelloMsg"), 0);
	return 0;
}