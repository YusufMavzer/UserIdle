#pragma once
#include "stdafx.h"
#include "UserIdle.h"

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

extern "C" __declspec(dllexport) int GetLastUserInputTime() {
	return UserIdle::GetLastUserInputTime();
}
extern "C" __declspec(dllexport) void ResetUserInputTime() {
	UserIdle::ResetUserInputTime();
	return;
}