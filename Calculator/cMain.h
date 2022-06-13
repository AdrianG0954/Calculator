#pragma once
#include "wx/wx.h"
#include "SplitButton.h"
class cMain : public wxFrame
{
public:
	cMain();
	~cMain();

public:
	wxChoice* BinaryDropDown;
	wxTextCtrl* Calc;

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




	//NUMBER CLICK EVENTS
	void num_Zero_btn(wxCommandEvent& evt);
	void num_One_btn(wxCommandEvent& evt);
	void num_Two_btn(wxCommandEvent& evt);
	void num_Three_btn(wxCommandEvent& evt);
	void num_Four_btn(wxCommandEvent& evt);
	void num_Five_btn(wxCommandEvent& evt);
	void num_Six_btn(wxCommandEvent& evt);
	void num_Seven_btn(wxCommandEvent& evt);
	void num_Eight_btn(wxCommandEvent& evt);
	void num_Nine_btn(wxCommandEvent& evt);


	//MAIN OPERATIONS
	void toNegative(wxCommandEvent& evt);
	void toDecimal(wxCommandEvent& evt);
	void all_Clear_btn(wxCommandEvent& evt);
	void plus_btn(wxCommandEvent& evt);
	void minus_btn(wxCommandEvent& evt);
	void divide_btn(wxCommandEvent& evt);
	void equals_btn(wxCommandEvent& evt);
	void multiplication(wxCommandEvent& evt);
	void modular(wxCommandEvent& evt);

	//EXTRA OPERATIONS
	void pie(wxCommandEvent& evt);
	void sin_Button(wxCommandEvent& evt);
	void tan_Button(wxCommandEvent& evt);
	void cos_Button(wxCommandEvent& evt);
	void less_Than_btn(wxCommandEvent& evt);
	void greater_Than_btn(wxCommandEvent& evt);
	void squareRoot_btn(wxCommandEvent& evt);
	void exponent_btn(wxCommandEvent& evt);
	void single_clear (wxCommandEvent& evt);
	void per1_Click(wxCommandEvent& evt);
	void per2_Click(wxCommandEvent& evt);

	

	wxDECLARE_EVENT_TABLE();

};

