#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

// libraries from author of the book

#include<std_lib_facilities.h>

// creating a valid code - different versions of a same program - correcting deliberate errors
// aim of code is that program can compile, runs properly and prints: "Well done"

// bonus trick: To move many lines of a text to the left, select full text, then press Shift+Tab.
 
#define FIRST			0		// first version - SIMPLEST, few errors in: cout << "Well done!\n";
#define SECOND			0		// second version  - error with initalizing 'res' variable and with type of vector
#define THIRD			0		// third version - error of specific index brackets - it was v(5) and I changed expression in if
#define FOURTH			0		// fourth version - I have changed condition in if to be true - literally
#define FIFTH			0		// fifth version - I changed condition in if to be true - I added "!"
#define SIXTH			0		// sixth version - I have added 'l' to bool and changed '<' to '>' ("fool" > s)
#define SEVENTH			0		// seventh version - I have changed: (s == "fool") to: (s != "fool")
#define EIGHTH			0		// eighth version - almost the same as above + I have added: '<' - it was: '... cout < ' 
#define NINTH			0		// ninth version - I have erased 's+' in: "s+"fool" and added: '<' 
#define TENTH			0		// tenth version - the loop was infinite, I only changed 0: '0 < v.size()' to i: 'i < v.size()' 
#define ELEVENTH		0		// tenth version - the loop was infinite, I only changed 0: '0 < v.size()' to i: 'i < v.size()' 
#define TWELFTH			0		// twelfth version - I just have erased word: 'then' 
#define THIRTEENTH		0		// thirteenth version - I have found integer value of 'c' (-48) by this code: 'int y = int(c); cout << y << "\n";'   
#define FOURTEENTH		0		// fourtenth version - correct (almost the same as one of previous ones) 
#define FIFTEENTH		0		// fifteenth version - vector had no type ('vector v(5);') 
#define SIXTEENTH		0		// sixteenth version - I have changed the loop instruction, by changing j (++j;) to i (++i;) 
#define SEVENTEENTH		0		// seventeenth version - changed '(x - 2)' to '(x - 1)' and 'this: '(d == 2 * x + 0.5)' to '(d == 2 * (x + 0.5))'
#define EIGHTEENTH		0		// eighteenth version - I changed this: ' string<char> s = ' to this: ' string s = ' 
#define NINETEENTH		0		// nineteenth version - I have changed '++j' to '++i' and '(j<i)' to: '(1<i)'
#define TWENTYTH		1		// twentyth - this one was correct

using namespace std;

