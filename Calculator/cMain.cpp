#include "cMain.h"
#include "buttonFactory.h"
wxBEGIN_EVENT_TABLE(cMain, wxFrame)

wxEND_EVENT_TABLE()

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(210, 200), wxSize(470, 470))
{
	buttonFactory factory;
	SetMinSize(wxSize(470, 470));
	SetMaxSize(wxSize(470, 470));

	//TEXT CTRL
	Calc = new wxTextCtrl(this, 102, "", wxPoint(35, 10), wxSize(385, 40), wxTE_RIGHT | wxTE_BESTWRAP);
	Calc->Enable(false);
	wxFont calc_font(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_SLANT, wxFONTWEIGHT_NORMAL, false);
	Calc->SetFont(calc_font);

	//RESULT BOX
	result = new wxListBox(this, 30092, wxPoint(35, 55), wxSize(150, 30));
	result->Enable(false);


	//Num buttons
	wxButton* num_Zero = factory.get_Zero(this,this);

	wxButton* num_One = factory.get_One(this,this);

	wxButton* num_Two =  factory.get_Two(this,this);

	wxButton* num_Three = factory.get_Three(this,this);

	wxButton* num_Four = factory.get_Four(this,this);

	wxButton* num_Five = factory.get_Five(this,this);

	wxButton* num_Six = factory.get_Six(this,this);

	wxButton* num_Seven = factory.get_Seven(this,this);

	wxButton* num_Eight = factory.get_Eight(this,this);

	wxButton* num_Nine =  factory.get_Nine(this,this);

	//MAIN OPERATION BUTTONS
	wxButton* neg = factory.get_toNeg(this,this);

	wxButton* dot = factory.get_Dot(this,this);

	wxButton* mod = factory.get_Mod(this,this);

	wxButton* all_Clear = factory.get_AC(this,this);

	wxButton* plus = factory.get_Plus(this,this);

	wxButton* minus = factory.get_Minus(this,this);

	wxButton* divide = factory.get_Div(this,this);

	wxButton* equals = factory.get_Equals(this,this);

	wxButton* times = factory.get_Times(this,this);

	//EXTRA OPERATION BUTTONS
	wxButton* pi = factory.get_Pi(this,this);

	wxButton* sin = factory.get_Sin(this,this);

	wxButton* tan = factory.get_Tan(this,this);

	wxButton* cos = factory.get_Cos(this,this);

	wxButton* less_Than = factory.get_LessThan(this, this);

	wxButton* greater_Than = factory.get_GreaterThan(this,this);

	wxButton* SquareRoot = factory.get_Squared(this,this);

	wxButton* exponent = factory.get_Exponent(this,this);

	wxButton* clear = factory.get_Per1(this,this);

	wxButton* per1 = factory.get_Per2(this,this);

	wxButton* per2 = factory.get_Clear(this,this);
	
}

#pragma region number click events

void cMain::num_Zero_btn(wxCommandEvent& evt) {
	if (isDecimal && DecimalCounter > 15)
		return;
	else if (isDecimal && DecimalCounter < 15)
		++DecimalCounter;

	Calc->AppendText("0");
	evt.Skip();
}


void cMain::num_One_btn(wxCommandEvent& evt) {
	if (isDecimal && DecimalCounter > 15)
		return;
	else if (isDecimal && DecimalCounter < 15)
		++DecimalCounter;

	Calc->AppendText("1");
	evt.Skip();
}


void cMain::num_Two_btn(wxCommandEvent& evt) {
	if (isDecimal && DecimalCounter > 15)
		return;
	else if (isDecimal && DecimalCounter < 15)
		++DecimalCounter;

	Calc->AppendText("2");
	evt.Skip();
}


void cMain::num_Three_btn(wxCommandEvent& evt) {
	if (isDecimal && DecimalCounter > 15)
		return;
	else if (isDecimal && DecimalCounter < 15)
		++DecimalCounter;

	Calc->AppendText("3");
	evt.Skip();
}


void cMain::num_Four_btn(wxCommandEvent& evt) {
	if (isDecimal && DecimalCounter > 15)
		return;
	else if (isDecimal && DecimalCounter < 15)
		++DecimalCounter;

	Calc->AppendText("4");
	evt.Skip();
}


void cMain::num_Five_btn(wxCommandEvent& evt) {
	if (isDecimal && DecimalCounter > 15)
		return;
	else if (isDecimal && DecimalCounter < 15)
		++DecimalCounter;

	Calc->AppendText("5");
	evt.Skip();
}


void cMain::num_Six_btn(wxCommandEvent& evt) {
	if (isDecimal && DecimalCounter > 15)
		return;
	else if (isDecimal && DecimalCounter < 15)
		++DecimalCounter;

	Calc->AppendText("6");
	evt.Skip();
}


