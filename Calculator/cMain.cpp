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
	result = new wxListBox(this, 30092, wxPoint(270, 55), wxSize(150, 30));
	result->Enable(false);

	//DROP DOWN MENU
	wxArrayString Choices;
	Choices.Add("Hexidecimal");
	Choices.Add("Binary");
	Choices.Add("Decimal");
	BinaryDropDown = new wxChoice(this, 103, wxPoint(35, 60), wxSize(100, 70), Choices, 0, wxDefaultValidator);


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
	Calc->AppendText("0");
}


void cMain::num_One_btn(wxCommandEvent& evt) {
	Calc->AppendText("1");
}


void cMain::num_Two_btn(wxCommandEvent& evt) {
	Calc->AppendText("2");
}


void cMain::num_Three_btn(wxCommandEvent& evt) {
	Calc->AppendText("3");
}


void cMain::num_Four_btn(wxCommandEvent& evt) {
	Calc->AppendText("4");
}


void cMain::num_Five_btn(wxCommandEvent& evt) {
	Calc->AppendText("5");
}


void cMain::num_Six_btn(wxCommandEvent& evt) {
	Calc->AppendText("6");
}


void cMain::num_Seven_btn(wxCommandEvent& evt) {
	Calc->AppendText("7");
}


void cMain::num_Eight_btn(wxCommandEvent& evt) {
	Calc->AppendText("8");
}


void cMain::num_Nine_btn(wxCommandEvent& evt) {
	Calc->AppendText("9");
}

#pragma endregion

#pragma region Main Operations

void cMain::toNegative(wxCommandEvent& evt) {
	Calc->AppendText("-");
}
void cMain::toDecimal(wxCommandEvent& evt) {
	Calc->AppendText(".");
}
void cMain::all_Clear_btn(wxCommandEvent& evt) {
	Calc->Clear();
}
void cMain::plus_btn(wxCommandEvent& evt) {
	Calc->AppendText("+");
}
void cMain::minus_btn(wxCommandEvent& evt) {
	Calc->AppendText("-");
}
void cMain::divide_btn(wxCommandEvent& evt) {
	Calc->AppendText("/");
}
void cMain::equals_btn(wxCommandEvent& evt) {
	Calc->AppendText("=");
}
void cMain::multiplication(wxCommandEvent& evt) {
	Calc->AppendText("x");
}

void cMain::modular(wxCommandEvent& evt) {
	Calc->AppendText("%");
}


#pragma endregion

#pragma region Extra Operations

void cMain::pie(wxCommandEvent& evt) {
	Calc->AppendText("3.14");
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
	Calc->AppendText("C");
}

void cMain::per1_Click(wxCommandEvent& evt) {
	Calc->AppendText("(");
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
	return stod(string(str));
}

wxString cMain::DoubleToString(double d)
{
	stringstream buffer;
	streambuf* old = std::cout.rdbuf(buffer.rdbuf());
	cout << fixed << setprecision(15) << d << std::endl;
	string text = buffer.str();

	wxString txt = text;
	return txt;
}
#pragma endregion
