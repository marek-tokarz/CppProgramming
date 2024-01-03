#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

#define FIRST			0		// improved madian calculation
#define SECOND			0		// calculation of distance between cities	
#define THIRD			0		// 'guessing numbers' program
#define FOURTH			0		// second version of previous program		
#define FIFTH			0		// simple calculator		
#define SIXTH			0		// converting text to numbers and vice versa		
#define SEVENTH			0		// modified calculator	
#define EIGHTH			0		// suming up rice grains at each chessboard field (squares)		
#define NINTH			1		// 'rock, paper, scissors'
#define TENTH			0		// prime numbers from 1 to 100, then from 1 to max - FAILED CODE		
#define ELEVENTH		0		// prime numbers from 1 to max
#define TWELFTH			0		// simplest alghoritm to find prime numbers
#define THIRTEENTH		0		// Erastotenes sieve - I have made alghoritm diagram for this program
#define FOURTEENTH		0		// I enter n and I find n smallest prime numbers
#define FIFTEENTH		0		// dominant of integer numbers set (I have made alghoritm diagram for this program)
#define SIXTEENTH		0		// smallest, biggest number of strings set + dominant
#define SEVENTEENTH		0		// finding a solution for a quadratic equation
#define EIGHTEENTH		0		// pairs: name - number
#define NINETEENTH		0		// also pairs as before - finding number after name
#define TWENTYTH		0		// also pairs as before - finding name after number

using namespace std;

