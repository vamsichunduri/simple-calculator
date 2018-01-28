/***********************************************************************************************

* Name :       Chunduri vamsi
* File name:   prog9.cc

************************************************************************************************/
//this file contains the program to work as  calculator.
#include "prog9.h"
/*****************************************************************************************************************************************************

Function Name     : process_token.
Parameters 		  : string&,stack<double>&
return 			  : no return.
Description		  : Thi function is used to process the given token by changing the number to decimal and storing them in a stack and performing the operations.

******************************************************************************************************************************************************/
void process_token(const string& token, stack<double>& s)
{
	//declaring the flag variable.
	bool FloatPointFlag = false;
	for (unsigned i = 0; i < token.length(); i++)
	{
		//checking for the + and - signs.
		if ((token[i] == '+' || token[i] == '-')&&(i!=token.length()-1)&&((isdigit(token[i+1]))||(token[i+1]=='.')))
		{
			//checking for the unary sign.
			if ((unarySign(token[i], token, i)))
			{
				//a variable to store sign.
				double p = 1;
				if (token[i] == '+') p = 1;
				if (token[i] == '-') p = -1;
				//incrementing i to get net character.
				i++;
				//calling the getnumber to get the number form a string.
				double dd = getNumber(token[i], token, i, FloatPointFlag);
				
				if (dd > 0 || dd < 0)
				{
					//pushing the element into stack.
					s.push(dd*p);
				}
				//changing the sign variable.
				p = 1;

			}
		}
		//checking for a dot.
		 else if (token[i] == '.')
		{
			//calling the getnumber to get the number form a string.
			double d = getNumber(token[i], token, i, true);
			if (d > 0 || d < 0)
			{
				//pushing the element into stack.
				s.push(d);
			}
		}
		//checking for a digit.
		 else if (isdigit(token[i]))
		{
			//calling the getnumber to get the number form a string.
			double d = getNumber(token[i], token, i, FloatPointFlag);
			if (d > 0 || d < 0) {
				//pushing the element into stack.
				s.push(d);
			}
		}
		//checking for a valid list of operators.
		 else  if (isValidOperator(token[i]))
		{
			//checking the size of the stack.
			if (s.size() > 1)
			{
				//getting the elements from stack and storing them in a variable.
				double d1 = popStack(s);
				double d2 = popStack(s);
				//calling the operation function to perform operation.
				double d3 = operation(token[i], d2, d1);
				//pushing the element into the stack.
				s.push(d3);
				}
				
			else 
			{
				//calling the emptyStack function.
				   emptyStack(s);
			}	
		}
		//checking for c character.
		 else if (token[i] == 'c')
		 {
			 //calling the emptyStack function.
			 emptyStack(s);
		 }
		 //checking for =
		 else if (token[i] == '=')
		 {
			 //calling the printResult to display result.
			 printResult(s);
		 }
	}
}
/*****************************************************************************************************************************************************

Function Name     : popStack.
Parameters 		  : stack<double>&
return 			  : double.
Description		  : This function is used to pop the top element from the stack.

******************************************************************************************************************************************************/
	double popStack(stack<double>& s)
	{
		//checking for the stack empty or not.
		if (!s.empty())
		{
			//getting the top element of the stack.
			double d = s.top();
			//removing the top element from the stack.
			 s.pop();
			 return d;
		}
        return 0;  
	}
/*****************************************************************************************************************************************************

Function Name     : unary_Sign
Parameters 		  : char&,string&,unsigned&
return 			  : bool.
Description		  : This function is used to check for the unary sign.

******************************************************************************************************************************************************/
	bool unarySign(const char& c, const string& token, const unsigned& i)
	{
		//validating the character is a unary sign or not.
		if ( (isdigit(token[i + 1]) || token[i + 1] == '.' ||isdigit(c)) &&(i!=token.length()-1))
			return true;
		else
			return false;
	}
