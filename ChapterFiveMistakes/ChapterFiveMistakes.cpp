#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

// libraries from author of the book

#include<std_lib_facilities.h>

// code in specific examples is deliberately below incomplite, mostly with demonstrating and explaining purposes

#define FIRST			0		// compilation errors: syntax errors
#define SECOND			0		// compilation errors: type errors	
#define THIRD			0		// compilation errors: errors that seem to not be errors
#define FOURTH			0		// consolidation errors	
#define FIFTH			0		// runtime errors
#define SIXTH			0		// solving error from previous program (division by zero) by "user" - function caller
#define SEVENTH			0		// solving error from previous program (division by zero) by "user" - function caller - WITH CONST INT
#define EIGHTH			0		// solving error from previous program (division by zero) by FUNCTION
#define NINTH			0		// errors raporting
#define TENTH			0		// trying to find all possible errors (more code need - protection from invali input)
#define ELEVENTH		0		// exceptions - try, throw, catch, incorrect arguments
#define TWELFTH			0		// exceptions - range errors
#define THIRTEENTH		0		// exceptions - incorrect input data
#define FOURTEENTH		0		// uncaught exception
#define FIFTEENTH		0		// range narrow down errors
#define SIXTEENTH		0		// logical errors
#define SEVENTEENTH		1		// initial and final conditions


using namespace std;

// THIS FUNCTION WAS USED FOR "ifs" since FIRST to NINTH
//int area(int lenght, int width);	//calculation of rectangle area
//{
//	return lenght * width;
//} 

// THIS FUNCTION WAS USED FOR "ifs" since FIRST to NINTH
int framed_area(int x, int y); //calculation of rectangle area in the frame
//{
//	return area(x - 2, y - 2); // function calls another function
//}

int area_correct(int lenght, int width)
{
	if (lenght <= 0 || width <= 0) {
		cout << "Calling function area_correct:\nParameters of this function can not be less or equal to 0\n";
		return -1;
	}
	else
		return lenght * width;
}

int framed_area_correct(int a, int b)
{
	if (a - 2 <= 0 || b - 2 <= 0) {
		cout << "Calling function framed_area_correct:\nParameters of this function can not be less or equal to 2\n";
		return -1;
	}
	else
		return (a - 2) * (b - 2);
}

class Bad_area {}; //special type to report errors in area() function

int area_with_exception(int lenght, int width)
{
	if (lenght <= 0 || width <= 0) throw Bad_area();
	return lenght * width;
}

