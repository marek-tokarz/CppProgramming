#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

#define FIRST		0		// loading and printing two words in one loop cycle
#define SECOND		0		// loading of a numbers, checking if it is the samlles/biggest of all numbers so far
#define THIRD		0		// loading of numbers like in program as before + unit
using namespace std;

//void number_operations(double number, int a, double &biggest, double &smallest);

inline void keep_window_open() { char ch; cin >> ch; }

int main()
{
	system("chcp 1250");

	if (FIRST)
	{
		int number = 0;
		string word_1;
		string word_2;
		double number_1 = 0;
		double number_2 = 0;
		int condition = 1;

		while (condition)
		{
			cout << "Give a first number" << endl;
			if (cin >> word_1)							// wczytuje jako string
				if (word_1 == "|")						// badam czy to znak "|"
				{
					condition = 0;
					break;
				}
				else
					number_1 = stod(word_1);
			cout << number_1 << endl;

			cout << "Give a second number" << endl;
			if (cin >> word_2)							// wczytuje jako string
				if (word_2 == "|")						// badam czy to znak "|"
				{
					condition = 0;
					break;
				}
				else
					number_2 = stod(word_2);
			cout << number_2 << endl;

			if (fabs(number_1 - number_2) < 1.0 / 100.0)
				cout << "Numbers are almost equal" << endl;
			else
				if (number_2 > number_1)
					cout << "Second number is bigger" << endl;
				else
					if (number_2 < number_1)
						cout << "First number is bigger" << endl;
					else
						cout << "Numbers are equal";
		}
	}

	if (SECOND)
	{
		double number = 0;
		double biggest;
		double smallest;
		int a = 0;

		cout << "Give a number\n";

		while (cin >> number)
		{
			if (a == 0)
			{
				biggest = number;
				smallest = number;
			}

			cout << number << endl;

			if (number > biggest)
			{
				biggest = number;
				cout << "This is the biggest of all numbers so far\n";
			}

			if (number < smallest)
			{
				smallest = number;
				cout << "This is the smallest of all numbers so far\n";
			}

			a++;

			cout << "Give a number \n";
		}
	}

	if (THIRD)
	{
		vector<double> numbers_vector;
		double number = 0;
		double biggest;
		double smallest;
		int a = 0;
		string unit;
		int number_count = 0;
		double numbers_sum = 0;

		cout << "Give a number \n";

		while (cin >> number)
		{
			number_count = number_count + 1;				// it should not add a number to the counter
			numbers_sum = numbers_sum + number;				// if I loaded it incorrectly - because I gave a wrong unit

			cout << "Give a unit ('inch', 'm', 'feet') \n";
			cin >> unit;
			//cout << "\n";
			if (unit == "cm")
			{
				number = number * 0.01;		// ------------------		// konwersja do metrów
				numbers_vector.push_back(number);
				if (a == 0)
				{
					biggest = number;
					smallest = number;
					a++;
				}

				cout << "Number in meters: " << number << "\n\n";

				if (number > biggest)
				{
					biggest = number;
					cout << "This is the biggest of numbers so far\n";
				}

				if (number < smallest)
				{
					smallest = number;
					cout << "This is the smallest of numbers so far \n";
				}

			}
			else
				if (unit == "m")
				{								// ------------------	// no conversion
					numbers_vector.push_back(number);
					if (a == 0)
					{
						biggest = number;
						smallest = number;
						a++;
					}

					cout << "Number in meters: " << number << "\n\n";

					if (number > biggest)
					{
						biggest = number;
						cout << "This is the biggest of numbers so far \n";
					}

					if (number < smallest)
					{
						smallest = number;
						cout << "This is the smallest of numbers so far \n";
					}

				}
				else
					if (unit == "inch")
					{
						number = number * 0.0254;		// -------		// conversion from inches to meters
						numbers_vector.push_back(number);
						if (a == 0)
						{
							biggest = number;
							smallest = number;
							a++;
						}

						cout << "Number in meters: " << number << "\n\n";

						if (number > biggest)
						{
							biggest = number;
							cout << "This is the biggest of numbers so far  \n";
						}

						if (number < smallest)
						{
							smallest = number;
							cout << "This is the smallest of numbers so far \n";
						}

					}
					else
						if (unit == "feet")
						{
							number = number * 0.3048;		//---		// conversion from feet to meters
							numbers_vector.push_back(number);
							if (a == 0)
							{
								biggest = number;
								smallest = number;
								a++;
							}

							cout << "Number in meters: " << number << "\n\n";

							if (number > biggest)
							{
								biggest = number;
								cout << "This is the biggest of entered numbers \n";
							}

							if (number < smallest)
							{
								smallest = number;
								cout << "This is the samllest of entered numbers \n";
							}
						}
						else
							cout << "Wrong unit! \n";
			cout << "Enter number \n";
		}

		cout << "Sum of all entered numbers: " << numbers_sum << "\n";
		cout << "Amount of entered numbers: " << number_count << "\n";
		cout << "Smallest number: " << smallest << "\n";
		cout << "Biggest number: " << biggest << "\n";

		cout << "All numbers that had been entered: \n";

		sort(numbers_vector.begin(), numbers_vector.end());

			for (int j = 0; j < numbers_vector.size(); ++j)
			{
				cout << numbers_vector[j] << "\t";
				if (j % 5 == 0)							// dividing by 5 and usuing reminder has no sense, 
					cout << "\n";						// because it prints one number and puts 'endl' then
			}
	}
}
