#pragma once

//This header file contains some definitions to be used all over the application

//All possible actions
enum ActionType
{
	ADD,
	ADD_Buff,			//Add 1-input Buffer gate
	ADD_INV,			//Add 1-input Inverter gate
	ADD_AND_GATE_2,		//Add 2-input AND gate
	ADD_OR_GATE_2,		//Add 2-input OR gate
	ADD_NAND_GATE_2,	//Add 2-input NAND gate
	ADD_NOR_GATE_2,		//Add 2-input NOR gate
	ADD_XOR_GATE_2,		//Add 2-input XOR gate
	ADD_XNOR_GATE_2,	//Add 2-input XNOR gate
	ADD_AND_GATE_3,		//Add 3-input AND gate
	ADD_NOR_GATE_3,		//Add 3-input NOR gate
	ADD_XOR_GATE_3,		//Add 3-input XOR gate
	ADD_Switch,			//Add Switch
	ADD_LED,			//Add LED
	ADD_CONNECTION,		//Add Wire Connection

	ADD_Label,			//Add Label to a Component, a Connection
	EDIT_Label,			//Edit Label of a Component, a Connection

	Create_TruthTable,	//Create Truth Table of the Circuit

	Change_Switch,		//Change Switch Status in Simulation Mode

	SELECT,	            //Select a Component, a Connection
	DEL,                //Delete a Component, a Connection
	MOVE,		        //Move a Component, a Connection

	COPY,               //Copy a Component
	CUT,                //Cut a Component
	PASTE,              //Paste a Component

	SAVE,		        //Save the whole Circuit to a file
	LOAD,		        //Load a Circuit from a file

	UNDO,		        //Undo the last Action preformed
	REDO,		        //Redo the last Action canceled

	DSN_MODE,	        //Switch to Design mode
	SIM_MODE,	        //Switch to Simulation mode

	EXIT,               //Exit the application

	STATUS_BAR,		    //A click on the status bar
	DSN_TOOL	        //A click on an empty place in the design tool bar

};

//Possible Status for the pin
enum STATUS
{
	LOW,
	HIGH
};

//Modes of operation
enum  MODE
{
	DESIGN,
	SIMULATION
};

//The items of the design menu (you should add more items)
enum DsgnMenuItem
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_AND2,		//AND gate item in menu
	ITM_OR2,		//OR gate item in menu

	ITM_EXIT,		//Exit item
	//TODO: Add more items names here

	ITM_DSN_CNT		//no. of design menu items ==> This should be the last line in this enum

};

//The items of the simulation menu (you should add more items)
enum SimMenuItem
{
	//Note: Items are ordered here as they appear in menu
	ITM_SIM,	//Simulate menu item
	ITM_TRUTH,	//Truth table menu item

	//TODO:Add more items names here

	ITM_SIM_CNT		//no. of simulation menu items ==> This should be the last line in this enum

};

//Assume fan out is 5 for now it can be read from the user or can be predefined as const
enum FANOUT
{
	AND2_FANOUT = 5	//Default fan out of 2-input AND gate
};

class GraphicsInfo
{
private:
	int X, Y, Width, Height;
public:
    GraphicsInfo(int X, int Y, int Width, int Height) {SetX(X); SetY(Y); SetWidth(Width); SetHeight(Height);}
    int GetX() {return X;}
    int GetY() {return Y;}
    int GetWidth() {return Width;}
    int GetHeight() {return Height;}
    void SetX(int X) {this->X = (X<0)?0:X;}
    void SetY(int Y) {this->Y = (Y<0)?0:Y;}
    void SetWidth(int Width) {this->Width = (Width<0)?0:Width;}
    void SetHeight(int Height) {this->Height = (Height<0)?0:Height;}
    bool Contains(int x, int y) {return (x > X && x < X+Width && y > Y && y < Y+Height);}
};

#ifndef NULL
#define NULL 0
#endif
