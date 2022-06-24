#include "Processor.h"
#include <bitset>

using namespace std;
Processor* Processor::_processor = nullptr;

Processor* Processor::GetInstance() {
	if (_processor == nullptr) {
		_processor = new Processor();
	}
	return _processor;
}

void Processor::GetDecimal(wxCommandEvent& evt, cMain* this2) {

	this->cmain = this2;

	cmain->result->AppendAndEnsureVisible(cmain->Calc->GetValue());

	evt.Skip();
}

void Processor::GetHexadecimal(wxCommandEvent& evt, cMain* this2) {
	this->cmain = this2;

	if (cmain->Calc->GetLineLength(1) == 0)
		return;

	int number = cmain->StringToDouble(cmain->Calc->GetValue());

	std::ostringstream ss;
	ss << "0x" << std::hex << number;
	std::string result = ss.str();

	cmain->result->AppendAndEnsureVisible(result);

	evt.Skip();
}

void Processor::GetBinary(wxCommandEvent& evt, cMain* this2) {
	this->cmain = this2;

	if (cmain->Calc->GetLineLength(1) == 0)
		return;

	int number = cmain->StringToDouble(cmain->Calc->GetValue());
	string str;
	while (number) {
		if (number & 1)
			str += '1';
		else
			str += '0';
		number >>= 1;
	}
	std::reverse(str.begin(), str.end());

	cmain->result->AppendAndEnsureVisible(str);

	evt.Skip();
}

#pragma region Operations

void Processor::onOperationDiv(wxCommandEvent& evt, cMain* this2) {
	this->cmain = this2;

	if (cmain->Calc->GetLineLength(1) == 0)
		return;

	if (!cmain->DivisionFlag)
	{
		cmain->op1 = cmain->StringToDouble(cmain->Calc->GetValue());
		cmain->DivisionFlag = true;
		cmain->result->AppendAndEnsureVisible(" / " + cmain->Calc->GetValue());
		cmain->ResetNumber();
	}
	else if (cmain->DivisionFlag)
	{
		cmain->op2 = cmain->StringToDouble(cmain->Calc->GetValue());
		cmain->res = cmain->op1 / cmain->op2;
		cmain->op1 = cmain->res;
		cmain->result->AppendAndEnsureVisible(" / " + cmain->Calc->GetValue());
		cmain->result->AppendAndEnsureVisible(" = " + cmain->DoubleToString(cmain->res));
		cmain->ResetNumber();
	}

	evt.Skip();
}

void Processor::onOperationTimes(wxCommandEvent& evt, cMain* this2) {
	this->cmain = this2;

	if (cmain->Calc->GetLineLength(1) == 0)
		return;

	if (!cmain->MultiplyFlag)
	{
		cmain->op1 = cmain->StringToDouble(cmain->Calc->GetValue());
		cmain->MultiplyFlag = true;
		cmain->result->AppendAndEnsureVisible(" * " + cmain->Calc->GetValue());
		cmain->ResetNumber();
	}
	else if (cmain->MultiplyFlag)
	{
		cmain->op2 = cmain->StringToDouble(cmain->Calc->GetValue());
		cmain->res = cmain->op1 * cmain->op2;
		cmain->op1 = cmain->res;
		cmain->result->AppendAndEnsureVisible(" * " + cmain->Calc->GetValue());
		cmain->result->AppendAndEnsureVisible(" = " + cmain->DoubleToString(cmain->res));
		cmain->ResetNumber();
	}

	evt.Skip();
}

void Processor::OnOperationMinus(wxCommandEvent& evt, cMain* this2) {
	this->cmain = this2;

	if (cmain->Calc->GetLineLength(1) == 0)
		return;

	if (!cmain->SubtractionFlag)
	{
		cmain->op1 = cmain->StringToDouble(cmain->Calc->GetValue());
		cmain->SubtractionFlag = true;
		cmain->result->AppendAndEnsureVisible(" - " + cmain->Calc->GetValue());
		cmain->ResetNumber();
	}
	else if (cmain->SubtractionFlag)
	{
		cmain->op2 = cmain->StringToDouble(cmain->Calc->GetValue());
		cmain->res = cmain->op1 - cmain->op2;
		cmain->op1 = cmain->res;
		cmain->result->AppendAndEnsureVisible(" - " + cmain->Calc->GetValue());
		cmain->result->AppendAndEnsureVisible(" = " + cmain->DoubleToString(cmain->res));
		cmain->ResetNumber();
	}
	evt.Skip();
}

