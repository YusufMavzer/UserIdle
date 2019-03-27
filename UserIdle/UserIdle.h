#pragma once
#include "stdafx.h"
class UserIdle {
public:
	static int GetLastUserInputTime()
	{
		LASTINPUTINFO lastInputInfo;
		lastInputInfo.cbSize = sizeof(LASTINPUTINFO);
		GetLastInputInfo(&lastInputInfo);
		return (GetTickCount() - lastInputInfo.dwTime); //user idle time milliseconds
	}
	static void ResetUserInputTime() {
		//SENDING MOUSE MOVE INPUT BUT KEEPING THE MOUSE POSITION THE SAME
		MOUSEINPUT mouseInput;
		mouseInput.dx = 0;
		mouseInput.dy = 0;
		mouseInput.dwFlags = MOUSEEVENTF_MOVE;
		mouseInput.mouseData = 0;
		mouseInput.time = 0;
		mouseInput.dwExtraInfo = 0;
		INPUT Input;
		Input.type = INPUT_MOUSE;
		Input.mi = mouseInput;
		SendInput(1, &Input, sizeof(Input));
	}
};