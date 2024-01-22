#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

// libraries from author of the book

#include<std_lib_facilities.h>

// Description as in commit:
// ChapterSix is about process of 'writing a program': since general idea, to analysis, creating a project, 
// implementing, testing, again creating and adapting project and at the end again implementing and so on
// until satysfying level of functionality and efficiency is achieved.

// This chapter represents ideas described above with a project and parts of implementation of a simple calculator 
// that takes values and type of operation in a one line.

#define FIRST		0	// first, simple prototype of a calculator: only '-' and '+' are handled
#define SECOND		0	// second prototype, using 'switch' instead of 'if' and using few expressions
#define THIRD		0	// to solve above problem (lack of priority) we will use user defined type: 'Token'
#define FOURTH		0	// implementing a calculator with tokens described above
#define FIFTH		0	// simple GRAMMAR of expressions to parse and analyze syntax of an input (parser and syntax analyzer)
#define SIXTH		0	// attempt to change grammar and its rules into functions and code			 //(JUST COMMENTS, NO CODE)	
#define SEVENTH		0	// second attempt to make grammar rules happen 
#define EIGHTH		0	// third attempt to calculator as an token accepting and handling object according to our grammar rules
#define NINTH		0	// few changes of above code (without double check of characters: '-', '+') 
#define TENTH		0	// handling elements of our grammar (element is 'term' in case of our grammar) 
#define ELEVENTH	0	// function to handle elementary factors entered to the calculator ( numbers and brackets:'()' ) 
#define TWELFTH		0	// modification of a function expression() in order to put back tokens not handled by this function
#define THIRTEENTH	0	// modification of a function term() in order to put back tokens not handled by this function
#define FOURTENTH	0	// change in a cout instruction to print result after ';' and to close program when 'e' pressed (end) 
#define FIFTEENTH	0	// implementing a stream: 'Token_stream'
#define SIXTEENTH	0	// implementation of three functions used by 'Token_stream'
#define SEVENTEENTH	0	// definition of a function get(); - function that is doing "most of work"

using namespace std;

