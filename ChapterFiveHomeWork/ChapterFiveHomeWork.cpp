#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

// libraries from author of the book

#include<std_lib_facilities.h>

// Description as in commit:
// Few simple programs focused on avoiding and detecting errors. Interesting program - game called 'bulls and cows",  
// some challenge becasue of dificulty to create by myslef not quite obvious alghoritm to solve the problem.


#define FIRST			0		// program had errros, below correct version after bug fixing
#define SECOND			0		// added an input test - while loop
#define THIRD			0		// program checks if error in a function "ctokInputTempCheck()"
#define FOURTH			0		// converting from Kelvin to Celsius too
#define FIFTH			0		// converting from Fahrenheit to Celsius and inversly too
#define SIXTH			0		// root of a quadratic equation
#define SEVENTH			0		// a sum of N first numbers typed by user, N is typed by user
#define EIGHTH			0		// same program as above, but there is an error info when sum is not an int value
#define NINTH			0		// same as SEVENTH, but with additional vector with difference of adjacent numbers 
#define TENTH			0		// Fibonacci numbers, finding biggest Fibonacci number to fit into int type, biggest found: 1836311903
#define ELEVENTH		0		// 'bulls and cows' game, guessing 4 numbers
#define TWELFTH			0		// same as above, but many games without exiting program and different answears - generated at each play
#define THIRTEENTH		1		// pairs of a day and a number, like: Monday 11, Tuesday 14... 

using namespace std;

double ctok(double c) //converting Celsius degrees to Celvin scale of degrees (starting from FIRST)
{
	int k = c + 273.15;
	return k;
}

double ctokInputTempCheck(double c) //converting Celsius degrees to Celvin scale of degrees (starting from THIRD)
{
	if (c < -273.15)
	{
		cout << "There is no temperature below -273.15 Celsius degrees";
		return 1;
	}
	else
	{
		int k = c + 273.15;
		return k;
	}
}

double ktocInputTempCheck(double k) // converting Kelvin to Celsius (at FOURTH)
{
	if (k < 0)
	{
		cout << "There is no temperature below 0 Kelvin degrees";
		return 1;
	}
	else
	{
		int c = k - 273.15;
		return c;
	}
}

double ctofInputTempCheck(double c) // converting from Celsius to Fahrenheit (FIFTH)
{
	if (c < -273.15)
	{
		cout << "There is no temperature below -273.15 Celsius degrees";
		return 1;
	}
	else
	{
		double k = 32 + (9. / 5) * c;
		return k;
	}
}

double ftocInputTempCheck(double f) // converting from Fahrenheit to Celsius (FIFTH)
{
	if (f < -459.67)
	{
		cout << "There is no temperature below -459.67 Fahrenheit degrees";
		return 1;
	}
	else
	{
		double k = (5. / 9) * (f - 32);
		return k;
	}
}

double rootsOfQuadraticEquation(double a, double b, double c) // roots of quadratic equation (SIXTH)
{
	if (b * b - 4 * a * c < 0)
	{
		cout << "This equation has no roots that are real numbers \n";
		return 1;
	}
	else
	{
		double delta = sqrt(b * b - 4 * a * c);

		if (delta == 0)
		{
			cout << "There is only one root: \n";

			double x = (-b ) / (2 * a);
			cout << "x is: " << x << " \n";

			return 0;
		}

		else
		{
			double x1 = (-b + delta) / (2 * a);
			cout << "x1 is: " << x1 << " \n";

			double x2 = (-b - delta) / (2 * a);
			cout << "x2 is: " << x2 << " \n";
			return 0;
		}
	}

}

