#pragma once
#include "buttonFactory.h"
#include <string>
#include <vector>
#include <queue>
#include "wx/wx.h"
#include "cMain.h"

using namespace std;


class cMain;

class Processor {

public:
	cMain* cmain;
private:
	static Processor* _processor;
	Processor() {}
public:
	static Processor* GetInstance();

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

	void OnExponent(wxCommandEvent& evt, cMain* this2);

	void onSingleClear(wxCommandEvent& evt, cMain* this2);

	void allClear(wxCommandEvent& evt, cMain* this2);

	void sin_btn(wxCommandEvent& evt, cMain* this2);

	void tan_btn(wxCommandEvent& evt, cMain* this2);

	void cos_btn(wxCommandEvent& evt, cMain* this2);

#pragma endregion

#pragma region Binary dec and hex

	void GetBinary(wxCommandEvent& evt, cMain* this2);

	void GetHexadecimal(wxCommandEvent& evt, cMain* this2);

	void OnsquareRoot(wxCommandEvent& evt, cMain* this2);

	void GetDecimal(wxCommandEvent& evt, cMain* this2);

#pragma endregion


};


