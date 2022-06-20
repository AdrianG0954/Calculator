#include "cMain.h"
#include "wx/wx.h"
#include "buttonFactory.h"


#pragma region Get 0-9 Buttons

wxButton* buttonFactory::get_Zero(wxWindow* parent, cMain* evt) {
	num_Zero = new wxButton(parent, wxID_ANY, "0", 
		wxPoint(230, 350), wxSize(60, 60));

	num_Zero->Bind(wxEVT_COMMAND_BUTTON_CLICKED,
		&cMain::num_Zero_btn, evt);

	return num_Zero;
}

wxButton* buttonFactory::get_One(wxWindow* parent, cMain* evt) {
	num_One = new wxButton(parent, 112, "1", wxPoint(165, 285),
		wxSize(60, 60));

	num_One->Bind(wxEVT_COMMAND_BUTTON_CLICKED,
		&cMain::num_One_btn, evt);

	return num_One;
}

wxButton* buttonFactory::get_Two(wxWindow* parent, cMain* evt) {
	num_Two = new wxButton(parent, 112, "2",
		wxPoint(230, 285), wxSize(60, 60));

	num_Two->Bind(wxEVT_COMMAND_BUTTON_CLICKED,
		&cMain::num_Two_btn, evt);

	return num_Two;
}

wxButton* buttonFactory::get_Three(wxWindow* parent, cMain* evt) {
	num_Three = new wxButton(parent, 112, "3",
		wxPoint(295, 285), wxSize(60, 60));

	num_Three->Bind(wxEVT_COMMAND_BUTTON_CLICKED,
		&cMain::num_Three_btn, evt);

	return num_Three;
}

wxButton* buttonFactory::get_Four(wxWindow* parent, cMain* evt) {
	num_Four = new wxButton(parent, 112, "4",
		wxPoint(165, 220), wxSize(60, 60));

	num_Four->Bind(wxEVT_COMMAND_BUTTON_CLICKED,
		&cMain::num_Four_btn, evt);

	return num_Four;
}

wxButton* buttonFactory::get_Five(wxWindow* parent, cMain* evt) {
	num_Five = new wxButton(parent, 112, "5",
		wxPoint(230, 220), wxSize(60, 60));

	num_Five->Bind(wxEVT_COMMAND_BUTTON_CLICKED,
		&cMain::num_Five_btn, evt);

	return num_Five;
}

wxButton* buttonFactory::get_Six(wxWindow* parent, cMain* evt) {
	num_Six = new wxButton(parent, 112, "6",
		wxPoint(295, 220), wxSize(60, 60));

	num_Six->Bind(wxEVT_COMMAND_BUTTON_CLICKED,
		&cMain::num_Six_btn, evt);

	return num_Six;
}

wxButton* buttonFactory::get_Seven(wxWindow* parent, cMain* evt) {
	num_Seven = new wxButton(parent, 112, "7",
		wxPoint(165, 155), wxSize(60, 60));

	num_Seven->Bind(wxEVT_COMMAND_BUTTON_CLICKED,
		&cMain::num_Seven_btn, evt);

	return num_Seven;
}

wxButton* buttonFactory::get_Eight(wxWindow* parent, cMain* evt) {
	num_Eight = new wxButton(parent, 112, "8",
		wxPoint(230, 155), wxSize(60, 60));

	num_Eight->Bind(wxEVT_COMMAND_BUTTON_CLICKED,
		&cMain::num_Eight_btn, evt);

	return num_Eight;
}

wxButton* buttonFactory::get_Nine(wxWindow* parent, cMain* evt) {
	num_Nine = new wxButton(parent, 112, "9",
		wxPoint(295, 155), wxSize(60, 60));

	num_Nine->Bind(wxEVT_COMMAND_BUTTON_CLICKED,
		&cMain::num_Nine_btn, evt);

	return num_Nine;
}

#pragma endregion

#pragma region Main operation Buttons

wxButton* buttonFactory::get_Dot(wxWindow* parent, cMain* evt) {
	dot = new wxButton(parent, 112, "•",
		wxPoint(165, 350), wxSize(60, 60));

	dot->Bind(wxEVT_COMMAND_BUTTON_CLICKED,
		&cMain::toDecimal, evt);

	return dot;
}

wxButton* buttonFactory::get_toNeg(wxWindow* parent, cMain* evt) {
	neg = new wxButton(parent, 108, "+/-",
		wxPoint(35, 350), wxSize(60, 60));

	neg->Bind(wxEVT_COMMAND_BUTTON_CLICKED,
		&cMain::toNegative, evt);

	return neg;
}

wxButton* buttonFactory::get_Mod(wxWindow* parent, cMain* evt) {
	mod = new wxButton(parent, 112, "%",
		wxPoint(100, 350), wxSize(60, 60));

	mod->Bind(wxEVT_COMMAND_BUTTON_CLICKED,
		&cMain::modular, evt);

	return mod;
}

wxButton* buttonFactory::get_AC(wxWindow* parent,cMain* evt) {
	all_Clear = new wxButton(parent, 112, "AC",
		wxPoint(360, 90), wxSize(60, 60));

	all_Clear->Bind(wxEVT_COMMAND_BUTTON_CLICKED,
		&cMain::all_Clear_btn, evt);

	return all_Clear;
}

wxButton* buttonFactory::get_Div(wxWindow* parent, cMain* evt) {
	divide = new wxButton(parent, 112, "÷",
		wxPoint(360, 155), wxSize(60, 60));

	divide->Bind(wxEVT_COMMAND_BUTTON_CLICKED,
		&cMain::divide_btn, evt);

	return divide;
}