int main()
{
	system("chcp 1250");

	if (FIRST)	// program had errros, below correct version after bug fixing
	{
		double d = 0;
		cout << "Enter temperature in Celsius degrees: \n";
		cin >> d;
						
		double k = ctok(d);
		cout << k << "\n";
	}

	else

	if (SECOND) // added an input tes - while loop
	{
		double d = 0;
		cout << "Enter temperature in Celsius degrees: \n";
		cin >> d;
		while (d < -273.15)
		{
			cout << "There is no temperature below -273.15 Celsius degree, enter again a temperature \n";
			cin >> d;
		}

		double k = ctok(d);
		cout << "Temperature in Kelvin degrees is: \n";
		cout << k << "\n";
	}

	else

	if (THIRD)	// program checks if error in a function "ctokInputTempCheck()"
	{
		double d = 0;
		cout << "Enter temperature in Celsius degrees: \n";
		cin >> d;

		double k = ctok(d);
		cout << k << "\n";
	}

	else

	if (FOURTH)	// converting from Kelvin to Celsius too
	{
		cout << "Do you want to convert Celsius to Kelvin (c) or Kelvin to Clesius (k)?\n";
		cout << "Type 'c' to convert from Celsius to Kelvin or 'k' to convert from Kelvin to Celsius\n";
		char choice;
		cin >> choice;
		cout << "\n";
		int counter = 0;
		while (counter == 0)
		{
			if (choice == 'c')
			{
				double d = 0;
				cout << "Enter temperature in Celsius degrees: \n";
				cin >> d;

				double k = ctokInputTempCheck(d);
				cout << k << "\n";
				counter = 1;
			}
			else
				if (choice == 'k')
				{
					double d = 0;
					cout << "Enter temperature in Kelvin degrees: \n";
					cin >> d;

					double k = ktocInputTempCheck(d);
					cout << k << "\n";
					counter = 1;
				}
				else
				{
					cout << "Invalid choice\n";
					cout << "Type 'c' to convert from Celsius to Kelvin or 'k' to convert from Kelvin to Clesius\n";
					cin >> choice;
					cout << "\n";
				}
		}
	}

	else

	if (FIFTH)	// converting from Fahrenheit to Celsius and inversly too
	{
		cout << "Do you want to convert Celsius to Fahrenheit (c) or Fahrenheit to Clesius (f)?\n";
		cout << "Type 'c' to convert from Celsius to Fahrenheitor or 'f' to convert from Fahrenheit to Celsius\n";
		char choice;
		cin >> choice;
		cout << "\n";
		int counter = 0;
		while (counter == 0)
		{
			if (choice == 'c')
			{
				double d = 0;
				cout << "Enter temperature in Celsius degrees: \n";
				cin >> d;

				double k = ctofInputTempCheck(d);
				cout << k << "\n";
				counter = 1;
			}
			else
				if (choice == 'f')
				{
					double d = 0;
					cout << "Enter temperature in Fahrenheit degrees: \n";
					cin >> d;

					double k = ftocInputTempCheck(d);
					cout << k << "\n";
					counter = 1;
				}
				else
				{
					cout << "Invalid choice\n";
					cout << "Type 'c' to convert from Celsius to Kelvin or 'f' to convert from Fahrenheit to Clesius\n";
					cin >> choice;
					cout << "\n";
				}
		}
	}

	else

	if (SIXTH) // rootS of a quadratic equation
	{
		cout << "Finding roots of a quadratic equation: 'ax2 + bx + c'\n";
		cout << "Type a \n";
		double a;
		cin >> a;
		while (a == 0)
		{
			cout << "'a' can not be equal to zero - then it is not a quadratic equation\n";
			cout << "Enter 'a' again\n";
			cin >> a;
		}

		cout << "Type b \n";
		double b;
		cin >> b;

		cout << "Type c \n";
		double c;
		cin >> c;

		rootsOfQuadraticEquation(a, b, c);
	}

	else

	if (SEVENTH) // a sum of N first numbers typed by user, N is typed by user
	{
		cout << "Enter number N - N is a number of numbers that you want to sum up\n";
		int n;
		cin >> n;
		while (n <= 0)
		{
			cout << "N is an integer bigger than zero\n";
			cout << "Type N again\n";
			cin >> n;
		}

		char end = '1';

		vector<int> numbers;
		int number;
		int sum = 0;

		while (end != '|')
		{
			cout << "Type a number\n";
			cin >> number;
			numbers.push_back(number);
			cout << "Type '|' to finish or 'c' to continue\n"; //program is asking thie question every time
			cin >> end;					// it sholud rather sense if input was '|' character and finish then
			cout << "\n";
		}
	
		int SizeOfNumbers = numbers.size();

		cout << "You have typed: " << SizeOfNumbers << " numbers and N is: " << n << "\n";
		
		while (n > SizeOfNumbers)
		{
			cout << "N is greater than number of all typed numbers\n";
			cout << "Type N again\n";
			cin >> n;
		}
		cout << "Sum of " << n << " first numbers: \n";
		for (int i = 0; i < n; i++)
		{
			cout << numbers[i] << ", ";
			sum = sum + numbers[i];
		}
		cout << " is: " << sum << "\n";
	}

	else

	if (EIGHTH) // same program as above, but there is an error info when sum is not an int value
	{
		cout << "Enter number N - N is a number of numbers that you want to sum up\n";
		int n;
		cin >> n;
		while (n <= 0)
		{
			cout << "N is an integer bigger than zero\n";
			cout << "Type N again\n";
			cin >> n;
		}

		char end = '1';

		vector<int> numbers;
		double number;
		int sum = 0;

		int doubleToInt;

		int check = 0;

		while (end != '|')
		{
			cout << "Type a number\n";
			cin >> number;
			doubleToInt = number; // writing double to int in order to check if this was floating point number
			if (number != doubleToInt) // here is the instruction to check if typed number was floating point
			{
				check = 1;
			}
			numbers.push_back(number);
			cout << "Type '|' to finish or 'c' to continue\n"; //program is asking thie question every time
			cin >> end;					// it sholud rather sense if input was '|' character and finish then
			cout << "\n";
		}

		int SizeOfNumbers = numbers.size();

		cout << "You have typed: " << SizeOfNumbers << " numbers and N is: " << n << "\n";

		while (n > SizeOfNumbers)
		{
			cout << "N is greater than number of all typed numbers\n";
			cout << "Type N again\n";
			cin >> n;
		}

		if (check > 0)
		{
			cout << "At least one of the numbers that you have typed is not an integer value\n";
		}
		else
		{
			cout << "Sum of " << n << " first numbers: \n";
			for (int i = 0; i < n; i++)
			{
				cout << numbers[i] << ", ";
				sum = sum + numbers[i];
			}
			cout << " is: " << sum << "\n";
		}
	}
	
	else

	if (NINTH) //same as SEVENTH, but with additional vector with difference of adjacent numbers
	{
		cout << "Enter number N - N is a number of numbers that you want to sum up\n";
		int n;
		cin >> n;
		while (n <= 0)
		{
			cout << "N is an integer bigger than zero\n";
			cout << "Type N again\n";
			cin >> n;
		}

		char end = '1';

		vector<double> numbers;
		double number;
		double sum = 0;

		vector<double> difference;

		int counter = 0;

		int i = 0;

		int ResultOfDifference = 0;

		while (end != '|')
		{
			cout << "Type a number\n";
			cin >> number;
			numbers.push_back(number);
			counter = counter + 1;
			cout << "Counter is " << counter << "\n";
			if (counter >= 2 && counter < n+1)
			{
				ResultOfDifference = numbers[i + 1] - numbers[i];
				difference.push_back(ResultOfDifference);
				cout << "Index " << i << " of differences vector is " << difference[i] << "\n";
				i++;
			}
			cout << "Type '|' to finish or 'c' to continue\n"; //program is asking thie question every time
			cin >> end;					// it sholud rather sense if input was '|' character and finish then
			cout << "\n";
		}

		int SizeOfNumbers = numbers.size();

		cout << "You have typed: " << SizeOfNumbers << " numbers and N is: " << n << "\n\n";

		while (n > SizeOfNumbers)
		{
			cout << "N is greater than number of all typed numbers\n";
			cout << "Type N again\n";
			cin >> n;
		}

		cout << "Sum of " << n << " first numbers: \n";
		for (int i = 0; i < n; i++)
		{
			cout << numbers[i] << ", ";
			sum = sum + numbers[i];
		}
		cout << " is: " << sum << "\n\n";

		for (int j = 0; j < difference.size(); j++)
		{
			cout << "Index " << j << " is: " << difference[j] << "\n";
		}
		cout << "\n";
	}

	else

	if (TENTH) // Fibonacci numbers, finding biggest Fibonacci number to fit into int type
	{
		vector<int> fibonacci;
		fibonacci.push_back(1);
		fibonacci.push_back(1);
		int sumOfPrevious;

		for (int i = 2; i < 47; i++)
		{
			sumOfPrevious = fibonacci[i-2] + fibonacci[i - 1];
			fibonacci.push_back(sumOfPrevious);
		}

		cout << "Fibonacci numbers: \n";

		for (int i = 40; i < 47; i++)
		{
			cout << i << " = " << fibonacci[i] << "\n";
		}

		// biggest found: 1836311903 (next one was negative, so does not fit into positive values of integer)
	}

	else

	if (ELEVENTH)
	{
		vector<int> numbers = { 1, 2, 3, 4 };
		vector<int> userGuess;
		int guess;

		vector<int> ifIndexAlreadyMatched = { 0, 0, 0, 0 };

		cout << "Guess numbers\n";
		for (int i = 0; i < 4; i++)
		{
			cout << "Enter number\n";
			cin >> guess;
			userGuess.push_back(guess);
		}

		cout << "\n";

		cout << "Your numbers are:\n";
		for (int i = 0; i < 4; i++)
		{
			cout << "Number " << i << " is: " << userGuess[i] << "\n";
		}

		cout << "\n";

		for (int i = 0; i < 4; i++)
		{
				if (userGuess[i] == numbers[i])
				{
					cout << "One bull at index " << i << "\n";
					ifIndexAlreadyMatched[i] = 1;
				}
		}

		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				
				if (ifIndexAlreadyMatched[j] == 1) { }
				else 
				{
					if (userGuess[k] == numbers[j])
					{
						cout << "One cow at index " << k << "\n";
						ifIndexAlreadyMatched[j] = 1;
					}
				}
			}
		}
		// numbers to be guessed: { 1, 2, 3, 4 };
		// program was checked for combinations: {1, 1, 1, 1} (correct result): 1 bull;
		// {1, 1, 2, 1}: 1 bull, 1 cow; {1, 1, 2, 2}: 1 bull, 1 cow (correct result despite two numbers: '2')
		// {1, 2, 3, 4}: 4 bulls; {4, 3, 2, 1}: 4 cows
	}

	else

	if (TWELFTH) // same as above, but many games and different answears - generated at each play
	{
		char gameContinue = 'y';

		while (gameContinue == 'y')
		{

			vector<int> numbers;

			int n;
			
			for (int i = 0; i < 4; i++)
			{
				cout << "To generate random answears enter any number\n";
				cin >> n;
				srand(n);
				numbers.push_back(rand()%10);
			}

			//cout << "Generated numbers are:\n";				// THIS CODE WAS ONLY TO CHECK IF NUMBERS ARE DIFFERENT
			//for (int i = 0; i < 4; i++)						// EVERY TIME A PROGRAM RUNS AGAIN
			//{
			//	cout << "Number " << i << " is: " << numbers[i] << "\n";
			//}

			cout << "\n";

			vector<int> userGuess;
			int guess;

			vector<int> ifIndexAlreadyMatched = { 0, 0, 0, 0 };

			cout << "Guess the numbers that were generated\n";
			for (int i = 0; i < 4; i++)
			{
				cout << "Enter number\n";
				cin >> guess;
				userGuess.push_back(guess);
			}

			cout << "\n";

			cout << "Your numbers are:\n";
			for (int i = 0; i < 4; i++)
			{
				cout << "Number " << i << " is: " << userGuess[i] << "\n";
			}

			cout << "\n";

			for (int i = 0; i < 4; i++)
			{
				if (userGuess[i] == numbers[i])
				{
					cout << "One bull at index " << i << "\n";
					ifIndexAlreadyMatched[i] = 1;
				}
			}

			for (int j = 0; j < 4; j++)
			{
				for (int k = 0; k < 4; k++)
				{

					if (ifIndexAlreadyMatched[j] == 1) {}
					else
					{
						if (userGuess[k] == numbers[j])
						{
							cout << "One cow at index " << k << "\n";
							ifIndexAlreadyMatched[j] = 1;
						}
					}
				}
			}
			cout << "Do you want to finish 'n' or play one more time 'y'?\n";
			cin >> gameContinue;
		}
	}

	else

	if (THIRTEENTH) // pairs of a day and a number, like: Monday 11, Tuesday 14...
	{	//this program is long and not efficient, there are for sure better solitions to this problem
		string day;
		int number;

		vector<int> monday;
		vector<int> tuesday;
		vector<int> wednesday;
		vector<int> thursday;
		vector<int> friday;
		vector<int> saturday;
		vector<int> sunday;

		char check = 'y';

		while (check == 'y')
		{
			for (int i = 0; i < 7; i++)
			{
				cout << "Type a day\n";
				cin >> day;

				cout << "Type a number\n";
				cin >> number;

				if (day == "Monday" || day == "monday" || day == "Mon" || day == "mon")
				{
					monday.push_back(number);
				}

				if (day == "Tuesday" || day == "tuesday" || day == "Tue" || day == "tue")
				{
					tuesday.push_back(number);
				}

				if (day == "Wednesday" || day == "wednesday" || day == "Wed" || day == "wed")
				{
					wednesday.push_back(number);
				}

				if (day == "Thursday" || day == "thursday" || day == "Thu" || day == "thu")
				{
					thursday.push_back(number);
				}

				if (day == "Friday" || day == "friday" || day == "Fri" || day == "fri")
				{
					friday.push_back(number);
				}

				if (day == "Saturday" || day == "saturday" || day == "Sat" || day == "sat")
				{
					saturday.push_back(number);
				}

				if (day == "Sunday" || day == "sunday" || day == "Sun" || day == "sun")
				{
					sunday.push_back(number);
				}
			}
			cout << "Do you want to continue? press 'y' if yes or 'n' if no\n";
			cin >> check;
			cout << "\n";
		}

		int sum = 0;

		cout << "For Monday there are numbers:\n";
		for (int i = 0; i < monday.size(); i++)
		{
			cout << monday[i] << " ";
			sum = sum + monday[i];
		}
		cout << "\n";
		cout << "Sum of this day is: " << sum << "\n";
		cout << "\n";
		sum = 0;

		cout << "For Tuesday there are numbers:\n";
		for (int i = 0; i < tuesday.size(); i++)
		{
			cout << tuesday[i] << " ";
			sum = sum + tuesday[i];
		}
		cout << "\n";
		cout << "Sum of this day is: " << sum << "\n";
		cout << "\n";
		sum = 0;

		cout << "For Wednesday there are numbers:\n";
		for (int i = 0; i < wednesday.size(); i++)
		{
			cout << wednesday[i] << " ";
			sum = sum + wednesday[i];
		}
		cout << "\n";
		cout << "Sum of this day is: " << sum << "\n";
		cout << "\n";
		sum = 0;

		cout << "For Thursday there are numbers:\n";
		for (int i = 0; i < wednesday.size(); i++)
		{
			cout << wednesday[i] << " ";
			sum = sum + thursday[i];
		}
		cout << "\n";
		cout << "Sum of this day is: " << sum << "\n";
		cout << "\n";
		sum = 0;

		cout << "For Friday there are numbers:\n";
		for (int i = 0; i < friday.size(); i++)
		{
			cout << friday[i] << " ";
			sum = sum + friday[i];
		}
		cout << "\n";
		cout << "Sum of this day is: " << sum << "\n";
		cout << "\n";
		sum = 0;

		cout << "For Saturday there are numbers:\n";
		for (int i = 0; i < saturday.size(); i++)
		{
			cout << saturday[i] << " ";
			sum = sum + saturday[i];
		}
		cout << "\n";
		cout << "Sum of this day is: " << sum << "\n";
		cout << "\n";
		sum = 0;

		cout << "For Sunday there are numbers:\n";
		for (int i = 0; i < sunday.size(); i++)
		{
			cout << sunday[i] << " ";
			sum = sum + sunday[i];
		}
		cout << "\n";
		cout << "Sum of this day is: " << sum << "\n";
		cout << "\n";
		sum = 0;
	}
}