/*****************************************************************************************************************************************************

Function Name     : getNumber.
Parameters 		  : char&,string&,unsigned&,bool&.
return 			  : double.
Description		  : This function is used to parse the number from a given string.

******************************************************************************************************************************************************/
	double getNumber(const char& c, const string& token, unsigned& i, const bool& FloatPointFlag)
	{
		//checking th flag.
		if ((!FloatPointFlag)||c)
		{
		a:
		   //variables to get the required number.
			int start = i, end = 0;
			int dot = 0;
			//checking for the end of the string.
			while (i < token.length())
			{
				//validating the given character.
				if (isdigit(token[i]) || token[i] == '.' || token[i] == '!')
				{
					//checking for the dot.
					if (token[i] == '.') 
					{
						dot++;
					}
						end++;
					i++;
				}
				else 
				{
					i--;
					//breaking the loop.
					break;
				}
			}
				//checking for the number of dots.
				if (dot > 1) 
				{
					//displaying the error on std error.
				cerr << "error: number  "<< token.substr(start, end + 1) <<"  is invalid"<< endl;
				return 0; 
				}
				//checking for the ! character.
			else if (token[end - 1] == '!') 
			{
				//displaying the error on std error.
				cerr << "error: character '!' is invalid"<<endl; 
				return 0;
				}
				//calling the stringToDouble to convert the string to double.
			return stringToDouble(token.substr(start, end + 1));
		}
		//checking the flag.
		else if(FloatPointFlag == true)
		{
			goto a;
		}
     return 0;
	}
/*****************************************************************************************************************************************************

Function Name     : stringToDouble
Parameters 		  : string&
return 			  : double.
Description		  : This function is used to convert the string to double.

******************************************************************************************************************************************************/
	double stringToDouble(const string& tok)
	{
		char* pt;
		//returning the converted double value.
		return strtod(tok.c_str(), &pt);
	}
/*****************************************************************************************************************************************************

Function Name     : isValidOperator
Parameters 		  : char&
return 			  : bool.
Description		  : This function is used to check for the valid operator.

******************************************************************************************************************************************************/
	bool isValidOperator(const char& c)
	{
		//validating the operators.
		if ((c == '/') || (c == '+') || (c == '-') || (c == '*'))
			return true;
		else
			return false;
	}
/*****************************************************************************************************************************************************

Function Name     : emptyStack
Parameters 		  : stack<double>&
return 			  : no return.
Description		  : This function is used to empty the stack.

******************************************************************************************************************************************************/	
	void emptyStack(stack<double>& s)
	{
		if(s.empty())
		{
			cerr << "error: stack is empty"<<endl;
		}
		
		//checking the stack empty or not.
		while (!s.empty())
		{
			s.pop();
		}
	}
/*****************************************************************************************************************************************************

Function Name     : printResult
Parameters 		  : stack<double>&
return 			  : no return.
Description		  : This function is used to print the result when = had encountered.

******************************************************************************************************************************************************/
	void printResult(stack<double>& s)
	{
		//checking for the stack is empty or not.
		if (!s.empty())
		{
			//printing the result.
			cout << setw(8)<<fixed<<setprecision(2);
			cout<< s.top() << endl;
		}
		else
		{
			cout << "stack empty error" << endl;
		}
	}
/*****************************************************************************************************************************************************

Function Name     : floatPoint
Parameters 		  : char&,string&,unsigned&
return 			  : bool.
Description		  : This function is used to check for the float point.

******************************************************************************************************************************************************/
bool floatPoint(const char& c, string& token, unsigned& i)
{
 unsigned j =i;
 //checking for the valid float points.
    if(c=='.'&&(j!=token.length()-1))
	return true;
   else
    return false;
}
/*****************************************************************************************************************************************************

Function Name     : operation.
Parameters 		  : char&,double&,double&
return 			  : double.
Description		  : This function is used to perform the operation depending on the caaracter.

******************************************************************************************************************************************************/
double operation(const char& c, double& x, double& y)
{
	//checking for the character.
	switch (c)
	{
		//addition.
	case '+': return x + y;
	//subtraction.
	case '-': return x - y;
	//division.
	case '/': return x / y;
	//multiplication.
	case '*': return x*y;
	}
return 0;
}
// a global variable which is used to display error.
int g=0;
int main()
{
	//creating a stack object.
	stack<double> s;
	//declaring a string named token.
	string token;
	//reading the string untill eno fo file.
	while (cin >> token)
	{
		//calling the function to process the token.
		process_token(token, s);
	}
	return 0;
}
