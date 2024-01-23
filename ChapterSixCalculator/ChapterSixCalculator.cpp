#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

// libraries from author of the book

#include<std_lib_facilities.h>

// Description as in commit:
// ChapterSixCalculator is a working version of a calculator that is a parser analyzer of an input according to the
// grammar rules implemented by its functions. Program handles an inputed characters as tokens and creates a 'stream'
// of those tokens to use numbers, operators and brackets to calculate complex expressions entered by the user

#define FIRST		0	// exemplary code written by author, this program corresponds to the chapter 6.9
                            //"Structure of a program" (calculator considered and developed in chapter 6)
                            // All of its classes and functions are outside main() function
#define SECOND		1	// small changes to the code

using namespace std;

// All classes and functions are outside main() function in this example:
//------------------------------------------------------------------------------

class Token {
public:
    char kind;        // This means what kind of token is this (char or number)
    double value;     // For tokens that are numbers: value of that number
    Token(char ch)    // this creates a token from char from cin input
        :kind(ch), value(0) { }
    Token(char ch, double val)     // this creates a token of number (with its value) kind
        :kind(ch), value(val) { }       // from char from cin input
};
//------------------------------------------------------------------------------

class Token_stream {
public:
    Token_stream();   // creates a Token_stream that takes input from cin stream
    Token get();      // takes a token (function get() is defined somewhere else).
    void putback(Token t);    // puts token back to its place
private:
    bool full;        // checks if there is a token in a buffer
    Token buffer;     // keeps token entered back to its place by function putback()
};
//------------------------------------------------------------------------------

// This constructor sets a value full only in a way that it indicates thath buffer is empty
Token_stream::Token_stream()
    :full(false), buffer(0)    // buffer is empty
{
}

//------------------------------------------------------------------------------

// Function putback() from class Token_stream puts back its argument to the buffer of a stream: Token_stream:
void Token_stream::putback(Token t)
{                   // 
    if (full) error("Function putback() tries to put a token to the buffer that is full.");
    buffer = t;       // This copies 't' to the buffer
    full = true;      // This sets buffer as full ('true' means full)
}
//------------------------------------------------------------------------------

Token Token_stream::get()
{
    if (full) {       // this checks is there a token that is ready
        // is so, then it deletes a token
        full = false;
        return buffer;
    }

    char ch;
    cin >> ch;    // Operator '>>' skips 'white signs' (space, new line, tabs and so on).

    switch (ch) {
    case ';':    // printing (described in a main() function)
    case 'q':    // end of program (also described in a main() function)
    case '(': case ')': case '+': case '-': case '*': case '/':
        return Token(ch);        // each character represents itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    {
        cin.putback(ch);         // this puts digit back to the input stream
        double val;
        cin >> val;              // this reads a floating point number
        return Token('8', val);   // character '8' represents a number (arbitrary chosen)
    }
    default:
        error("Invalid token");
    }
}
//------------------------------------------------------------------------------

Token_stream ts;        // This token delivers to the functions: get() and putback().
//------------------------------------------------------------------------------

double expression();    // Declaration that allows function primary to call a function expression (defined later) 
//------------------------------------------------------------------------------

// Handling numbers and brackets: ()
double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':    // handling: '(' expression ')'
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')') error("')' was expected.");
        return d;
    }
    case '8':            // this character: '8' represents numbers
        return t.value;  // returns a value of a number
    default:
        error("An element was expected.");
    }
}
//------------------------------------------------------------------------------

// Handling: *, / and %.
double term()
{
    double left = primary();
    Token t = ts.get();        // this takes next token from an input stream

    while (true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
        {
            double d = primary();
            if (d == 0) error("Dividing by zero.");
            left /= d;
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);  // puts back 't' to the tokens stream 
            return left;
        }
    }
}
//------------------------------------------------------------------------------

// Handling + and -.
double expression()
{
    double left = term();      // Reads and calculates a value of a component
    Token t = ts.get();        // takes next token from an input stream

    while (true) {
        switch (t.kind) {
        case '+':
            left += term();
            t = ts.get();
            break;
        case '-':
            left -= term();
            t = ts.get();
            break;
        default:
            ts.putback(t);     // Puts back 't' to the tokens stream
            return left;       // no more characters: =, + and -. Returns result
        }
    }
}
//------------------------------------------------------------------------------

int main()
{
    system("chcp 1250");

    if (FIRST)
    {
        try
        {
            double val = 0;
            while (cin) {
                Token t = ts.get();

                if (t.kind == 'q') break; // end of a program
                if (t.kind == ';')        // printing a value of an expression
                    cout << "=" << val << '\n';
                else
                    ts.putback(t);
                val = expression();
            }
        }
        catch (exception& e) {
            cerr << "Error: " << e.what() << '\n';
            return 1;
        }
        catch (...) {
            cerr << "Unknown exception!\n";
            return 2;
        }
    }

    else

    if (SECOND)
    {
        try
        {
            cout << "Welcome to the simple calculator.\n Use floating point numbers in your expressions\n";
            cout << "In order to print a reslut of an expression that you typed use this character: '='\n";
            cout << "In order to close the program use this character: 'x'\n";
            cout << "Those operands are handled by the program: '+', '-', '/', '*' and you can use brackets: '()'\n";

            double val = 0;
            while (cin) {
                Token t = ts.get();

                if (t.kind == 'x') break; // end of a program
                if (t.kind == '=')        // printing a value of an expression
                    cout << "=" << val << '\n';
                else
                    ts.putback(t);
                val = expression();
            }
        }
        catch (exception& e) {
            cerr << "Error: " << e.what() << '\n';
            return 1;
        }
        catch (...) {
            cerr << "Unknown exception!\n";
            return 2;
        }
    }
}