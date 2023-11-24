#include <iostream>
#include <string.h>
using namespace std;

class RecursiveDescentParser
{
private:
    string inputString;
    int input_pointer;

    bool check(char expected)
    {
        if (input_pointer < inputString.length() && inputString[input_pointer] == expected)
        {
            input_pointer++;
            return true;
        }
        return false;
    }

/* Grammar 
    E -> E + T | T
    T -> T * F | F
    F -> (E) | i
*/
    bool E()
    {
        return T() && E_dash();
    }

    bool E_dash()
    {
        if (check('+'))
        {
            return T() && E_dash();
        }
        return true;
    }

    bool T()
    {
        return F() && T_dash();
    }

    bool T_dash()
    {
        if (check('*'))
        {
            return F() && T_dash();
        }
        return true;
    }

    bool F()
    {
        if (check('('))
        {
            return E() && check(')');
        }
        else if (check('i'))
        {
            return true;
        }
        return false;
    }

public:
    RecursiveDescentParser(string input)
    {
        this->inputString = input;
        this->input_pointer = 0;
    }
    bool parse()
    {
        return E();
    }
};

int main()
{
    string s;
    cout << "Enter a string : ";
    cin >> s;

    RecursiveDescentParser RDP(s);
    string ans = RDP.parse() ? "String Accepted!" : "String Rejected!";
    cout << ans;
    return 0;
}