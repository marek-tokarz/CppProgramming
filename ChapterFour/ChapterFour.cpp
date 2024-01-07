#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

#define FIRST		1		// currency calculator
#define SECOND		0		// Simple Switch-Case, inches to cm and cm to inches
#define THIRD		0		// errors in switch
#define FOURTH		0		// errors: few labels (cases) for the same case
#define FIFTH		0		// errors: switch without break
#define SIXTH		0		// simple while loop with 'char' to 'int'
#define SEVENTH		0		// simple for loop with 'char' and their 'int' substitutes
#define EIGHTH		0		// 'square' with adding only - function declaration
#define NINTH		0		// firs vector - average and median of temperatures
#define TENTH		0		// vector with words as a form of dictionary - sorted words
#define ELEVENTH	0		// program to change input words (unwanted) to other words
using namespace std;

int square_sum(int x);

inline void keep_window_open() { char ch; cin >> ch; }
int main()
{
	system("chcp 1250");

	if (FIRST)
	{
		cout << "Conversion of yen, euro and PLN to $\n";
		
		cout << "What currency do you want to convert: 'yen', 'euro', 'PLN' \n";
		string currency;
		cin >> currency;
		double value;
		cout << "How much in that value do you have?\n";
		cin >> value;
		int iteration = 0;
		while (iteration < 10)
		{
			if (currency == "yen")
				cout << value << " yen = " << value * 0.0067 << " $ \n";
			else
				if (currency == "euro")
					cout << value << " euro = " << value * 1.06 << " $ \n";
				else
					if (currency == "PLN")
						cout << value << " PLN = " << value * 0.24 << " $ \n";
					else
						cout << "Wrong value - name of currency \n";
			iteration++;

			cout << "What currency do you want to convert: 'yen', 'euro', 'PLN' \n";
			cin >> currency;
			cout << "How much in that value do you have?\n";
			cin >> value;
		}
	}
	
	if (SECOND)
		{
			const double cm_per_inch = 2.54;
			double lenght = 1;
			char unit = 'a'; // it can not be strin, only char or int are fine
			//cm_per_inch = 1; // it causes error, cant be modified
			string next;

			do
			{
				cout << "What is the lenght and unit? (c or i): \n";
				cin >> lenght >> unit;
				switch (unit)
				{
				case 'i': // it has to be a specific vale, it can not be a variable
					cout << lenght << "cal == " << cm_per_inch * lenght << " cm\n";
					break; // after each case there has to be a break, compiler does not remind about that
				case 'c':// same value can not be used for two labels 'case', ther cant be case 'i' and case 'i' again
					cout << lenght << "cm == " << lenght / cm_per_inch << " cal\n";
					break;
				default:
					cout << "Wrong value";
					break;
				}
				cout << "Do you want to make another conversion of units? \n 'yes', 'no'\n";
				cin >> next;
			} while (next != "no");
		}

	if (THIRD)
			{
				int y = 'y';
				const char n = 'n';
				const char m = '?';
				cout << "Do you like fish? \n";
				char a;
				cin >> a;
				switch (a)
				{
				case n:
					cout << "first case, n";
					break;
					// case y: // expression must have a constant value, value of variable like 'y' can not be used as a constant
					//case 'n': // value of this case label had alredy been in switch in line 92
				}
			}
	
	if (FOURTH)
				{
					string next = "0";

					do
					{
						cout << "Give a digit\n";
						char digit = '0';
						cin >> digit;
						switch (digit)
						{
						case '0': case '2': case '4': case '6': case '8':
							cout << "Even \n";
							break;
						case '1': case '3': case '5': case '7': case '9':
							cout << "Odd \n";
							break;
						default:
							cout << "Wrong value \n"; //wczytuje pierwszy znak jako cyfrę i nigdy nie wchodzi do default
							break;
						}
						cout << "Do you want to check again? 'yes', 'no'\n";
						cin >> next;
					} while (next != "no");

				}

	if (FIFTH)
	{
		const double cm_per_inch = 2.54;
		double lenght = 1;
		char unit = 'a'; 
		string next;

		do
		{
			cout << "What is the lenght and unit? (c or i): \n";
			cin >> lenght >> unit;
			switch (unit)
			{
			case 'i': 
				cout << lenght << "cal == " << cm_per_inch * lenght << " cm\n";
				//break;  // przy braku break wykona wszystkie case
			case 'c':
				cout << lenght << "cm == " << lenght / cm_per_inch << " cal\n";
				break;
			default:
				cout << "Wrong value \n";
				//break;
			}
			cout << "Do you want to make another conversion of units? \n 'yes', 'no'\n";
			cin >> next;
		} while (next != "no"); // wchodzi w jakąś nieskończoną pętlę, "KernelBased.dll wyjatek WTF?
	}

	if (SIXTH)
	{
		char letter = 'a';
		int i = 0;
		while (i < 26)
		{
			cout << char(letter + i) << "\t" << letter + i << "\n"; // forced conversion is important
			i++;													// or it will convert char to int
		}
	}

	if (SEVENTH)
	{
		char letter = 0;
		int i = 0;
		for (i = 48; i < 58; i++)
		{
			cout << char(letter + i) << "\t" << letter + i << "\n";
		}
		
		for (i=65; i < 91; i++)
		{
			cout << char(letter + i) << "\t" << letter + i << "\n";
		}

		for (i=97; i < 123; i++)
		{
			cout << char(letter + i) << "\t" << letter + i << "\n";
		}
	}

	if (EIGHTH) 
	{
		cout << "Squares of numbers 8, 10, and 12\n\n";
		
		int a = 8;

		int b = 10;

		int c = 12;
		
		cout << square_sum(a) << "\n";

		cout << square_sum(b) << "\n";

		cout << square_sum(c) << "\n";
	}
	
	if(NINTH)
	{
		vector<double> temps;		// temperatures vector
		double temp;
		while (cin >> temp)			// input of data
			temps.push_back(temp);	// loading to the vector
									// calculation of average temperature
		double sum = 0;
		for (int i = 0; i < temps.size(); ++i)
			sum = sum + temps[i];
		cout << "Average temperature is: " << sum / temps.size() << endl;
																				// median calculation
		sort(temps.begin(), temps.end());		// sorting 'temps' vector from smallest to largest
		cout << "Mediana: " << temps[temps.size() / 2] << endl;
	}

	if (TENTH)
	{
		vector <string> words;
		string temp;
		while (cin >> temp)
			words.push_back(temp);
		cout << "Number of words: " << words.size() << endl;
		sort(words.begin(), words.end());								// how does sort works? is it alphabetical for sure?
		for (int i = 0; i < words.size(); ++i)
		{
			if (i == 0 || words[i - 1] != words[i])			// checking whether words near each other are the same
				cout << words[i] << endl;
		}
	}

	if (ELEVENTH)
	{
		vector<string> disliked = {"darkness", "shadow", "moon", "night"};
		vector<string> words;
		string temp;
		string other_value = "Unwanted word";
		int counter = 0;
		while (cin >> temp)
		{
			counter = 0;
			for (int i = 0; i < 4; i++)
			{
				if (temp == disliked[i])
					counter = counter + 1;
			}
			if (counter != 0)
				words.push_back(other_value);
			else
				words.push_back(temp);
		}
		for (int i = 0; i < words.size(); ++i)
		{
			cout << words[i] << endl;
		}
	}	
}

int square_sum(int x)
{
	int result = 0;
	for (int i = 0; i < x; i++)
		result = x + result;
	return result;
}
