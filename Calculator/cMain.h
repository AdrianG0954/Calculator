#pragma once
#include "wx/wx.h"
#include "buttonFactory.h"
class cMain : public wxFrame
{
public:
	cMain();

public:
	//DROP DOWN AND TEXT CONTROL
	wxChoice* BinaryDropDown;
	wxTextCtrl* Calc;
	wxListBox* result;

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

