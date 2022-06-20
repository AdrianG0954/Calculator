#pragma once
#include "buttonFactory.h"
#include <string>
#include "wx/wx.h"
#include "cMain.h"


class cMain;

class Processor
{
public:
	cMain* cmain;
private:
	static Processor* _processor;
	int baseNum;
	Processor() {}
public:
	static Processor* GetInstance();

	void setBaseNum(int number) {
		baseNum = number;
	}

	Processor(Processor& other) = delete;

	void operator=(const Processor& _assign) = delete;

#pragma region Operations

	void OnOperationPlus(wxCommandEvent& evt, cMain* this2);

	void OnOperationMinus(wxCommandEvent& evt, cMain* this2);

	void onOperationTimes(wxCommandEvent& evt, cMain* this2);

	void onOperationDiv(wxCommandEvent& evt, cMain* this2);

	void onOperationEquals(wxCommandEvent& evt, cMain* this2);

	void onDecimal(wxCommandEvent& evt, cMain* this2);

	void plusToMinus(wxCommandEvent& evt, cMain* this2);

	void modular(wxCommandEvent& evt, cMain* this2);

#pragma endregion

#pragma region Binary dec and hex

	void GetBinary(wxCommandEvent& evt, cMain* this2);

	void GetHexadecimal(wxCommandEvent& evt, cMain* this2);

	void GetDecimal();

#pragma endregion
};