int main()
{
	system("chcp 1250");

	if (FIRST)	// first, simple prototype of a calculator: only '-' and '+' are handled
	{
		cout << "Type an expression (only '-' and '+' are handled):\n";
		int lval = 0;
		int rval;
		char op;
		int res;
		cin >> lval >> op >> rval;	// this line reads and loads expressions like: 1 + 3

		if (op == '+')
		{
			res = lval + rval;
		}
		else if (op == '-')
		{
			res = lval - rval;
		}
		cout << "Result is: " << res << "\n";
		keep_window_open();
		return 0;
	}

	else
		
	if (SECOND) // second prototype, using 'switch' instead of 'if' and using few expressions
	{			// TEST RESULT:this program returns 9 instead of 7 when expression is: 1+2*3
				// program lacks operands priority defined in math operations
		cout << "Type an expression (those operands are handled: '+', '-', '*', '/'):\n";
		cout << "Add 'x' at the end in order to finish typing an expression (1+2*3x)\n";
		int lval = 0;
		int rval;
		cin >> lval;			//reading and loading a first argument of an expression
		if (!cin) error("You have not typed an argument (a number) at the begin of expression\n");
		for (char op; cin >> op; )				//reading and loading once operand then argument and again
		{
			if(op != 'x') cin >> rval;
			if (!cin) error("You have not typed a second argument of the expression\n");
			switch (op)
			{
			case '+':
				lval = lval + rval;		//adding lval (already typed) and rval (typed in a for loop)
				break;
			case '-':
				lval = lval - rval;		//subtracting lval (already typed) from rval (typed in a for loop)
				break;
			case '*':
				lval = lval * rval;		//multiplication lval (already typed) with rval (typed in a for loop)
				break;
			case '/':
				lval = lval / rval;		//division lval (already typed) by rval (typed in a for loop)
				break;
			default:
				cout << "Result is: " << lval << '\n';
				keep_window_open();
				return 0;
			}
		}
	}

	else

	if (THIRD)	// to solve above problem (lack of priority) we will use user defined type: 'Token',
	{			// in our case a token will be a class
		class Token {		// class Token as a user defined type with two members
		public:
			char kind;
			double value;
		};

		// below instructions with token as a type and with variable of a token type

		Token t;		// variable 't'
		t.kind = '+';	// this variable named t has value '+' (its member kind is 'plus')
		Token t2;		// variable 't2'
		t2.kind = '8';	// digit '8' means this token type variable is a number (kind: number)
		t2.value = 3.14;	// value of class meber 'value' is 3.14 for this t2 variable

			// copying a variable of token type (same as other types like int, char and so on)

		Token tt = t;		// initalization of copy of token t
		if (tt.kind != t.kind) error("It is impossible!");
		t = t2;				// assigning t2 to the variable t
		cout << t.value;	// it will print 3.14

		// ways to initalize a token with a specific value

		Token t3 = { '+' };		//initialization of t3, then t3.kind = '+'
		Token t4 = { '8', 11.5 };		//initialization of t4, then t4.kind = '8' (a number)
	}									// and t4.value is '11.5'

	else

	if (FOURTH)	// few parts of project of implementing a calculator with tokens described above
	{
		class Token {		// class Token as a user defined type with two members
		public:
			char kind;
			double value;
		};

		Token get_token();		// reading and loading a token from cin stream (get_token() - library function)
		vector<Token> tok;		// vector of tokens

		while (cin) {				// while loop to load data - members of token class
			Token t = get_token();
			tok.push_back(t);
		}

		// for loop to find a '*' operand and calculate multiplication

		for (int i = 0; i < tok.size(); ++i)
			if (tok[i].kind == '*')
				double d = tok[i - 1].value * tok[i + 1].value; // multiplication of two values from tokens
	}															// seperated by operand '*'

	else

	if (FIFTH) // simple GRAMMAR of expressions to parse and analyze syntax of an input (parser and syntax analyzer)
	{
		// Expression:
		//		Term
		//		Expression "+" Term		// Addition		
		//		Expression "-" Term		// Subtraction
		// Term:
		//		Primary
		//		Term "*" Primary		// Multiplication
		//		Term "/" Primary		// Division
		//		Term "%" Primary		// Modulo
		// Primary:
		//		Number
		//		"(" Expression ")"		// Grouping
		// Number:
		//		floating-point-literal

		// example with parsing a number 2

		// Expression:						Expression
		//		Term							^
		//		Expression "+" Term				|			
		//		Expression "-" Term				|
		// Term:							  Term
		//		Primary						    ^
		//		Term "*" Primary			 Primary
		//		Term "/" Primary				^
		//		Term "%" Primary				|
		// Primary:							  Number
		//		Number							^
		//		"(" Expression ")"				|
		// Number:						floating-point-literal
		//		floating-point-literal          ^
		//										2

		// Example of a grammar  - grammar of an English language 
								// (for better understanding of a grammar and parsing in general)
		// Parsed sentence: "BIRDS FLY BUT FISH SWIM"
		// Sentence:
		//		Noun Verb
		//		Sentence Conjunction Sentence
		// Conjunction:
		//		"and"
		//		"or"
		//		"but"
		// Noun:
		//		"birds"
		//		"fish"
		// Verb:
		//		"fly"
		//		"swim

		// Another example of grammar and its rules

		// List:
		//	"{" Sequence "}"
		// Sequence:
		//	Element
		//	Element " ," Sequence
		// Element:
		// "A"
		// "B"
		// Samples of above list: { A }, { B }, { A,B }, {A,A,A,A,B }
	}

	else

	if (SIXTH) //attempt to change grammar and its rules into functions and code
	{
		// Functions and its types to execute and accomplish grammar rules for calculatro needs

		// Token get_token()		// reads and loads characters and creates tokens
		// double expression();		// handles operands: '+' and '-'
		// double term()			// handles characters: '*', '/', '%'
		// double primary()			// handles numbers and brackets

		class Token {		// class Token as a user defined type with two members
		public:
			char kind;
			double value;
		};

		Token get_token();
		double term();
		
		double expression();		// can not define function here, so only declaration of function expression()
		{	// line below will cause infinite recursive calls of function 'expression()'
			double left = expression();		// reads, loads and calculates a value of an expression
			Token t = get_token();			// next token
			switch (t.kind)					// this switch checks type of a token
			{
				case '+':
					return left + term();	// reads, loads and checks value of an element
											// then adds two values
				case '-':
					return left - term();	// reads, loads and checks value of an element
											// then subtracts two values

				default:
					return left;			// returns calculated value of an expression

			}
		}
		// this program has beside infinte recursion one more problem: code does not define 
		// where the 'expression' ends and where characters like '+' and '-' are
	}

	else

	if (SEVENTH) // second attempt to make grammar rules happen 
	{
		class Token {		
		public:
			char kind;
			double value;
		};

		Token get_token();
		double term();

		double expression();		// can not define function here, so only declaration of function expression()
		{	
			double left = term();		// reads, loads and calculates a value of an expression
			Token t = get_token();			// next token
			switch (t.kind)					// this switch checks type of a token
			{
			case '+':
				return left + expression();	// reads, loads and checks value of an element
				// then adds two values
			case '-':
				return left - expression();	// reads, loads and checks value of an element
				// then subtracts two values

			default:
				return left;			// returns calculated value of an expression
			}
		}
		// code above will not return valid answear with expression like this: 1-2-3 and breaks grammar rules
		// that were established before, code in this section means different grammar, like this:
		// Expression:
		//		Term '+' Expression     but it should be: Term '+' Term
		//		Term '-' Expression		but it should be: Term '+' Term
	}

	else

	if (EIGHTH) // third attempt to calculator as an token accepting and handling object according to our grammar rules
	{
		class Token {
		public:
			char kind;
			double value;
		};

		Token get_token();
		double term();

		double expression();		// can not define function here, so only declaration of function expression()
		{
			double left = term();		// reads, loads and calculates a value of an element
			Token t = get_token();			// next token
			while (t.kind == ' + ' || t.kind == ' - ')		// this while loop searches '+' and '-'
			{
				if (t.kind == '+')
					left = left + term();				// value of an element is calculated (addition)
				else
					left = left - term();				// value of an element is calculated (subtraction)
				t = get_token();
			}
			return left;
		}
	}

	else

	if (NINTH)	// few changes of above code (without double check of characters: '-', '+')
	{
		class Token {
		public:
			char kind;
			double value;
		};

		Token get_token();
		double term();

		double expression();
		{
			double left = term();
			Token t = get_token();
			while (true) 
			{
				switch (t.kind)
				{
				case '+':
					left = left + term();
					t = get_token();
					break;
				case '-':
					left = left - term();
					t = get_token();
					break;
				default:
					return left;
				}
			}
		}
	}

	else

	if (TENTH) // handling elements of our grammar (element is 'term' in case of our grammar)
	{
		class Token {
		public:
			char kind;
			double value;
		};

		double primary();

		Token get_token();

		double term();  // function to handle 'term' in our grammar - term is lower tahn expression in our grammar
		{
			double left = primary();	// // reads, loads and calculates a value of an factor
			Token t = get_token();

			while (true)
			{
				switch (t.kind)
				{
				case '*':
					left = left * primary();
					t = get_token();
					break;
				case '/':
					left = left / primary();
					t = get_token();
					break;
				case '%':					 // because of problems described below this operator will be added later
				//	left = left % primary(); // will not compile - can not execute modulo division for type double
					t = get_token();		 // modulo is only to divide and calculate reminder of integers
				default:
					return left;
				}
			}
		}

		// code below is almost the same as above - but with protecting from division by zero

		double term();
		{
			double left = primary();
			Token t = get_token();
			while (true)
			{

				switch (t.kind)
				{
				case '*':
					left = left * primary();
					t = get_token();
					break;
				case '/':
				{							// we need '{}' here to define and to initialize variables in 'switch'
					double d = primary();
					if (d == 0) error("Dzielenie przez zero.");
					left = left / d;
					t = get_token();
					break;
				}
				default:
					return left;
				}
			}
		}
	}
	
	else

	if (ELEVENTH) // function to handle elementary factors entered to the calculator ( numbers and brackets:'()' )
	{

		class Token {
		public:
			char kind;
			double value;
		};

		double expression();
		double primary();
		Token get_token();

		double primary();		// function to handle elementary factors entered to the calculator
		{
			Token t = get_token();
			switch (t.kind)
			{
			case '(':
				{
					double d = expression();
					t = get_token();
					if (t.kind != ')') error("')' was expected.");
					return d;
				}
			case '8':			// '8' means a number in a t.kind of Token class
				return t.value;	// returns value of a number
			default:
				error("A factor was expected");
			}
		}
	}

	// when above functions are used, some tokens are lost (for example, above function expression accepts 
	// only '+' and '-'), so we need to 'save' unused tokens for other function so they can handle it

	else

	if (TWELFTH) // modification of a function expression() in order to put back tokens not handled by this function
	{
		class Token {
		public:
			char kind;
			double value;
			Token get();
			Token putback();
		};

		double term();
		double primary();
		Token get_token();
		Token ts;
		Token get();

		double expression();
		{
			double left = term();
			Token t = ts.get();			// next token is being taken from tokens stream
			while (true)
			{
				switch (t.kind)
				{
				case '+':
					left = left + term();
					t = ts.get();
					break;
				case '-':
					left = left - term();
					t = ts.get();
					break;
				default:
					ts.putback(); // ts.putback(t); - it should be like this but I cant define 'Token t'
					return left;					// in a class 'Token' - it will be in a Token_stream class
				}
			}
		}
	}

	else

	if (THIRTEENTH) // modification of a function term() in order to put back tokens not handled by this function
	{
		class Token {
		public:
			char kind;
			double value;
			Token get();
			Token putback();
		};
		Token ts;
		double primary();

		double term();
		{
			double left = primary();
			Token t = ts.get();

			while (true) 
			{
				switch (t.kind)
				{
				case '*':
					left = left * primary();
					t = ts.get();
					break;
				case '/':
					{
					double d = primary();
					if (d == 0) error("You can not divide by zero.");
					left = left / d;
					t = ts.get();
					break;
					}
				default:
					ts.putback();	// ts.putback(t); - it should be like this but I cant define 'Token t'
					return left;		// in a class 'Token' - it will be in a Token_stream class
				}
			}
		}

	}

	// those two above modifications gave valid answears but with a "delay" - answear was after typing
	// next expression

	else

	if (FOURTENTH) // change in a cout instruction to print result after ';' and to close program when 'e' pressed (end)
	{
		double expression();

		class Token {
		public:
			char kind;
			double value;
			Token get();
			Token putback();
		};
		Token ts;

		// it was just this line to print a result:

		while (cin) cout << "=" << expression() << '\n'; // first, simple version

		// new, more advanced and functional version - prints out after ';'

		double val = 0;
		while (cin)
		{
			Token t = ts.get();

			if (t.kind == 'e') break;	// character 'e' will end program
			if (t.kind == ';')			// character ';' means that there will be cout now
				cout << "=" << val << '\n';
			else
				ts.putback(); // ts.putback(t) - it should be like this
			val = expression();
		}
		// above changes made calculator work properly: 2+3;   = 5   3+4*5;   = 23 and so on
	}

	else

	if (FIFTEENTH) // implementing a stream: 'Token_stream'
	{
		class Token {
		public:
			char kind;
			double value;
			Token get();
			Token putback();
		};

		// user defined types:
		// public interface of such user defined object: 'public:'
		// private interface of such user defined object: 'private:'

		class Token_stream {	// inital, proposed construction of a class (object) 'Token_stream'
		public:
			Token_stream();		// this function creates type: 'Token_stream', that reads data from a stream
		
			Token get();		// this function gives a Token - object of a 'Token' type
			void putback(Token t);	// this function gives back a specific token

		private:
								// function implementation and other details
		};

		// a way to use a 'Token_stream':

		Token_stream ts;		// declaration of object of type 'Token_stream'
		Token t = ts.get();		// declaration of a 'Token' t, that is taken from ts with function get() 
		// ...						(next Token from ts stream)
		ts.putback(t);			// Token t is returned to the 'Token_stream' - to the object ts
	}

	else

	if (SIXTEENTH) // implementation of three functions used by 'Token_stream'
	{
		class Token {
		public:
			char kind;
			double value;
			Token get();
			Token putback();
		};

		//Token Token::putback()	// this line causes error: Can not define member: 'function putback()' 
		//{								// of a class Token outside the class again
		//};

		//Token Token::get()        // exact the same error as above
		//{
		//}

		class Token_stream {
		public:
			Token_stream();		// creates object of 'Token_stream" type that takes data froam a stream

			Token get();		// it gives a Token - get() is defined somewhere else
			void putback(Token t);	// this gives a token back
		private:
			bool full;			// a flag to tell whether there already is a token in a buffer
			Token buffer;		// a place to keep and store a token written in a stream 
		};						// with a function putback()

		// definition of a putback() function

		// void Token_stream::putback(Token t) { // same error as in line with: 'Token Token::putback()'
		//	buffer = t;			// this instruction makes a copy of Token t to the buffer (object of Token type)
		//	full = true;
		// }

		// special test to check whether a function was not called twice without reading (with functioin get) 
		// what was written in a stream between those calls

		// void Token_stream::putback(Token t) // again, same error as above - declaration again outsied the class
		// {
			// if (full) error("Function putback() was called again, when buffer is full");
			// buffer t; // this copies an object t to the buffer
			// full = true; // buffer is full
		// }

		// above test checks an initial condition: there is no any token in a buffer
	}

	else

	if (SEVENTEENTH)	// definition of a function get(); - function that is doing "most of work"
	{
		class Token {
		public:
			char kind;
			double value;
			Token get();
			Token putback();
		};

		class Token_stream {
		public:
			Token_stream();		// creates object of 'Token_stream" type that takes data froam a stream

			Token get();		// it gives a Token - get() is defined somewhere else
			void putback(Token t);	// this gives a token back
		private:
			bool full;			// a flag to tell whether there already is a token in a buffer
			Token buffer;		// a place to keep and store a token written in a stream 
		};						// with a function putback()

		//Token Token_stream::get()
		//{
		//	if (full) // checking whteher there is a token that is ready
		//	{
		//		// deleting token out of the buffer
		//		full = false;
		//		return buffer;
		//	}

		//	char ch;
		//	cin >> ch; // Hint: '>>' avoids 'white signs (space, new line, tab)'

		//	switch (ch)
		//	{
		//		case ';':		// if ';', then printing of an calculated expression
		//		case 'e':		// if 'e', then program ends 
		//		case '(': case ')': case '+': case '-': case '*': case '/': case '%':
		//			return Token(ch); // each of characters represents itself
		//		case '0': case '1': case '2': case '3': case '4':
		//		case '5': case '6': case '7': case '8': case '9':
		//		{	cin.putback(ch);
		//			double val;
		//			cin >> val;
				//	return Token('8', val); // error: non of instance does not match the argument list
		//		}							// argument types: (char, <error-type>)
				//default:			// label 'default' can be used only in a switch instruction
		//		error("Invalid token (character)");
		//	}
		//}
	}
}