int main()
{
	system("chcp 1250");

	if (FIRST)	// first version
	{
		try {
			cout << "Well done 1 !\n";					// code I enter
			keep_window_open();
			return 0;
		}
		catch (exception& e) {
			cerr << "Error: " << e.what() << "\n";
			keep_window_open();
			return 1;
		}
		catch (...) {
			cerr << "Unknown type of exception";
			return 2;
		}
	}

	else

	if (SECOND)	// second version - error with initalizing 'res' variable and with type of vector
	{
		try {
			string res = "7";						// code I enter
			vector<string> v(10);				
			v[5] = res;
			cout << "Well done 2 !\n";				// code I enter
			keep_window_open();
			return 0;
		}
		catch (exception& e) {
			cerr << "Error: " << e.what() << "\n";
			keep_window_open();
			return 1;
		}
		catch (...) {
			cerr << "Unknown type of exception";
			return 2;
		}
	}

	else

	if (THIRD) // third version - error of specific index brackets - it was v(5) and I changed expression in if
	{
		try {
		vector<int> v(10);							// code I enter
		v[5] = 7;
		if (v[5] = 7) cout << "Well done 3 !\n";	// code I enter
		keep_window_open();
		return 0;
		}
		catch (exception& e) {
			cerr << "Error: " << e.what() << "\n";
			keep_window_open();
			return 1;
		}
		catch (...) {
			cerr << "Unknown type of exception";
			return 2;
		}
	}

	else

	if (FOURTH) // fourth version - I changed condition in if to be true - literally
	{
		try {
			if (true)						// code I enter
				cout << "Well done 4 !\n";
			else
				cout << "Wrong ! \n";			// code I enter
			keep_window_open();
			return 0;
		}
		catch (exception& e) {
			cerr << "Error: " << e.what() << "\n";
			keep_window_open();
			return 1;
		}
		catch (...) {
			cerr << "Unknown type of exception";
			return 2;
		}
	}

	else

	if (FIFTH) // fifth version - I changed condition in if to be true - I added "!"
	{
		try {
			bool c = false;					// code I enter
			if (!c) cout << "Well done 5 !\n";
			else cout << "Wrong !\n";			// code I enter
			keep_window_open();
			return 0;
		}
		catch (exception& e) {
			cerr << "Error: " << e.what() << "\n";
			keep_window_open();
			return 1;
		}
		catch (...) {
			cerr << "Unknown type of exception";
			return 2;
		}
	}
	
	else

	if (SIXTH) // sixth version - I have added 'l' to bool and changed '<' to '>' ("fool" > s)
	{
		try {
			string s = "ape";					// code I enter
			bool c = "fool" > s;				// interesting string comparison
			if (c) cout << "Well done 6 !\n";	// code I enter
		keep_window_open();
		return 0;
		}
		catch (exception& e) {
			cerr << "Error: " << e.what() << "\n";
			keep_window_open();
			return 1;
		}
		catch (...) {
			cerr << "Unknown type of exception";
			return 2;
		}
	}

	else

	if (SEVENTH) // seventh version - I have changed: (s == "fool") to: (s != "fool")
	{
		try {
			string s = "ape";							// code I enter
			if (s != "fool") cout << "Well done 7 !\n"; // code I enter
			keep_window_open();
			return 0;
		}
		catch (exception& e) {
			cerr << "Error: " << e.what() << "\n";
			keep_window_open();
			return 1;
		}
		catch (...) {
			cerr << "Unknown type of exception";
			return 2;
		}
	}

	else

	if (EIGHTH) // eighth version - almost the same as above + I have added: '<' - it was: '... cout < '
	{
		try {
			string s = "ape";							// code I enter
			if (s != "fool") cout << "Well done 8 !\n"; // code I enter
			keep_window_open();
			return 0;
			}
		catch (exception& e) {
			cerr << "Error: " << e.what() << "\n";
			keep_window_open();
			return 1;
		}
		catch (...) {
			cerr << "Unknown type of exception";
			return 2;
		}
	}

	else

	if (NINTH) // ninth version - I have erased 's+' in: "s+"fool" and added: '<'
	{
		try {
			string s = "ape";						// code I enter
			if ("fool") cout << "Well done 9 !\n";	// code I enter
			keep_window_open();
			return 0;
		}
		catch (exception& e) {
			cerr << "Error: " << e.what() << "\n";
			keep_window_open();
			return 1;
		}
		catch (...) {
			cerr << "Unknown type of exception";
			return 2;
		}
	}

	else

	if (TENTH) // tenth version - the loop was infinite, I only changed 0: '0 < v.size()' to i: 'i < v.size()'
	{
		try {
			vector<char> v(5);					// code I enter
			for (int i = 0; i < v.size(); ++i);
			cout << "Well done 10 !\n";			// code I enter
			keep_window_open();
			return 0;
		}
		catch (exception& e) {
			cerr << "Error: " << e.what() << "\n";
			keep_window_open();
			return 1;
		}
		catch (...) {
			cerr << "Unknown type of exception";
			return 2;
		}
	}

	else

	if (ELEVENTH) // eleventh version - this one was correct
	{
		try {		//  0123 4 5678 9 10,11 12 13 14 15
			string s = "Well done 11 !\n";				// code I enter
			for (int i = 0; i < 16; i++)
			cout << s[i];								// code I enter
			keep_window_open();
			return 0;
		}
		catch (exception& e) {
			cerr << "Error: " << e.what() << "\n";
			keep_window_open();
			return 1;
		}
		catch (...) {
			cerr << "Unknown type of exception";
			return 2;
		}
	}

	else

	if(TWELFTH) // twelfth version - I just have erased word: 'then'
	{
		try {		
			if (true)						// code I enter
				cout << "Well done 12 !\n";
			else
				cout << "Wrong \n";			// code I enter
			keep_window_open();
			return 0;
		}
		catch (exception& e) {
			cerr << "Error: " << e.what() << "\n";
			keep_window_open();
			return 1;
		}
		catch (...) {
			cerr << "Unknown type of exception";
			return 2;
		}
	}

	else
	
	if(THIRTEENTH) // thirteenth version - I have found integer value of 'c' (-48) by this code: 
	{											          // 'int y = int(c); cout << y << "\n";'
		try {
			int x = 2000;					// code I enter
			char c = x;
			if (c == -48)
				cout << "Well done 13 !\n";	// code I enter
			keep_window_open();
			return 0;
		}
		catch (exception& e) {
			cerr << "Error: " << e.what() << "\n";
			keep_window_open();
			return 1;
		}
		catch (...) {
			cerr << "Unknown type of exception";
			return 2;
		}
	}

	else

	if(FOURTEENTH) // fourtenth version - correct (almost the same as one of previous ones)
	{
		try {
			string s = "Well done 14 !\n";		// code I enter
			for (int i = 0; i < 15; ++i)
				cout << s[i];					// code I enter
			keep_window_open();
			return 0;
		}
		catch (exception& e) {
			cerr << "Error: " << e.what() << "\n";
			keep_window_open();
			return 1;
		}
		catch (...) {
			cerr << "Unknown type of exception";
			return 2;
		}
	}

	else

	if (FIFTEENTH) // fifteenth version - vector had no type ('vector v(5);')
	{
		try {
			vector<int> v(5);						// code I enter
			for (int i = 0; i <= v.size(); ++i);
			cout << "Well done 15 !\n";				// code I enter
			keep_window_open();
			return 0;
		}
		catch (exception& e) {
			cerr << "Error: " << e.what() << "\n";
			keep_window_open();
			return 1;
		}
		catch (...) {
			cerr << "Unknown type of exception";
			return 2;
		}
	}

	else

	if (SIXTEENTH) // sixteenth version - I have changed the loop instruction, by changing j (++j;) to i (++i;)
	{
		try {
			int i = 0; 						// code I enter
			int j = 9;
			while (i < 10)
				++i;
			if (j < i)
				cout << "Well done 16 !\n";	// code I enter
			keep_window_open();
			return 0;
		}
		catch (exception& e) {
			cerr << "Error: " << e.what() << "\n";
			keep_window_open();
			return 1;
		}
		catch (...) {
			cerr << "Unknown type of exception";
			return 2;
		}
	}

	else
		
	if (SEVENTEENTH) // seventeenth version - changed '(x - 2)' to '(x - 1)' and 'this: '(d == 2 * x + 0.5)' to '(d == 2 * (x + 0.5))'
	{
		try {
			int x = 2;						// code I enter
			double d = 5 / (x - 1);
			if (d == 2 * (x + 0.5))
				cout << "Well done 17 !\n";	// code I enter
			keep_window_open();
			return 0;
		}
		catch (exception& e) {
			cerr << "Error: " << e.what() << "\n";
			keep_window_open();
			return 1;
		}
		catch (...) {
			cerr << "Unknown type of exception";
			return 2;
		}
	}
	
	else

	if (EIGHTEENTH) // eighteenth version - I changed this: ' string<char> s = ' to this: ' string s = '
	{
		try {
			string s = "Well done 18 !\n";	// code I enter
			for(int i=0; i<=15; ++i)
				cout << s[i];				// code I enter
			keep_window_open();
			return 0;
		}
		catch (exception& e) {
			cerr << "Error: " << e.what() << "\n";
			keep_window_open();
			return 1;
		}
		catch (...) {
			cerr << "Unknown type of exception";
			return 2;
		}
	}

	else

	if (NINETEENTH) //  nineteenth version - I have changed '++j' to '++i' and '(j<i)' to: '(1<i)'
	{
		try {
			int i = 0;								// code I enter
			while (i < 10) ++i;
			if (1<i) cout << "Well done 19 !\n";	// code I enter
			keep_window_open();
			return 0;
		}
		catch (exception& e) {
			cerr << "Error: " << e.what() << "\n";
			keep_window_open();
			return 1;
		}
		catch (...) {
			cerr << "Unknown type of exception";
			return 2;
		}
	}

	else

	if (TWENTYTH) // twentyth - this one was correct
	{
		try {
			int x = 4;									// code I enter
			double d = 5 / (x - 2);
			if (d=2*x+0.5) cout << "Well done 20 !\n";	// code I enter
			keep_window_open();
			return 0;
		}
		catch (exception& e) {
			cerr << "Error: " << e.what() << "\n";
			keep_window_open();
			return 1;
		}
		catch (...) {
			cerr << "Unknown type of exception";
			return 2;
		}
	}
}