void cMain::num_Seven_btn(wxCommandEvent& evt) {
	if (isDecimal && DecimalCounter > 15)
		return;
	else if (isDecimal && DecimalCounter < 15)
		++DecimalCounter;

	Calc->AppendText("7");
	evt.Skip();
}


void cMain::num_Eight_btn(wxCommandEvent& evt) {
	if (isDecimal && DecimalCounter > 15)
		return;
	else if (isDecimal && DecimalCounter < 15)
		++DecimalCounter;

	Calc->AppendText("8");
	evt.Skip();
}


void cMain::num_Nine_btn(wxCommandEvent& evt) {
	if (isDecimal && DecimalCounter > 15)
		return;
	else if (isDecimal && DecimalCounter < 15)
		++DecimalCounter;

	Calc->AppendText("9");
	evt.Skip();
}

#pragma endregion

#pragma region Main Operations

void cMain::toNegative(wxCommandEvent& evt) {
	Processor* processor = Processor::GetInstance();
	processor->plusToMinus(evt, this);
}
void cMain::toDecimal(wxCommandEvent& evt) {
	Processor* processor = Processor::GetInstance();
	processor->onDecimal(evt, this);
}
void cMain::all_Clear_btn(wxCommandEvent& evt) {
	Processor* processor = Processor::GetInstance();
	processor->allClear(evt, this);
}
void cMain::plus_btn(wxCommandEvent& evt) {
	Processor* processor = Processor::GetInstance();
	processor->OnOperationPlus(evt, this);
}
void cMain::minus_btn(wxCommandEvent& evt) {
	Processor* processor = Processor::GetInstance();
	processor->OnOperationMinus(evt, this);
}
void cMain::divide_btn(wxCommandEvent& evt) {
	Processor* processor = Processor::GetInstance();
	processor->onOperationDiv(evt, this);
}
void cMain::equals_btn(wxCommandEvent& evt) {
	Processor* processor = Processor::GetInstance();
	processor->onOperationEquals(evt, this);
}
void cMain::multiplication(wxCommandEvent& evt) {
	Processor* processor = Processor::GetInstance();
	processor->onOperationTimes(evt, this);
}

void cMain::modular(wxCommandEvent& evt) {
	Processor* processor = Processor::GetInstance();
	processor->modular(evt, this);
}


#pragma endregion

#pragma region Extra Operations

void cMain::pie(wxCommandEvent& evt) {
	if (isDecimal && DecimalCounter > 15)
		return;
	else if (isDecimal && DecimalCounter < 15)
		++DecimalCounter;

	Calc->AppendText("3.14");
	evt.Skip();
}

void cMain::sin_Button(wxCommandEvent& evt) {
	Calc->AppendText("Sin");
}

void cMain::tan_Button(wxCommandEvent& evt) {
	Calc->AppendText("Tan");
}

void cMain::cos_Button(wxCommandEvent& evt) {
	Calc->AppendText("Cos");
}

void cMain::less_Than_btn(wxCommandEvent& evt) {
	Calc->AppendText(L"\u2264");
}

void cMain::greater_Than_btn(wxCommandEvent& evt) {
	Calc->AppendText(L"\u2265");
}

void cMain::squareRoot_btn(wxCommandEvent& evt) {
	Processor* processor = Processor::GetInstance();
	processor->OnsquareRoot(evt, this);
}

void cMain::exponent_btn(wxCommandEvent& evt) {
	Processor* processor = Processor::GetInstance();
	processor->OnExponent(evt, this);
}

void cMain::single_clear(wxCommandEvent& evt) {
	Processor* processor = Processor::GetInstance();
	processor->onSingleClear(evt, this);
}

void cMain::per1_Click(wxCommandEvent& evt) {
	Processor* processor = Processor::GetInstance();
	processor->GetBinary(evt, this);
}

void cMain::per2_Click(wxCommandEvent& evt) {
	Processor* processor = Processor::GetInstance();
	processor->GetHexadecimal(evt, this);
}
#pragma endregion

#pragma region Extra stuff

void cMain::ResetNumber()
{
	isDecimal = false;
	isReset = true;
	Calc->Clear();
	DecimalCounter = 0;
}

void cMain::ResetFlags()
{
	AdditionFlag = false;
	DivisionFlag = false;
	MultiplyFlag = false;
	ModularFlag = false;
	ExponentFlag = false;
	SubtractionFlag = false;
	isDecimal = false;
	isReset = false;
}

double cMain::StringToDouble(wxString str)
{
	return std::stod(std::string(str));
}

wxString cMain::DoubleToString(double d)
{
	std::stringstream buffer;
	std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
	std::cout << std::fixed << std::setprecision(15) << d << std::endl;
	std::string text = buffer.str();

	wxString txt = text;
	return txt;
}
#pragma endregion