int main()
{
	system("chcp 1250");

	if (FIRST)	// compilation errors: syntax errors
	{
		//	int s1 = area(7;	     // lack of sign: ')'
		//	int s2 = area(7)		 // lack of sign ';'
		//	Int s3 = area(7)		 // there is no 'Int' type
		//	int s4 = area('7);	 // there is no sign ' in the ()
	}
	
	else

	if (SECOND) // compilation errors: type errors
	{
		//	int x0 = arena(7);			// undefined function
		//	int x1 = area(7);			// incorrect number of parameters
		//	int x2 = area("seven", 7);	// first parameter has an incorrect type - "const char *" 
		//                                 is incompatibile with 'int' 
	}

	else

	if (THIRD) // compilation errors: errors that seem to not be errors
	{
		//	int x4 = area(10, -7);	//area of rectangle can not be negative
		//	int x5 = area(10.7, 9.3); // seems fine, but compiler will use numbers: 10, 9 instead of numbers:
		//                               10.7, 9.3 - nonvisible conversion
		//	char x6 = area(100, 9999); // seems fine, but the result will be reduced because of "char" type
	}

	else

	if (FOURTH) // consolidation errors
	{
		//int x = area(2, 3); //if function area was declared dut not defined there will be consolidation error
		//                      compiler said: unrecognized external element

		// same name but different type functions will be ignored when function area: 
		// "area(int lenght, int width)" is called:
		//double area(double x, double y);
		//int area(int x, int y, char unit);
	}

	else

	if (FIFTH) // runtime errors
	{
		int x = -1;
		int y = 2;
		int z = 4;

		//int area1 = area(x, y);
		//int area2 = framed_area(1, z);
		//int area3 = framed_area(y, z);
		//double ratio = double(area1 / area3); // type conversion - conversion to double 
		// in order to make floating point division
		// above line will cause an error, description of an error: 
		// unserved exception: integer division by zero		
	}

	else

	if (SIXTH) // solving error from previous program (division by zero) by "user" - function caller
	{
		int x = -1;
		int y = 2;
		int z = 4;

		if (x <= 0) cout << "Value of a variable 'x' is not postive\n";
		if (y <= 0) cout << "Value of a variable 'y' is not postive\n";
		//int area1 = area(x, y);

		if (x <= 0 || y <= 0) cout << "Parameter of a function area() is not positive\n"; // alternative way
																						  // only one statement for both parameters
		if (z <= 2) cout << "Second parameter of a function area() called by a function framed_area() is not positive";
		//int area2 = framed_area(1, z);

		if (y <= 2 || z <= 2) cout << "Parameter of a function area() called by a function framed_area() is not positive";
		//int area3 = framed_area(y, z);
	}

	else

	if (SEVENTH) // solving error from previous program (division by zero) by "user" - function caller
	{
		int x = -1;
		int y = 2;
		int z = 4;

		const int frame_width = 2;

		if (x <= 0) cout << "Value of a variable 'x' is not postive\n";
		if (y <= 0) cout << "Value of a variable 'y' is not postive\n";
		//int area1 = area(x, y);

		if (x <= 0 || y <= 0) cout << "Parameter of a function area() is not positive\n"; // alternative way
																						  // only one statement for both parameters

		if (z - frame_width <= 0) cout << "Second parameter of a function area() called by a function framed_area() is not positive";
		//int area2 = framed_area(1, z);

		if (y - frame_width <= 0 || z - frame_width <= 0) cout << "Parameter of a function area() called by a function framed_area() is not positive";
		//int area3 = framed_area(y, z);
	}

	else

	if (EIGHTH) // solving error from previous program (division by zero) by FUNCTION
	{
		//int area2(int lenght, int width); //function declaration here because of demonstrating purposes
		//int framed_area2(int x, int y); //function declaration here because of demonstrating purposes

		int x = -1;
		int y = 2;
		int z = 4;

		int lenght;
		int width;

		const int frame_width = 2;

	 // int area2(int lenght, int width)  //I can not make a function definition here
		{
			if (lenght<=0 || width <= 0)
				cout << "Calling function area\nParameter of a function area() is not positive\n";
		}

	 // int framed_area2(int x, int y)    //I can not make a function definition here
		{
			constexpr int frame_width = 2;
			if (x - frame_width <= 0 || y - frame_width <= 0)
				cout << "Parameter of a function area() called by a function framed_area() is not positive";
			//return area(x - frame_width, y - frame_width);
		}
	}

	else

	if (NINTH) // errors raporting
	{
		string question;

		char ask_user(string question); // asking a user a "yes or no question"
		{								// if answer is not a yes or y or no or n then there is a incorrect answer and the error
			cout << question << "? (yes or now)\n";
			string answer = " ";
			cin >> answer;
			if (answer == "t" || answer == "yes") return 't';
			if (answer == "n" || answer == "no") return 'n';
			return 'z';			// 'z' in this case is an incorrect answer - it is a report of an error
		}

		int lenght, width;

	  // int area(int lenght, int width);
		{
			if (lenght <= 0 || width <= 0) return -1;
			return lenght * width;
		}
	}

	else

	if (TENTH) // trying to find all possible errors
	{
		int x = 1;
		int y = 1;
		int z = 1;

		int area1 = area_correct(x, y);
		cout << "Area1 is: " << area1 << "\n";

		int area2 = framed_area_correct(1, z);
		cout << "Area2 is: " << area2 << "\n";

		int area3 = framed_area_correct(y, z);
		cout << "Area3 is: " << area3 << "\n";

		double ratio = double(area1 / area3);
		cout << "ratio is: " << ratio << "\n";
	}

	else

	if (ELEVENTH) //exceptions - try, throw, catch, incorrect arguments
	{
		try {
			int x = -1;
			int y = 2;
			int z = 4;

			int area1 = area_with_exception(x, y);
			int area2 = framed_area_correct(1, z);
			int area3 = framed_area_correct(y, z);
			double ratio = area1 / area3;
		}
		catch (Bad_area) {
			cout << "Incorrect parameteres for function area().\n";
		}
	}

	else

	if (TWELFTH) //exceptions - range error (vectro subscript out of range)
	{
		//vector<int> v;
		//for (int i; cin >> i; )
		//	v.push_back(i);
		//for (int i = 0; i <= v.size(); ++i)
		//	cout << "v[" << i << "] == " << v[i] << '\n';

		// same code as above but with an exception handling

		try {
			vector<int> v;
			for (int x; cin >> x; )
				v.push_back(x);
			for (int i = 0; i <= v.size(); ++i)
				cout << "v[" << i << "] == " << v[i] << '\n';
		}
		catch (out_of_range) {
			cerr << "Range error"; // after running a program I can not see this message (I tried cout too)
			return 1;			   // 'cerr' work like a 'cout' but it is for error purposes
		}
	}

	else

	if (THIRTEENTH) //exceptions - incorrect input data
	{
		//double d = 0;
		//cin >> d;
		if (cin) {
			// 'cin' was correct, another number can be loaded
		}
		else {
			//loading operation had failure, another instruction will be carried out
		}

		//alternative way of above code

		double d = 0;
		cin >> d;
		if (!cin) cout << "Number of type 'double' could not be loaded in a function\n"; //!cin means a failure of cin operation


		//example with runtime error

		void error(string s);		// I can not declare function here
		{
			string s;
			throw runtime_error(s);
		}

		//catching runtime error

		void keep_window_open(); //declaration in order to write proper instructions in every 'catch' below

		try {
			// instructions of a program
			return 0; // here '0' means succes, no errors appeard
		}
		catch (runtime_error& e) {
			cerr << "Error of type 'run time error'" << e.what() << "\n";
			keep_window_open();
			return 1; // here '1' means a failure, an error
		}

		//handling exceptions like out_of_range and runtime_error

		try {
			// instructions of a program
			return 0; // here '0' means succes, no errors appeard
		}
		catch (exception& e) {
			cerr << "Error: " << e.what() << "\n";
			keep_window_open();
			return 1; // here '1' means a failure, an error
		}
		//catch (exception) {   // here can appear any exception - this catch handles all type of exception
		{	cerr << "Unknown exception type \n";	  //that are not handled in the code above this catch
			keep_window_open();
			return 2; // here '2' means a failure, an error
		}

		//using function error() to describe problem with two messages - strings concatenation

		string s1;
		string s2;
		void error(string s1, string s2);
		{
			throw runtime_error(s1 + s2);
		}
	}

	else

	if (FOURTEENTH) // uncaught exception
	{
		// if an exception was not caught by user - handled by his 'catch' there will be system message - uncaught error
		cout << "Enter a number\n";
		int a;
		cin >> a;
		cout << "You have entered a: " << a << "\n";
		//error();   // I can not use error() function without declaring it first
					 // it was supposed to be a system function in some library, bu it isn't
	}

	else

	if (FIFTEENTH) // range narrow down errors
	{		
		//handling narrow down errors with narrow_cast from <std_lib_facilities.h> from author of the book
		// int x1 = narrow_cast<int>(2.9);		// here an execption will occur
		// int x2 = narrow_cast<int>(2.0);		// here is no exception
		// char c1 = narrow_cast<char>(1066);  // here an execption will occur
		// char c2 = narrow_cast<char>(85);	// here is no exception
	}

	else

	if (SIXTEENTH) // logical errors
	{
		{
			vector<double> temps;
			double temp = 0;
			double sum = 0;
			double high_temp = 0;   // this inicialization causes problem - what if all temperature are below 0?
			double low_temp = 0;    // this inicialization causes problem - what if all temperature are above 0?

			while (cin >> temp)
				temps.push_back(temp);
			for (int i = 0; i < temps.size(); ++i)
			{
				if (temps[i] > high_temp) high_temp = temps[i];
				if (temps[i] < low_temp) low_temp = temps[i];
				sum = sum + temps[i];
			}
			cout << "Highest temp. is: " << high_temp << '\n';
			cout << "Lowest temp. is: " << low_temp << '\n';
			cout << "Average temp. is " << sum / temps.size() << '\n';
		}
		//second version of above code
		{
			vector<double> temps;
			double temp = 0;
			double sum = 0;
			double high_temp = -1000;   // this inicialization is a value, that will never occur - becasue those are temperatures
			double low_temp = 1000;     // this inicialization is a value, that will never occur - becasue those are temperatures
			int no_of_temps = 0;

			while (cin >> temp) {
				++no_of_temps;
				sum += temp;
				if (temp > high_temp) high_temp = temp;
				if (temp < low_temp) low_temp = temp;
			}
			cout << "Highest temp. is: " << high_temp << '\n';
			cout << "Lowest temp. is: " << low_temp << '\n';
			cout << "Average temp. is " << sum / no_of_temps << '\n';
		}
	}
	
	else

	if (SEVENTEENTH) // initial and final conditions
	{
		{
			// coments about function:
			// function calculates rectangle area
			// function reports exception Bad_area() when function recieved invalid argumnets 
			int area(int length, int width);
			{
				int length, int width;			// declaration again becasue I can not declare function here
				if (length <= 0 || width <= 0) throw Bad_area();
				return length * width;
			}
		}
		// now more proper and useful comments about initial and final conditions of a function
		// alternative code of above function area()

		int area(int length, int width);
		// function calculates rectangle area
		// Initial conditions: variables 'length' and 'width' must be a positive numbers
		// Final conditions: function returns positive value - an area of rectangle
		{
			int length, int width;			// declaration again becasue I can not declare function here
			if (length <= 0 || width <= 0) error("Initial condition of area() function");
			int a = length * width;
			if (a <= 0) error("Final condition of area function");
			return a;
		}
		// initial and final conditions help to create basic test of code
	}
}

