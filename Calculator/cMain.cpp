#include "cMain.h"
wxBEGIN_EVENT_TABLE(cMain, wxFrame)

wxEND_EVENT_TABLE()

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(210, 200), wxSize(470, 470))
{
	SetMinSize(wxSize(470, 470));
	SetMaxSize(wxSize(470, 470));

	//TEXT CTRL
	Calc = new wxTextCtrl(this, 102,"", wxPoint(35, 10), wxSize(385, 40), wxTE_RIGHT | wxTE_BESTWRAP);
	Calc->Enable(false);
	wxFont calc_font(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_SLANT, wxFONTWEIGHT_NORMAL,false);
	Calc->SetFont(calc_font);

	//RESULT BOX
	result = new wxListBox(this, 30092, wxPoint(270, 55), wxSize(150, 30));
	result->Enable(false);

	//DROP DOWN MENU
	wxArrayString Choices;
	Choices.Add("Hexidecimal");
	Choices.Add("Binary");
	Choices.Add("Decimal");
	BinaryDropDown = new wxChoice(this, 103, wxPoint(35, 60), wxSize(100, 70),Choices,0, wxDefaultValidator);


	//Num buttons
	num_Zero = new wxButton(this, 112, "0", wxPoint(230, 350), wxSize(60, 60));
	num_Zero->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::num_Zero_btn, this);

	num_One = new wxButton(this, 112, "1", wxPoint(165, 285), wxSize(60, 60));
	num_One->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::num_One_btn, this);

	num_Two = new wxButton(this, 112, "2", wxPoint(230, 285), wxSize(60, 60));
	num_Two->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::num_Two_btn, this);

	num_Three = new wxButton(this, 112, "3", wxPoint(295, 285), wxSize(60, 60));
	num_Three->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::num_Three_btn, this);

	num_Four = new wxButton(this, 112, "4", wxPoint(165, 220), wxSize(60, 60));
	num_Four->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::num_Four_btn, this);

	num_Five = new wxButton(this, 112, "5", wxPoint(230, 220), wxSize(60, 60));
	num_Five->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::num_Five_btn, this);

	num_Six = new wxButton(this, 112, "6", wxPoint(295, 220), wxSize(60, 60));
	num_Six->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::num_Six_btn, this);

	num_Seven = new wxButton(this, 112, "7", wxPoint(165, 155), wxSize(60, 60));
	num_Seven->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::num_One_btn, this);

	num_Eight = new wxButton(this, 112, "8", wxPoint(230, 155), wxSize(60, 60));
	num_Eight->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::num_Eight_btn, this);

	num_Nine = new wxButton(this, 112, "9", wxPoint(295, 155), wxSize(60, 60));
	num_Nine->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::num_Nine_btn, this);


	//MAIN OPERATION BUTTONS
	dot = new wxButton(this, 112, "•", wxPoint(165, 350), wxSize(60, 60));
	dot->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::toDecimal, this);

	neg = new wxButton(this, 108, "+/-", wxPoint(35, 350), wxSize(60, 60));
	neg->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::toNegative, this);

	mod = new wxButton(this, 112, "%", wxPoint(100, 350), wxSize(60, 60));
	mod->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::modular, this);

	all_Clear = new wxButton(this, 112, "AC", wxPoint(360, 90), wxSize(60, 60));
	all_Clear->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::all_Clear_btn, this);

	divide = new wxButton(this, 112, "÷", wxPoint(360, 155), wxSize(60, 60));
	divide->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::divide_btn, this);

	plus = new wxButton(this, 112, "+", wxPoint(360, 350), wxSize(60, 60));
	plus->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::plus_btn, this);

	times = new wxButton(this, 112, "x", wxPoint(360, 220), wxSize(60, 60));
	times->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::multiplication, this);

	minus = new wxButton(this, 112, "-", wxPoint(360, 285), wxSize(60, 60));
	minus->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::minus_btn, this);

	equals = new wxButton(this, 112, "=", wxPoint(295, 350), wxSize(60, 60));
	equals->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::equals_btn, this);

	//EXTRA OPERATION BUTTONS
	pi = new wxButton(this, 104,L"\u03C0", wxPoint(35, 90), wxSize(60, 60));
	pi->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::pie, this);

	sin = new wxButton(this, 105, "Sin", wxPoint(35, 155), wxSize(60, 60));
	sin->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::sin_Button, this);

	tan = new wxButton(this, 106, "Tan", wxPoint(35, 220), wxSize(60, 60));
	tan->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::tan_Button, this);

	less_Than = new wxButton(this, 107, L"\u2264", wxPoint(35, 285), wxSize(60, 60));
	less_Than->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::less_Than_btn, this);

	SquareRoot = new wxButton(this, 109, L"\u221a", wxPoint(100, 90), wxSize(60, 60));
	SquareRoot->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::squareRoot_btn, this);

	cos = new wxButton(this, 110, "Cos", wxPoint(100, 155), wxSize(60, 60));
	cos->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::cos_Button, this);

	exponent = new wxButton(this, 112, "x²", wxPoint(100, 220), wxSize(60, 60));
	exponent->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::exponent_btn, this);

	greater_Than = new wxButton(this, 112, L"\u2265", wxPoint(100, 285), wxSize(60, 60));
	greater_Than->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::greater_Than_btn, this);

	per1 = new wxButton(this, 112, "(", wxPoint(165, 90), wxSize(60, 60));
	per1->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::per1_Click, this);

	per2 = new wxButton(this, 112, ")", wxPoint(230, 90), wxSize(60, 60));
	per2->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::per2_Click, this);

	clear = new wxButton(this, 112, "C", wxPoint(295, 90), wxSize(60, 60));
	clear->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::single_clear, this);
}

cMain::~cMain()
{

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
	Calc->AppendText(L"\u221a");
}


void cMain::exponent_btn(wxCommandEvent& evt) {
	Calc->AppendText("x²");
}

void cMain::single_clear(wxCommandEvent& evt) {
	Calc->AppendText("C");
}


void cMain::per1_Click(wxCommandEvent& evt) {
	Calc->AppendText("(");
}


void cMain::per2_Click(wxCommandEvent& evt) {
	Calc->AppendText(")");
}

#pragma endregion
