/***********************************************************************************************

* Name :       Chunduri vamsi
* File name:   prog9.h

************************************************************************************************/


//this file contains the headder files required for the program.
#ifndef de
#define de
#include<iostream>
#include<string>
#include<stdlib.h>
#include<stack>
#include<iomanip>
using namespace std;
//function prototype to process  the token
void process_token(const string&, stack<double>&);
//function prototype to get the number.
double getNumber(const char&, const string&, unsigned&, const bool&);
//function protype to convert the string to double.
double stringToDouble(const string&);
//function prototype to check theunary sign.
bool unarySign(const char&, const string&, const unsigned&);
//functio prototype to chck for a valid operator
bool isValidOperator(const char&);
//function prototype for operation.
double operation(const char&, double&, double&);
//function prototype for popstack.
double popStack(stack<double>&);
//function prototype empty stack.
void emptyStack(stack<double>&);
//function prototype for print result.
void printResult(stack<double>&);
//function prototype for float point.
bool floatPoint(const char&, string&, unsigned&);


#endif