wxButton* buttonFactory::get_Plus(wxWindow* parent, cMain* evt) {
	plus = new wxButton(parent, 112, "+",
		wxPoint(360, 350), wxSize(60, 60));

	plus->Bind(wxEVT_COMMAND_BUTTON_CLICKED,
		&cMain::plus_btn, evt);

	return dot;
}

wxButton* buttonFactory::get_Times(wxWindow* parent, cMain* evt) {
	times = new wxButton(parent, 112, "x",
		wxPoint(360, 220), wxSize(60, 60));

	times->Bind(wxEVT_COMMAND_BUTTON_CLICKED,
		&cMain::multiplication, evt);

	return times;
}

wxButton* buttonFactory::get_Minus(wxWindow* parent, cMain* evt) {
	minus = new wxButton(parent, 112, "-",
		wxPoint(360, 285), wxSize(60, 60));

	minus->Bind(wxEVT_COMMAND_BUTTON_CLICKED,
		&cMain::minus_btn, evt);

	return minus;
}

wxButton* buttonFactory::get_Equals(wxWindow* parent, cMain* evt) {
	equals = new wxButton(parent, 112, "=",
		wxPoint(295, 350), wxSize(60, 60));

	equals->Bind(wxEVT_COMMAND_BUTTON_CLICKED,
		&cMain::equals_btn, evt);

	return equals;
}
#pragma endregion

#pragma region Extra Operations

wxButton* buttonFactory::get_Pi(wxWindow* parent, cMain* evt) {
	pi = new wxButton(parent, 104, L"\u03C0",
		wxPoint(35, 90), wxSize(60, 60));

	pi->Bind(wxEVT_COMMAND_BUTTON_CLICKED,
		&cMain::pie, evt);

	return pi;
}

wxButton* buttonFactory::get_Sin(wxWindow* parent, cMain* evt) {
	sin = new wxButton(parent, 105, "Sin",
		wxPoint(35, 155), wxSize(60, 60));

	sin->Bind(wxEVT_COMMAND_BUTTON_CLICKED,
		&cMain::sin_Button, evt);

	return sin;
}

wxButton* buttonFactory::get_Tan(wxWindow* parent, cMain* evt) {
	tan = new wxButton(parent, 106, "Tan",
		wxPoint(35, 220), wxSize(60, 60));

	tan->Bind(wxEVT_COMMAND_BUTTON_CLICKED,
		&cMain::tan_Button, evt);

	return tan;
}

wxButton* buttonFactory::get_LessThan(wxWindow* parent, cMain* evt) {
	less_Than = new wxButton(parent, 107, L"\u2264",
		wxPoint(35, 285), wxSize(60, 60));

	less_Than->Bind(wxEVT_COMMAND_BUTTON_CLICKED,
		&cMain::less_Than_btn, evt);

	return less_Than;
}

wxButton* buttonFactory::get_Squared(wxWindow* parent, cMain* evt) {
	SquareRoot = new wxButton(parent, 109, L"\u221a",
		wxPoint(100, 90), wxSize(60, 60));

	SquareRoot->Bind(wxEVT_COMMAND_BUTTON_CLICKED,
		&cMain::squareRoot_btn, evt);

	return SquareRoot;
}

wxButton* buttonFactory::get_Cos(wxWindow* parent, cMain* evt) {
	cos = new wxButton(parent, 110, "Cos",
		wxPoint(100, 155), wxSize(60, 60));

	cos->Bind(wxEVT_COMMAND_BUTTON_CLICKED,
		&cMain::cos_Button, evt);

	return cos;
}

wxButton* buttonFactory::get_Exponent(wxWindow* parent, cMain* evt) {
	exponent = new wxButton(parent, 112, "x²",
		wxPoint(100, 220), wxSize(60, 60));

	exponent->Bind(wxEVT_COMMAND_BUTTON_CLICKED,
		&cMain::exponent_btn, evt);

	return exponent;
}

wxButton* buttonFactory::get_GreaterThan(wxWindow* parent, cMain* evt) {
	greater_Than = new wxButton(parent, 112, L"\u2265",
		wxPoint(100, 285), wxSize(60, 60));

	greater_Than->Bind(wxEVT_COMMAND_BUTTON_CLICKED,
		&cMain::greater_Than_btn, evt);

	return greater_Than;
}

wxButton* buttonFactory::get_Per1(wxWindow* parent, cMain* evt) {
	per1 = new wxButton(parent, 112, "Binary",
		wxPoint(165, 90), wxSize(60, 60));

	per1->Bind(wxEVT_COMMAND_BUTTON_CLICKED,
		&cMain::per1_Click, evt);

	return per1;
}

wxButton* buttonFactory::get_Per2(wxWindow* parent, cMain* evt) {
	per2 = new wxButton(parent, 112, "Hexidecimal",
		wxPoint(230, 90), wxSize(60, 60));

	per2->Bind(wxEVT_COMMAND_BUTTON_CLICKED,
		&cMain::per2_Click, evt);

	return per2;
}

wxButton* buttonFactory::get_Clear(wxWindow* parent, cMain* evt) {
	clear = new wxButton(parent, 112, "C",
		wxPoint(295, 90), wxSize(60, 60));

	clear->Bind(wxEVT_COMMAND_BUTTON_CLICKED,
		&cMain::single_clear, evt);

	return clear;
}



#pragma endregion

