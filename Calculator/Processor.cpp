#include "Processor.h"
using namespace std;

Processor* Processor::_processor = nullptr;

Processor* Processor::GetInstance() {
	if (_processor == nullptr) {
		_processor = new Processor();
	}
	return _processor;
}

void Processor::GetDecimal(wxCommandEvent& evt, cMain* this2) {

	cmain->result->AppendAndEnsureVisible(cmain->Calc->GetValue());
}

void Processor::GetHexadecimal(wxCommandEvent& evt, cMain* this2) {
	this->cmain = this2;
	
	if (cmain->Calc->GetLineLength(1) == 0)
		return;

	wxString result2 = "0x";
	int number = cmain->StringToDouble(cmain->Calc->GetValue());
	while (number > 0) {
		int mod = number % 16;
		if (mod < 10) {
			result2 += std::to_string(mod);
		}
		else if (mod == 10) {
			result2 += "A";
		}
		else if (mod == 11) {
			result2 += "B";
		}
		else if (mod == 12) {
			result2 += "C";
		}
		else if (mod == 13) {
			result2 += "D";
		}
		else if (mod == 14) {
			result2 += "E";
		}
		else if (mod == 15) {
			result2 += "F";
		}
		number /= 16;
	}
	cmain->result->AppendAndEnsureVisible(result2);

	evt.Skip();
}

void Processor::GetBinary(wxCommandEvent& evt, cMain* this2) {
	this->cmain = this2;

	if (cmain->Calc->GetLineLength(1) == 0)
		return;

	wxString result2 = "";
	int number = cmain->StringToDouble(cmain->Calc->GetValue());
	for (int i = 0; i < 32; ++i) {
		if (number % 2 == 0) {
			result2 += "0";
		}
		else
		{
			result2 += "1";
		}
		number /= 2;
	}
	cmain->result->AppendAndEnsureVisible(result2);

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
	int one = 0;
	int two = 0;

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
		two = cmain->StringToDouble(cmain->Calc->GetValue());
		cmain->res = one % two;
		cmain->result->AppendAndEnsureVisible(" % " + cmain->Calc->GetValue());
		cmain->result->AppendAndEnsureVisible(" = " + cmain->DoubleToString(cmain->res));
		cmain->ResetFlags();
		cmain->ResetNumber();
	}
	else if (cmain->ExponentFlag) {
		cmain->op2 = cmain->StringToDouble(cmain->Calc->GetValue());
		cmain->res = pow(cmain->op1,cmain->op2);
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
	int one = 0;
	int two = 0;
	if (cmain->Calc->GetLineLength(1) == 0)
		return;

	if (!cmain->ModularFlag)
	{
		one = cmain->StringToDouble(cmain->Calc->GetValue());
		cmain->ModularFlag = true;
		cmain->result->AppendAndEnsureVisible(" % " + cmain->Calc->GetValue());
		cmain->ResetNumber();
	}
	else if (cmain->ModularFlag)
	{
		two = cmain->StringToDouble(cmain->Calc->GetValue());
		cmain->res = one % two;
		one = cmain->res;
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
		cmain->res = pow(cmain->op1,cmain->op2);
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

#pragma endregion