void Processor::OnOperationPlus(wxCommandEvent& evt, cMain* this2) {
	this->cmain = this2;

	if (cmain->Calc->GetLineLength(1) == 0)
		return;

	if (!cmain->AdditionFlag)
	{
		cmain->op1 = cmain->StringToDouble(cmain->Calc->GetValue());
		cmain->AdditionFlag = true;
		cmain->result->AppendAndEnsureVisible(" + " + cmain->Calc->GetValue());
		cmain->ResetNumber();
	}
	else if (cmain->AdditionFlag)
	{
		cmain->op2 = cmain->StringToDouble(cmain->Calc->GetValue());
		cmain->res = cmain->op1 + cmain->op2;
		cmain->op1 = cmain->res;
		cmain->result->AppendAndEnsureVisible(" + " + cmain->Calc->GetValue());
		cmain->result->AppendAndEnsureVisible(" = " + cmain->DoubleToString(cmain->res));
		cmain->ResetNumber();
	}
	evt.Skip();
}

void Processor::onOperationEquals(wxCommandEvent& evt, cMain* this2) {
	this->cmain = this2;

	if (cmain->Calc->GetLineLength(1) == 0)
		return;

	if (cmain->AdditionFlag)
	{
		cmain->op2 = cmain->StringToDouble(cmain->Calc->GetValue());
		cmain->res = cmain->op1 + cmain->op2;
		cmain->result->AppendAndEnsureVisible(" + " + cmain->Calc->GetValue());
		cmain->result->AppendAndEnsureVisible(" = " + cmain->DoubleToString(cmain->res));
		cmain->ResetFlags();
		cmain->ResetNumber();
	}
	else if (cmain->MultiplyFlag)
	{
		cmain->op2 = cmain->StringToDouble(cmain->Calc->GetValue());
		cmain->res = cmain->op1 * cmain->op2;
		cmain->result->AppendAndEnsureVisible(" * " + cmain->Calc->GetValue());
		cmain->result->AppendAndEnsureVisible(" = " + cmain->DoubleToString(cmain->res));
		cmain->ResetFlags();
		cmain->ResetNumber();
	}
	else if (cmain->DivisionFlag)
	{
		cmain->op2 = cmain->StringToDouble(cmain->Calc->GetValue());
		cmain->res = cmain->op1 / cmain->op2;
		cmain->result->AppendAndEnsureVisible(" / " + cmain->Calc->GetValue());
		cmain->result->AppendAndEnsureVisible(" = " + cmain->DoubleToString(cmain->res));
		cmain->ResetFlags();
		cmain->ResetNumber();
	}
	else if (cmain->SubtractionFlag)
	{
		cmain->op2 = cmain->StringToDouble(cmain->Calc->GetValue());
		cmain->res = cmain->op1 - cmain->op2;
		cmain->result->AppendAndEnsureVisible(" - " + cmain->Calc->GetValue());
		cmain->result->AppendAndEnsureVisible(" = " + cmain->DoubleToString(cmain->res));
		cmain->ResetFlags();
		cmain->ResetNumber();
	}
	else if (cmain->ModularFlag) {
		cmain->op2 = cmain->StringToDouble(cmain->Calc->GetValue());
		cmain->res = (int)cmain->op1 % (int)cmain->op2;
		cmain->result->AppendAndEnsureVisible(" % " + cmain->Calc->GetValue());
		cmain->result->AppendAndEnsureVisible(" = " + cmain->DoubleToString(cmain->res));
		cmain->ResetFlags();
		cmain->ResetNumber();
	}
	else if (cmain->ExponentFlag) {
		cmain->op2 = cmain->StringToDouble(cmain->Calc->GetValue());
		cmain->res = pow(cmain->op1, cmain->op2);
		cmain->result->AppendAndEnsureVisible(" ^ " + cmain->Calc->GetValue());
		cmain->result->AppendAndEnsureVisible(" = " + cmain->DoubleToString(cmain->res));
		cmain->ResetFlags();
		cmain->ResetNumber();
	}

	evt.Skip();
}