int main()
{
	system("chcp 1250");

	if (FIRST)
	{
		int vector_range;
		double median;
		vector<double> temps;		// temperatures vector
		double temp;
		double help;
		while (cin >> temp)			// entering data
			temps.push_back(temp);	// entering data to the vector
		//average temperature calculation
		double sum = 0;
		vector_range = temps.size();
		for (int i = 0; i < vector_range; ++i)
			sum = sum + temps[i];
		cout << "Average temperature is: " << sum / vector_range << endl;
		// median calculation
		sort(temps.begin(), temps.end());		// sorting 'temps' vector from smallest to biggest

		if (vector_range % 2 == 1)
			cout << "Median (odd number of vector indexes): " << temps[(vector_range) / 2] << "\n";
		else
		{
			help = (vector_range + 1) / 2;
			median = (temps[help - 0.5] + temps[help + 0.5]) / 2;
			cout << "Median (even number of vectro indexes): " << median << "\n";
		}
	}

	if (SECOND)
	{
		vector<double> distances_vector;
		double distance = 0;				// variable initialization is important
		double sum = 0;						// variable initialization is important

		cout << "Enter the distance: \n";

		while (cin >> distance)
		{
			distances_vector.push_back(distance);
			cout << "Enter the distance: \n";
		}

		double range = distances_vector.size();				
		
		cout << "Number of different distances: " << range << "\n";

		for (int i = 0; i < range; i++)
			sum = sum + distances_vector[i];

		cout << "Sum of all distances between cities is " << sum << "\n";

		sort(distances_vector.begin(), distances_vector.end());

		cout << "Smallest distance: " << distances_vector[0] << "\n";
		cout << "Biggest distance: " << distances_vector[range - 1] << "\n";		// last index = range - 1 
		
		cout << "Average distance is " << sum / range << "\n";
	}

	if (THIRD)
	{
		int guessed_number;
		cout << "Enter a guessed number: \n";
		cin >> guessed_number;
		char answear;

		int i = 1;

		cout << "Is this number less or equal to 50? 'y', 'n' \n";
		cin >> answear;
		if (answear == 'y')															 //yes: x <= 50
		{
			cout << "Is this number less or equal to 25? 'y', 'n' \n";
			cin >> answear;
			if (answear == 'y')														//yes: x <= 25 
			{
				cout << "Is this number less or equal to 12? 'y', 'n' \n";
				cin >> answear;														//yes: x <=12
				{
					cout << "Is this number less or equal to 6? 'y', 'n' \n";
					cin >> answear;
					if (answear == 'y')												//yes: x <= 6
					{
						cout << "Is this number less or equal to 3? 'y', 'n' \n";
						cin >> answear;
						if (answear == 'y')											//yes: x <= 3
						{
							cout << "Is this number less or equal to 1? 'y', 'n' \n";
							if (answear == 'y')
							{
								cout << "Is this number is '0'?";
								if (answear == 'y')
									cout << "The number is '0'";
								else
									cout << "The number is '1'";
							}
						}
					}
				}
			}
			else
			{
				cout << "Is this number less or equal to 25? 'y', 'n' \n";
			}

		}
		else																		// x >= 50
		{
			cout << "Is this number bigger or equal to 75? 'y', 'n' \n";
			cin >> answear;
			if (answear == 'y')
			{
				cout << "Is this number bigger or equal to 88? 'y', 'n' \n";
				cin >> answear;
				if (answear == 'y')
				{
					cout << "Is this number bigger or equal to 94? 'y', 'n' \n";
					cin >> answear;
					if (answear == 'y')
					{
						cout << "Is this number bigger or equal to 97? 'y', 'n' \n";
						cin >> answear;
					}
					if (answear == 'y')
					{
						cout << "Is this number bigger or equal to 99? 'y', 'n' \n";
						cin >> answear;
						if (answear == 'y')
						{
							cout << "Is this number is 99? 'y', 'n' \n";
							cin >> answear;
							if (answear == 'y')
							{
								cout << "The number is 99 \n";
								cin >> answear;
							}
							else
								cout << "The number is 100 \n";
						}
					}
				}
			}
		}
	}

	if (FOURTH)
	{
		int guessed_number = 0;
		int real_number = 0;
		cout << "Enter your number: \n";
		cin >> real_number;
		char answear;

		int position = 50;

		int start = 0;

		int end = 100;

		int i = 1;

		while (i)
		{			
			cout << "Is this number is less or equal to: " << position << " ? 'y', 'n'\n";  // index in the middle of range
			cin >> answear;
			if (answear == 'y')									
			{
				guessed_number = position;
				end = position;
				position = (start + end) / 2;
				if (guessed_number == real_number)
				{
					cout << "Podana liczba to było: " << guessed_number;
					i--;
				}
			}
			else												
			{
				guessed_number = position + 1;
				start = position + 1;
				position = (start + 1 + end) / 2;
				if (guessed_number == real_number)
				{
					cout << "Podana liczba to było: " << guessed_number;
					i--;
				}
			}
		}
	}

	if (FIFTH)
	{
		double first_number, second_number;
		char operation;
		char end_program = 'n';

		while (end_program != 'y')
		{

			cout << "Enter first number: \n";
			cin >> first_number;						// przy złej wartości wpisanej do 'cin >> ...' program wpada w jakąś nieskończoną pętlę

			cout << "Enter second number: \n";
			cin >> second_number;						// przy złej wartości wpisanej do 'cin >> ...' program wpada w jakąś nieskończoną pętlę

			cout << "What type of operation do yopu want to choose: '+', '-', '*', '/' \n";
			cin >> operation;
			while (!(operation == '+' || operation == '-' || operation == '*' || operation == '/'))   // ta pętla wykonuje się nieskończoną ilość razy
			{
				cout << "Inapropriate sign was typed, type again: '+', '-', '*', '/' \n";
				cin >> operation;
			}

			switch (operation)
			{
			case '+':
				cout << "Sum of two numbers: " << first_number << " + " << second_number << " = " << first_number + second_number << "\n";
				break;
			case '-':
				cout << "Difference of two numbers: " << first_number << " - " << second_number << " = " << first_number - second_number << "\n";
				break;
			case '*':
				cout << "Product of two numbers: " << first_number << " * " << second_number << " = " << first_number * second_number << "\n";
				break;
			case '/':
				cout << "Quotient of two numbers: " << first_number << " / " << second_number << " = " << first_number / second_number << "\n";
				break;
			default:
				break;
			}

			cout << "Do you want to finish the program? 'y', 'n'\n";
			cin >> end_program;

		}
	}

	if (SIXTH)
	{
		char end_program = 'n';
		vector<string> digits = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};

		int user_digit;

		while (end_program != 'y')
		{
			cout << "Type a digit \n";
			cin >> user_digit;				// if wrong value type, like a sign, there is again a infinte loop

			switch (user_digit)
			{
			case 0:
				cout << digits[0] << "\n";
				break;
			case 1:
				cout << digits[1] << "\n";
				break;
			case 2:
				cout << digits[2] << "\n";
				break;
			case 3:
				cout << digits[3] << "\n";
				break;
			case 4:
				cout << digits[4] << "\n";
				break;
			case 5:
				cout << digits[5] << "\n";
				break;
			case 6:
				cout << digits[6] << "\n";
				break;
			case 7:
				cout << digits[7] << "\n";
				break;
			case 8:
				cout << digits[8] << "\n";
				break;
			case 9:
				cout << digits[9] << "\n";
				break;
			default:
				cout << "No digit was typed \n";
				break;
			}

			string user_digit_letters;
			cout << "Enter in words digit \n";
			cin >> user_digit_letters;

			for (int i = 0; i < 11; i++)
			{
				if (user_digit_letters == digits[i])
					cout << i << "\n";
			}

			cout << "Do you want to finish the program? 'y', 'n'\n";
			cin >> end_program;
		}
	}

	if (SEVENTH)
	{
		char end_program = 'n';

		string first_digit = "0";
		string second_digit = "0";

		double digit_1 = 0;
		double digit_2 = 0;

		char operation;

		vector<string> digits_letters = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

		vector<string> digits = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };

		while (end_program != 'y')
		{
			cout << "Enter first number: \n";
			cin >> first_digit;
			
			for (int i = 0; i < 10; i++)
			{
				if (first_digit == digits_letters[i])
					digit_1 = i;
			}
			
			for (int i = 0; i < 10; i++)
			{
				if (first_digit == digits[i])
					digit_1 = i;
			}
			
			cout << "Enter second number: \n";
			cin >> second_digit;
			for (int i = 0; i < 10; i++)
			{
				if (second_digit == digits_letters[i])
					digit_2 = i;
			}
			for (int i = 0; i < 10; i++)
			{
				if (second_digit == digits[i])
					digit_2 = i;
			}

			cout << "What operation do you want to do: '+', '-', '*', '/' \n";
			cin >> operation;
			while (!(operation == '+' || operation == '-' || operation == '*' || operation == '/'))   // ta pętla wykonuje się nieskończoną ilość razy
			{
				cout << "Inapropirate sign, type again: '+', '-', '*', '/' \n";
				cin >> operation;
			}

			switch (operation)
			{
			case '+':
				cout << "Sum of two numbers: " << digit_1 << " + " << digit_2 << " = " << digit_1 + digit_2 << "\n";
				break;
			case '-':
				cout << "Difference of two numbers: " << digit_1 << " - " << digit_2 << " = " << digit_1 - digit_2 << "\n";
				break;
			case '*':
				cout << "Product of two numbers: " << digit_1 << " * " << digit_2 << " = " << digit_1 * digit_2 << "\n";
				break;
			case '/':
				cout << "Quotient of two numbers: " << digit_1 << " / " << digit_2 << " = " << digit_1 / digit_2 << "\n";
				break;
			default:
				break;
			}

			cout << "Do you want to finish the program? 'y', 'n'\n";
			cin >> end_program;
		}

	}

	if (EIGHTH)
	{
		int field_number = 0;
		double sum = 0;
		int power = 0;
		int field_numbers_count = 0;

		double limit;

		char end_program = 'n';

		while (end_program != 'y')
		{
			cout << "What is the limit? \n";
			cin >> limit;
			cout << "How many fields? \n";
			cin >> field_number;
			for (int i = 0; i < field_number; i++)
			{
				sum = sum + pow(2, i);
				field_numbers_count = i + 1;
				cout << "Current sum of squares of field numbers is: " << sum << "\n";
				cout << "Current number of fields is: " << field_numbers_count << "\n";
				if (sum >= limit)
				{
					cout << "Limit has been reached, sum is: " << sum << "\n";
					cout << "Current number of fields is: " << field_number << "\n";
					break;
				}
			}
			cout << "Do you want to finish the program? 'y', 'n'\n";
			cin >> end_program;
		}
	}

	if (NINTH)
	{
		char end_program = 'n';

		string user_input = "0";

		int number = 0;

		int i = 1;

		int a = 1;

		for (a = 1; a < 5 && end_program != 'y'; a++)
		{
			if (a == 4)
				a = 1;

			cout << "Choose 'rock', 'paper' or 'scissors' \n";
			cin >> user_input;

			i = 1;

			while (i == 1)
			{
				if (user_input == "rock")
				{
					number = 1;
					i = 0;
				}
				else if (user_input == "paper")
				{
					number = 2;
					i = 0;
				}
				else if (user_input == "scissors")
				{
					number = 3;
					i = 0;
				}
				else
				{
					cout << "Wrong value, type again \n";
					cin >> user_input;
				}
			}

			switch (number)
			{
			case 1:
				if (a == 3)
				{
					cout << "Rock wins with scissors \n";
				}
				if (a == 2)
				{
					cout << "Rock loses with paper \n";
				}
				if (a == 1)
				{
					cout << "Rock has a draw with rock \n";
				}
				break;
			case 2:
				if (a == 3)
				{
					cout << "Paper loses with scissors \n";
				}
				if (a == 2)
				{
					cout << "Paper has a draw with paper \n";
				}
				if (a == 1)
				{
					cout << "Paper wins with rock \n";
				}
				break;
			case 3:
				if (a == 3)
				{
					cout << "Scissors have a draw with scissors\n";
				}
				if (a == 2)
				{
					cout << "Scissors win with paper \n";
				}
				if (a == 1)
				{
					cout << "Scissors loose with rock \n";
				}
				break;
			}

			cout << "Do you want to finish the program? 'y', 'n'\n";
			cin >> end_program;   // if I type here: 'rok', 'paper' or 'scissors' program enters the loop 
			
		}



	}

	if (TENTH)

	{
		cout << "Enter max (range of prime numbers search) \n";
		int max;
		cin >> max;
		//0  1  2  3  4   5   6   7   8   9   10  11  12
		vector <int> primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,
							   43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 }; // 25 liczb pierw
		//13  14  15  16  17  18  19  20  21  22  23  24

		vector <int> my_numbers(max);

		int i, a;

		int number;

		int comparison = 0;

		int b = 0;

		for (i = 2; i < max; i++)
		{
			number = i;
			comparison = number;

			cout << "Number according to 'i': " << number << "\n";

			if (b <= max)
			{
				for (a = 0; a <= 24; a++)
				{
					if ((number % primes[a]) == 0 && comparison == number)
					{
						cout << "Primes [a]: " << primes[a] << "\n";
						cout << "Comparison: " << comparison << " number: " << number << "\n";
						my_numbers[b] = number;
						cout << "Number of added number: " << b << " is: " << number << "\n";
						b++;
						cout << "b = " << b << "\n";
					}
				}
			}
		}

		{
			cout << "\n";
			cout << "Prime numbers that has been found: \n";

			for (a = 0; a < max; a++)
			{
				cout << my_numbers[a] << " ";
			}

			cout << "\n";

			for (a = 0; a < max; a++)
			{
				cout << primes[a] << " ";
			}
			cout << "\n";
			cout << "Above prime numbers : \n";
		}

	}

	if (ELEVENTH)
	{
		int a;

		int i = 2;

		int max;

		cout << "Enter value 'max': " << "\n";

		cin >> max;

		int checked_number;

		vector<int> prime_numbers;

		for (checked_number = 2; checked_number < max; checked_number++)
		{
			//cout << "for loop: " << checked_number << "\n";

			a = 1;
			i = 2;

			while (a)
			{
				if (checked_number == i)
				{
					prime_numbers.push_back(checked_number);
					a = 0;
				}
				else if ((checked_number % i) == 0)
						a = 0;
				else
					i++;
			}
			
		}

		cout << "\n";

		cout << "Prime numbers that has been found: \n";

		cout << "\n";

		for (int j = 0; j < prime_numbers.size(); j++)
			cout << prime_numbers[j] << " ";

		cout << "\n";
	}

	if (TWELFTH)
	{
		char end_program = 'n';

		int n;

		int i = 2;

		int a = 1;

			while (end_program != 'y')
			{
				cout << "Enter number 'n': " << "\n";
				cin >> n;
				a = 1;
				i = 2;

				while (a)
				{
					if (n == 1)
					{ 
						cout << "1 is not a prime number \n";
						a = 0;
					}
					else if (n == i)
					{
						cout << n << " is prime number \n";
						a = 0;
					}
					else if (n % i == 0)
					{ 
						cout << n << " is not a prime number \n";
						a = 0;
					}
					else
						i++;
				}
				cout << "Do you want to finish the program? 'y', 'n'\n";
				cin >> end_program;
			}
	}

	if (THIRTEENTH)
	{
		char end_program = 'n';
		
		while (end_program != 'y')
		{
			int n;
			cout << "Enter 'n' number: \n";
			cin >> n;
			double square_root = sqrt(n);

			vector <int> numbers;

			for (int i = 0; i < n+1; i++)
				numbers.push_back(i);
			
			//cout << "Numbers size: " << numbers.size() << "\n";

			//cout << "Entered numbers: \n";

			//for (int i = 0; i < numbers.size(); i++)
			//	cout << "Numbers[" << i << "]: " << numbers[i] << "\n";

			//cout << "Entering numbers has just finished \n";
	
			int x = 1;

			x++;			 // x = 2

			int a = x;		 // a = 2

			int i = 0;

			while (x <= square_root)
			{
				//cout << "First loop \n";
				while (numbers[x] != 0)
				{
					//cout << "Second loop \n";
					i = x;							// i = 2
					while (a * i < n+1)
					{
						//cout << "Third loop \n";
						//cout << "Product of numbers: a*i = \n" << a * i << "\n";
						numbers[a * i] = 0;
						i++;
					}
					x++;
					a = x;
				}
				x++;
				a = x;
			}

			cout << "Prime numbers that has been found: \n";

			for(int i = 2; i < n+1; i++)
			{
				if (numbers[i] != 0)
					cout << numbers[i] << " ";
			}
			cout << "\n";

			cout << "Do you want to finish the program? 'y', 'n'\n";
			cin >> end_program;
		}
	}

	if (FOURTEENTH)
	{
		int n;
		int j = 0;
		cout << "Enter number 'n': \n";
		cin >> n;

		int a;

		int i = 2;

		int checked_number = 1;

		vector<int> prime_numbers;

		while(j < n)
		{
			//cout << "'for' loop: " << checked_number << "\n";
			checked_number++;
			a = 1;
			i = 2;

			while (a)
			{
				if (checked_number == i)
				{
					prime_numbers.push_back(checked_number);
					j++;
					a = 0;
				}
				else if ((checked_number % i) == 0)
					a = 0;
				else
					i++;
			}

		}

		cout << "\n";

		cout << "Prime numbers that has been found: \n";

		cout << "\n";

		for (int j = 0; j < prime_numbers.size(); j++)
			cout << prime_numbers[j] << " ";

		cout << "\n";

	}

	if (FIFTEENTH)
	{
		//char end_program = 'n';

		//while (end_program != 'y')
		//{
			{
				int number = 0;
				vector <int> numbers;
				
				cout << "Type a number \n";

				while (cin >> number)
				{
					numbers.push_back(number);
					cout << "Type a number \n";
				}

				cout << "Entering numbers is finished\n";

				int i = 0;
				int a = i;

				int current_dominant_count = 0;
				int previous_dominant_count = 0;

				int current_dominant = numbers[a];
				int final_dominant = numbers[a];

				int n = numbers.size();

				cout << "Numbers count is: " << n << "\n";

				while (a != n - 1)
				{
					//cout << "First loop\n";
					while (i < n-1)
					{
						//cout << "Second loop, 'i' is: " << i << "\n";
						while (numbers[i + 1] == current_dominant)
						{
							//cout << "Third loop\n";
							current_dominant_count++;
							i++;
							if (current_dominant_count > previous_dominant_count)
								final_dominant = numbers[a];
						}
						i++;
					}
					previous_dominant_count = current_dominant_count;
					a++;
					i = a;
					current_dominant_count = 0;
					current_dominant = numbers[a];
				}

				cout << "Dominant is: " << final_dominant << "\n";
			}
		//	cout << "Zakończyć program? 'y', 'n'\n";
		//	cin >> end_program;                           // here it doesnt take my input
		//}												  // but immediately goes on further											  
	}

	if(SIXTEENTH)
	{
		string word;
		string biggest;
		string smallest;
		int x = 0;
		vector <string> words;

		cout << "Type a word: \n";

		while (cin >> word)
		{
			words.push_back(word);

			if (x == 0)
			{
				biggest = word;
				smallest = word;
			}

			cout << word << "\n";

			if (word > biggest)
			{
				biggest = word;
			}

			if (word < smallest)
			{
				smallest = word;
			}
			x++;
			cout << "Type a word: \n";
		}

		int i = 0;
		int a = i;

		int current_dominant_count = 0;
		int previous_dominant_count = 0;

		string current_dominant = words[a];
		string final_dominant = words[a];

		int n = words.size();

		cout << "Words count is: " << n << "\n";

		while (a != n - 1)
		{
			//cout << "First loop\n";
			while (i < n - 1)
			{
				//cout << "Second loop, 'i' is: " << i << "\n";
				while (words[i + 1] == current_dominant)
				{
					//cout << "Third loop\n";
					current_dominant_count++;
					i++;
					if (current_dominant_count > previous_dominant_count)
						final_dominant = words[a];
				}
				i++;
			}
			previous_dominant_count = current_dominant_count;
			a++;
			i = a;
			current_dominant_count = 0;
			current_dominant = words[a];
		}
		cout << "Dominant is: " << final_dominant << "\n";
	}

	if (SEVENTEENTH)
	{
		char end_program = 'n';

		while (end_program != 'y')
		{
			// finding solutions for quadratic equation
			double a = 0;
			while (a == 0)
			{
				cout << "Type 'a': \n";
				cin >> a;
				if (a == 0)
					cout << "'a' can not be equal to zero \n";
			}

			double b, c;
			cout << "Type b: \n";
			cin >> b;
			cout << "Type c: \n";
			cin >> c;

			double delta = b * b - 4 * c * a;

			cout << "Delta is equal to: " << delta << "\n";

			double x1, x2;

			if (delta == 0)
			{
				cout << "'x1' is equal to: \n" << -b / (2 * a) << "\n";
			}
			else if (delta < 0)
				cout << "There is no solutions for real numbers \n";
			else
			{
				cout << "'x1' is equal to: \n" << (-b - sqrt(delta)) / (2 * a) << "\n";
				cout << "'x2' is equal to: \n" << (-b + sqrt(delta)) / (2 * a) << "\n";
			}
			cout << "Do you want to finish the program? 'y', 'n'\n";
			cin >> end_program;
		}
		                        
	}	

	if (EIGHTEENTH)
	{
		int number = 1;
		string name = "null";

		vector <string> names;
		names.push_back(name);
		vector <int> numbers;
		numbers.push_back(number);

		int i = 0;
		int x = 0;
					
		while (name != "NoName" && number != 0 && x == 0)
		{
			cout << "Type a name: \n";
			cin >> name;
															
			while (i<names.size() && x == 0)
			{
				if (name != names[i])
				{
					i++;
				}
				else
					x = 1;
			}
			names.push_back(name);
			i = 0;
			cout << "Type a number: \n";
			cin >> number;
			numbers.push_back(number);
		}

		if (x == 1)
		{
			cout << "Error, a name that has been typed already exists \n";
		}

		cout << "Names size: " << names.size() << "\n";
		cout << "Numbers size " << numbers.size() << "\n";

		for (int z = 1; z < names.size(); z++)
			cout << z << ": " << names[z] << " " << numbers[z] << "\n";
	}

	if (NINETEENTH)
	{
		int number = 1;
		string name = "null";


		vector <string> names;
		names.push_back(name);
		vector <int> numbers;
		numbers.push_back(number);

		int i = 0;
		int x = 0;

		while (name != "NoName" && number != 0 && x == 0)
		{
			cout << "Type a name: \n";
			cin >> name;

			while (i < names.size() && x == 0)
			{
				if (name != names[i])
				{
					i++;
				}
				else
					x = 1;
			}
			names.push_back(name);
			i = 0;
			cout << "Type a number: \n";
			cin >> number;
			numbers.push_back(number);
		}

		if (names[names.size()-1] == "NoName" || numbers[numbers.size()-1] == 0)
		{
			names.pop_back();
			numbers.pop_back();
		}

		if (x == 1)
		{
			cout << "Error, a name that has been typed already exists \n";
		}

		cout << "Names size: " << names.size()-1 << "\n";
		cout << "Numbers size " << numbers.size()-1 << "\n";

		for (int z = 1; z < names.size(); z++)
			cout << z << ": " << names[z] << " " << numbers[z] << "\n";

		string searched_name;
		cout << "Search for the number connected with name, type name \n";
		cin >> searched_name;

		int k = 1;

		int l = 0;

		while (k < names.size())
		{
			if (searched_name == names[k])
			{
				cout << "Number connected with " << searched_name << " is: " << numbers[k] << "\n";
				break;
				l++;
			}
			k++;
		}

		if (l == 0)
		{
			cout << "Searched name wasn't found \n";
		}
	}

	if (TWENTYTH)
	{
		int number = 1;
		string name = "null";


		vector <string> names;
		names.push_back(name);
		vector <int> numbers;
		numbers.push_back(number);

		int i = 0;
		int x = 0;

		while (name != "NoName" && number != 0 && x == 0)
		{
			cout << "Type a name: \n";
			cin >> name;

			while (i < names.size() && x == 0)
			{
				if (name != names[i])
				{
					i++;
				}
				else
					x = 1;
			}
			names.push_back(name);
			i = 0;
			cout << "Type a number: \n";
			cin >> number;
			numbers.push_back(number);
		}

		if (names[names.size() - 1] == "NoName" || numbers[numbers.size() - 1] == 0)
		{
			names.pop_back();
			numbers.pop_back();
		}

		if (x == 1)
		{
			cout << "Error, a name that has been typed already exists \n";
		}

		cout << "Names size: " << names.size() - 1 << "\n";
		cout << "Numbers size " << numbers.size() - 1 << "\n";

		for (int z = 1; z < names.size(); z++)
			cout << z << ": " << names[z] << " " << numbers[z] << "\n";

		int searched_number;
		cout << "Search for the name connected with number, type number \n";
		cin >> searched_number;

		int k = 1;

		int l = 0;

		while (k < numbers.size())
		{
			if (searched_number == numbers[k])
			{
				cout << "Name connected with " << searched_number << " is: " << names[k] << "\n";
				l++;
				break;
			}
			k++;
		}

		if (l == 0)
		{
			cout << "Searched number wasn't found \n";
		}
	}
}

