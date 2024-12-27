#include <iostream>
#include <string>
#include <cmath>
#include <cctype>

using namespace std;

int CharValue(char c)
{
    if (isdigit(c))
    {
        return c - '0';
    }
    else if (isalpha(c))
    {
        return tolower(c) - 'a' + 10;
    }
    return -1;
}

char ValueChar(int value) 
{
    if (value < 10)
    {
        return '0' + value;
    }
    else 
    {
        return 'a' + (value - 10);
    }
}

bool FromBtoDec(string A, int b1, double& decValue)
{
    size_t dotPos = A.find('.');
    string intPart = (dotPos == string::npos) ? A : A.substr(0, dotPos);
    string frac = (dotPos == string::npos) ? "" : A.substr(dotPos + 1);

    decValue = 0;
    for (char c : intPart) 
    {
        int value = CharValue(c);

        if (value < 0 || value >= b1) 
        {
            return false;
        }

        decValue = decValue * b1 + value;
    }

    double fracValue = 0.0, fracB = 1.0;

    for (char c : frac) 
    {
        int value = CharValue(c);

        if (value < 0 || value >= b1) 
        {
            return false;
        }
        fracB *= b1;
        fracValue += value / fracB;
    }

    decValue += fracValue;
    return true;
}

string FromDecBase(double decValue, int b2, int k)
{
    long long intPart = static_cast<long long>(decValue);
    double frac = decValue - intPart;

    string result;
    if (intPart == 0) 
    {
        result = "0";
    }
    else 
    {
        while (intPart > 0) 
        {
            result = ValueChar(intPart % b2) + result;
            intPart /= b2;
        }
    }

    if (k > 0) 
    {
        result += '.';
        while (k--) 
        {
            frac *= b2;
            int fracInt = static_cast<int>(frac);
            result += ValueChar(fracInt);
            frac -= fracInt;
            if (frac == 0.0) break;
        }
    }

    return result;
}

int main() 
{
    int b1, b2, k;
    string A;

    cin >> b1 >> b2 >> k;
    cin >> A;

    double decValue;
    if (!FromBtoDec(A, b1, decValue))
    {
        cout << "N0" << endl;
        return 0;
    }

    string result = FromDecBase(decValue, b2, k);
    cout << result << endl;
    return 0;
}