void Processor::onDecimal(wxCommandEvent& evt, cMain* this2) {
	this->cmain = this2;

	if (!cmain->isDecimal)
	{
		cmain->Calc->AppendText(".");
		cmain->isDecimal = true;
	}
	evt.Skip();
}

void Processor::plusToMinus(wxCommandEvent& evt, cMain* this2) {
	this->cmain = this2;

	if (cmain->Calc->GetLineLength(1) == 0)
		return;

	double aux = cmain->StringToDouble(cmain->Calc->GetValue());
	double ret = aux * -1;
	wxString mystring = cmain->DoubleToString(ret);

	cmain->Calc->SetValue(mystring);

	evt.Skip();
}

void Processor::modular(wxCommandEvent& evt, cMain* this2) {
	this->cmain = this2;
	if (cmain->Calc->GetLineLength(1) == 0)
		return;

	if (!cmain->ModularFlag)
	{
		cmain->op1 = cmain->StringToDouble(cmain->Calc->GetValue());
		cmain->ModularFlag = true;
		cmain->result->AppendAndEnsureVisible(" % " + cmain->Calc->GetValue());
		cmain->ResetNumber();
	}
	else if (cmain->ModularFlag)
	{
		cmain->op2 = cmain->StringToDouble(cmain->Calc->GetValue());
		cmain->res = (int)cmain->op1 % (int)cmain->op2;
		cmain->op1 = cmain->res;
		cmain->result->AppendAndEnsureVisible(" % " + cmain->Calc->GetValue());
		cmain->result->AppendAndEnsureVisible(" = " + cmain->DoubleToString(cmain->res));
		cmain->ResetNumber();
	}

	evt.Skip();
}

void Processor::OnsquareRoot(wxCommandEvent& evt, cMain* this2) {
	this->cmain = this2;

	if (cmain->Calc->GetLineLength(1) == 0)
		return;

	cmain->op1 = cmain->StringToDouble(cmain->Calc->GetValue());
	cmain->result->AppendAndEnsureVisible(L"\u221a" + cmain->Calc->GetValue());
	cmain->res = sqrt(cmain->op1);
	cmain->op1 = cmain->res;
	cmain->result->AppendAndEnsureVisible(L"\u221a" + cmain->Calc->GetValue());
	cmain->result->AppendAndEnsureVisible(" = " + cmain->DoubleToString(cmain->res));
	cmain->ResetNumber();

	evt.Skip();
}

void Processor::OnExponent(wxCommandEvent& evt, cMain* this2) {
	this->cmain = this2;

	if (cmain->Calc->GetLineLength(1) == 0)
		return;

	if (!cmain->AdditionFlag)
	{
		cmain->op1 = cmain->StringToDouble(cmain->Calc->GetValue());
		cmain->ExponentFlag = true;
		cmain->result->AppendAndEnsureVisible(" ^ " + cmain->Calc->GetValue());
		cmain->ResetNumber();
	}
	else if (cmain->AdditionFlag)
	{
		cmain->op2 = cmain->StringToDouble(cmain->Calc->GetValue());
		cmain->res = pow(cmain->op1, cmain->op2);
		cmain->op1 = cmain->res;
		cmain->result->AppendAndEnsureVisible(" ^ " + cmain->Calc->GetValue());
		cmain->result->AppendAndEnsureVisible(" = " + cmain->DoubleToString(cmain->res));
		cmain->ResetNumber();
	}
	evt.Skip();
}

void Processor::allClear(wxCommandEvent& evt, cMain* this2) {
	this->cmain = this2;
	cmain->ResetFlags();
	cmain->ResetNumber();
	evt.Skip();
}

