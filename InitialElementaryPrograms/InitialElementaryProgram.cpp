#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

#define FIRST		0		// initial
#define SECOND		0		// floating point numbers operation
#define THIRD		0		// concatenation (joining) of 'strings'
#define FOURTH		0		// porównanie stringów
#define FIFTH		0		// detection of repeting word and summing amount of their occurence
#define SIXTH		0		// types conversion, char -> int
#define SEVENTH		0		// safe types conversion
#define EIGHTH		0		// not allowed types conversion
#define NINTH		0		// conversion experiments
#define TENTH		0		// initalization with brackets {}
#define ELEVENTH	0		// miles to km conversion
#define TWELFTH		0		// simple calculator
#define THIRTEENTH	0		// sorting three numbers with 'if'
#define FOURTEENTH	0		// sorting 'string' with if
#define FIFTEENTH	0		// parity checking
#define SIXTEENTH	0		// 0 - zero, 1 - one, 2 - two and so on
#define SEVENTEENTH	0		// calculator with type of operation choosing: choose: +, -, *, /
#define EIGHTEENTH	1		// sum of coins
using namespace std;

inline void keep_window_open() { char ch; cin >> ch; }

int main()
{
	system("chcp 1250");

	if (FIRST)
	{
		cout << "Type your name and age\n";
		string first_name;
		double age;
		cin >> first_name;
		cin >> age;
		cout << "Hello, " << first_name << " (age * months = " << age * 12 << ")\n";
	}

	if (SECOND)
	{
		cout << "Enter floating piont number \n";
		int n;
		cin >> n;
		cout << "n == " << n
			<< "\n n + 1 == " << n + 1
			<< "\n Three times n == " << n * 3
			<< "\n Two times n == " << n * 2
			<< "\n n squared == " << n * n
			<< "\n Half of n == " << n / 2
			<< "\n Square root of n == " << sqrt(n)
			<< "\n";
	}

	if (THIRD)
	{
		cout << "Enter 'string' that will be joined (concatenation) \n";
		string first;
		string second;
		cin >> first >> second;
		string concatenation = first + " " + second;
		cout << concatenation;
	}

	if (FOURTH)
	{
		cout << "Enter two string to comparison \n";
		string first;
		string second;
		cin >> first >> second;
		if (first == second) cout << "Two same names have been typed\n";
		if (first < second) cout << first << " is alphabetically first than " << second << "\n";
		if (first > second) cout << second << "  is alphabetically first than " << first << "\n";
	}

	if (FIFTH)
	{
		int number_of_words = 0;
		string previous = " ";
		cout << "Enter a word \n";
		string current;
		int i = 0;
		int end_of_loop = 20;
		while (cin >> current && i != end_of_loop)
		{
			++number_of_words;
			if (previous == current)
				cout << "Word number: " << number_of_words << " has occured: " << current << " times " << '\n';
			cout << "Enter a word \n";
			previous = current;
			i++;
		}
	}

	if (SIXTH)
	{
		char c = 'x';
		int i1 = c;
		int i2 = 'x';

		char c2 = i1;

		cout << c << ' ' << i1 << ' ' << c2 << '\n';

	}

	if (SEVENTH)
	{
		// allowed conversions - bool to char - there has been a failure
		bool bool_number_1 = 1;
		char char_number_1 = 'a';
		int integer_number_1 = 10;

		char one = bool_number_1;
		int two = bool_number_1;
		double three = bool_number_1;

		int four = char_number_1;
		double five = char_number_1;

		double six = integer_number_1;

		cout << "Bool to char: " << one << "\nBool to int: " << two << "\nBool to double: " << three
			<< "\nChar to int: " << four << "\nChar to double: " << five << "\nInt to double: " << six;
	}

	if (EIGHTH)
	{
		int a = 20000;
		char c = a;
		int b = c;
		if (a != b)
			cout << "Liczby: " << a << " i " << b << " są różne ";
		else
			cout << "Liczby:" << a << " i " << b << " są równe";
		cout << "\n";
	}

	if (NINTH)
	{
		double d = 0;
		while (cin >> d)
		{
			//int i = d;		// converison of double to int
			//char c = i;		// converison int to char
			//int i2 = c;		// sign char (c) as a int variable - "value of sign"
			//cout << "d == " << d << " double\n"
			//	<< "i == " << i << " int\n"
			//	<< "i2 == " << i2 << " int made of char 'c'\n"
			//	<< "char( " << c << " ) char made of int i\n";
		}
	}
	
	if (TENTH)
	{
		//double x{ 2 };
		//int y{ x };
		//int a{ 64 };
		//char b{ a };

		//cout << "Double to int: " << y << "\nInt to char: " << b;
	}
		
	if (ELEVENTH)
	{		
		// konwersja mil na km
		double miles = 0;
		cout << "Enter number of miles \n";
		
		while (cin >> miles) 
		{
			cout << "Kilometers: " << (miles / 1.609) << "\n";
			cout << "Enter number of miles \n";
		}
	}

	if (TWELFTH)
	{
		int a = 0;
		while (a < 10)
		{
			cout << "Enter two integer numbers: \n";
			double val1, val2;
			cin >> val1;
			cin >> val2;
			if (val1 > val2)
				cout << "Bigger number is value_1 \n";
			if (val2 > val1)
				cout << "Bigger number is value_2 \n";
			if (val1 == val2)
				cout << "Those numbers are equal \n";
			cout << "Sum: " << val1 + val2 << "\n";
			cout << "Difference: " << val1 - val2 << "\n";
			cout << "Product: " << val1*val2 << "\n";
			cout << "Quotient: " << val1 / val2 << "\n";
			a++;
		}
	}

	if (THIRTEENTH)
	{
		int  a = 0, b = 0, c = 0;
		int x = 0;
			while (x < 10)
			{ 
				x++;
				cout << "Enter 'a', 'b', 'c': \n";
				cin >> a;
				cin >> b;
				cin >> c;
				if (a > b || a == b)
				{
					if (b > c || b == c)
					cout << c << ", " << b << ", " << a << "\n";
					else
						if (a > c || a == c)
							cout << b << ", " << c << ", " << a << "\n";
						else
							cout << b << ", " << a << ", " << c << "\n";
	
				}
				else
					if(c > b || c == b)
						cout << a << ", " << b << ", " << c << "\n";
					else
						if(a > c || a == c)
							cout << c << ", " << a << ", " << b << "\n";
						else
							cout << a << ", " << c << ", " << b << "\n";
			}



	}

	if (FOURTEENTH)
	{
		string  a = "0", b = "0", c = "0";
		int x = 0;
		while (x < 7)
		{
			x++;
			cout << "Enter 'a', 'b', 'c': \n";
			cin >> a;
			cin >> b;
			cin >> c;
			if (a > b || a == b)
			{
				if (b > c || b == c)
					cout << c << ", " << b << ", " << a << "\n";
				else
					if (a > c || a == c)
						cout << b << ", " << c << ", " << a << "\n";
					else
						cout << b << ", " << a << ", " << c << "\n";

			}
			else
				if (c > b || c == b)
					cout << a << ", " << b << ", " << c << "\n";
				else
					if (a > c || a == c)
						cout << c << ", " << a << ", " << b << "\n";
					else
						cout << a << ", " << c << ", " << b << "\n";
		}

	}

	if (FIFTEENTH)
	{
		int x = 0;
		int a = 0;
		int b = 0;

		cout << "Enter 'a' \n";
		cin >> a;
		while (x < 5)
		{			
			x++;
			b = a % 2;
			if (b == 1)
				cout << "This number: " << a << " is odd \n";
			else
				cout << "This number: " << a << " is even \n";
			cout << "Enter 'a' \n";
			cin >> a;
		}
	}

	if (SIXTEENTH)
	{
		string number;
		cout << "Enter a number \n";
		cin >> number;
		int a = 0;
		while (a < 10)
		{
			if (number == "zero")
				cout << "You have entered: " << 0 << "\n";
			else
				if (number == "one")
					cout << "You have entered: " << 1 << "\n";
				else
					if (number == "two")
						cout << "You have entered: " << 2 << "\n";
					else
						if (number == "three")
							cout << "You have entered: " << 3 << "\n";
						else
							if (number == "four")
								cout << "You have entered: " << 4 << "\n";
							else
								cout << "Wrong number" << "\n";
			cout << "Enter a number \n";
			cin >> number;
			a++;
		}
	}

	if (SEVENTEENTH)
	{
		int a = 0;
		char operation = '0';
		double number_1 = 0, number_2 = 0;
		cout << "What operation do you want to perform: +, -, *, /: \n";
		cin >> operation;
		cout << "Enter first number: \n";
		cin >> number_1;
		cout << "Enter second number: \n";
		cin >> number_2;
		
		while (a < 10)
		{
			if (operation == '+')
				cout << number_1 << " + " << number_2 << " = " << number_1+number_2 << "\n";
			else
				if (operation == '-')
					cout << number_1 << " - " << number_2 << " = " << number_1-number_2 << "\n";
				else
					if (operation == '/')
						cout << number_1 << " / " << number_2 << " = " << number_1/number_2 << "\n";
					else
						if (operation == '*')
							cout << number_1 << " * " << number_2 << " = " << number_1*number_2 << "\n";
						else
							cout << "Wrong operation \n";
			a++;
			cout << "What operation do you want to perform: +, -, *, /: \n";
			cin >> operation;
			cout << "Enter first number: \n";
			cin >> number_1;
			cout << "Enter second number: \n";
			cin >> number_2;
		}
	}

	if (EIGHTEENTH)
	{
		cout << "Program to sum up the value in different coins, type how many of specific coins do you have? \n";
		int one = 0, two = 0, five = 0, ten = 0, fifty = 0;
		cout << "Type amount of 1/100 coins\n";
		cin >> one;
		cout << "Type amount of 2/100 coins \n";
		cin >> two;
		cout << "Type amount of 5/100 coins \n";
		cin >> five;
		cout << "Type amount of 10/100 coins \n";
		cin >> ten;
		cout << "Type amount of 50/100 coins \n";
		cin >> fifty;

		cout << "You have in total: \n";
		cout << one << " 1/100 coins \n";
		cout << two << " 2/100 coins\n";
		cout << five << " 5/100 coins \n";
		cout << ten << " 10/100 coins \n";
		cout << fifty << " 50/100 coins \n";
		cout << "Total value of your coins is: \n" << one + two * 2 + five * 5 + ten * 10 + fifty * 50;
	}
}