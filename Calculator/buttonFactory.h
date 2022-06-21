#pragma once
#include "wx/wx.h"
#include <vector>


class cMain;

class buttonFactory
{
public:
#pragma region buttons
	//NUMBERS
	wxButton* num_Zero;
	wxButton* num_One;
	wxButton* num_Two;
	wxButton* num_Seven;
	wxButton* num_Four;
	wxButton* num_Eight;
	wxButton* num_Five;
	wxButton* num_Nine;
	wxButton* num_Six;
	wxButton* num_Three;

	//MAIN OPERATIONS
	wxButton* neg;
	wxButton* dot;
	wxButton* mod;
	wxButton* all_Clear;
	wxButton* plus;
	wxButton* minus;
	wxButton* divide;
	wxButton* equals;
	wxButton* times;

	//EXTRA OPERATIONS
	wxButton* pi;
	wxButton* sin;
	wxButton* tan;
	wxButton* cos;
	wxButton* less_Than;
	wxButton* greater_Than;
	wxButton* SquareRoot;
	wxButton* exponent;
	wxButton* clear;
	wxButton* per1;
	wxButton* per2;

#pragma endregion

	
public:
#pragma region num functions
	wxButton* get_Zero(wxWindow* parent, cMain* evt);
	wxButton* get_One(wxWindow* parent, cMain* evt);
	wxButton* get_Two(wxWindow* parent, cMain* evt);
	wxButton* get_Three(wxWindow* parent, cMain* evt);
	wxButton* get_Four(wxWindow* parent, cMain* evt);
	wxButton* get_Five(wxWindow* parent, cMain* evt);
	wxButton* get_Six(wxWindow* parent, cMain* evt);
	wxButton* get_Seven(wxWindow* parent, cMain* evt);
	wxButton* get_Eight(wxWindow* parent, cMain* evt);
	wxButton* get_Nine(wxWindow* parent, cMain* evt);

#pragma endregion

#pragma region Main Operation Functions
	wxButton* get_Dot(wxWindow* parent, cMain* evt);
	wxButton* get_toNeg(wxWindow* parent, cMain* evt);
	wxButton* get_Mod(wxWindow* parent, cMain* evt);
	wxButton* get_AC(wxWindow* parent,cMain* evt);
	wxButton* get_Div(wxWindow* parent, cMain* evt);
	wxButton* get_Plus(wxWindow* parent, cMain* evt);
	wxButton* get_Times(wxWindow* parent, cMain* evt);
	wxButton* get_Minus(wxWindow* parent, cMain* evt);
	wxButton* get_Equals(wxWindow* parent, cMain* evt);
#pragma endregion

#pragma region Extra operation functions
	wxButton* get_Pi(wxWindow* parent, cMain* evt);
	wxButton* get_Sin(wxWindow* parent, cMain* evt);
	wxButton* get_Tan(wxWindow* parent, cMain* evt);
	wxButton* get_LessThan(wxWindow* parent, cMain* evt);
	wxButton* get_Squared(wxWindow* parent, cMain* evt);
	wxButton* get_Cos(wxWindow* parent, cMain* evt);
	wxButton* get_Exponent(wxWindow* parent, cMain* evt);
	wxButton* get_GreaterThan(wxWindow* parent, cMain* evt);
	wxButton* get_Per1(wxWindow* parent, cMain* evt);
	wxButton* get_Per2(wxWindow* parent, cMain* evt);
	wxButton* get_Clear(wxWindow* parent, cMain* evt);
#pragma endregion



};