void Processor::onSingleClear(wxCommandEvent& evt, cMain* this2) {
	this->cmain = this2;

	if (cmain->Calc->GetRange(cmain->Calc->GetLastPosition() - 1, cmain->Calc->GetLastPosition()) == '.')
		cmain->isDecimal = false;

	if (cmain->Calc->GetLineLength(1) == 0)
		cmain->ResetNumber();
	else
		cmain->Calc->Remove(cmain->Calc->GetLastPosition() - 1, cmain->Calc->GetLastPosition());

	if (cmain->isDecimal && cmain->DecimalCounter < 15)
		--cmain->DecimalCounter;

	evt.Skip();
}

void Processor::sin_btn(wxCommandEvent& evt, cMain* this2) {
	this->cmain = this2;

	if (cmain->Calc->GetLineLength(1) == 0)
		return;

	cmain->op1 = cmain->StringToDouble(cmain->Calc->GetValue());
	cmain->result->AppendAndEnsureVisible("Sin" + cmain->Calc->GetValue());
	cmain->res = sin(cmain->op1 * M_PI / 180);
	cmain->op1 = cmain->res;
	cmain->result->AppendAndEnsureVisible("Sin" + cmain->Calc->GetValue());
	cmain->result->AppendAndEnsureVisible(" = " + cmain->DoubleToString(cmain->res));
	cmain->ResetNumber();
}

void Processor::tan_btn(wxCommandEvent& evt, cMain* this2) {
	this->cmain = this2;

	if (cmain->Calc->GetLineLength(1) == 0)
		return;

	cmain->op1 = cmain->StringToDouble(cmain->Calc->GetValue());
	cmain->result->AppendAndEnsureVisible("Sin" + cmain->Calc->GetValue());
	cmain->res = tan(cmain->op1 * M_PI / 180);
	cmain->op1 = cmain->res;
	cmain->result->AppendAndEnsureVisible("Sin" + cmain->Calc->GetValue());
	cmain->result->AppendAndEnsureVisible(" = " + cmain->DoubleToString(cmain->res));
	cmain->ResetNumber();
}

void Processor::cos_btn(wxCommandEvent& evt, cMain* this2) {
	this->cmain = this2;

	if (cmain->Calc->GetLineLength(1) == 0)
		return;

	cmain->op1 = cmain->StringToDouble(cmain->Calc->GetValue());
	cmain->result->AppendAndEnsureVisible("Sin" + cmain->Calc->GetValue());
	cmain->res = cos(cmain->op1 * M_PI / 180);
	cmain->op1 = cmain->res;
	cmain->result->AppendAndEnsureVisible("Sin" + cmain->Calc->GetValue());
	cmain->result->AppendAndEnsureVisible(" = " + cmain->DoubleToString(cmain->res));
	cmain->ResetNumber();
}


#pragma endregion

#pragma region Unit Tests(Contain same code as regular functions)


//the reason the code is so much shorter here is because in my
// other ones I had to use the textctrl and the results box and etc
// but here all I have to do is run and see if my math logic is 
//Correct
int Processor::TestOnOperationPlus(int op1, int op2) {
	int res;

	res = op1 + op2;

	return res;
}

int Processor::TestOnOperationMinus(int op1, int op2) {
	int res;

	res = op1 - op2;

	return res;
}

int Processor::TestonOperationTimes(int op1, int op2) {
	int res;

	res = op1 * op2;

	return res;
}

int Processor::TestonOperationDiv(int op1, int op2) {
	int res;

	res = op1 / op2;

	return res;
}

string Processor::TestGetBinary(int op1) {
	string str;
	while (op1) {
		if (op1 & 1)
			str += '1';
		else 
			str += '0';
		op1 >>= 1; 
	}
	std::reverse(str.begin(), str.end());

	return str;
}

string Processor::TestGetHexadecimal(int op1) {
	std::ostringstream ss;
	ss << "0x" << std::hex << op1;
	std::string result = ss.str();

	return result;
}
#pragma endregion 