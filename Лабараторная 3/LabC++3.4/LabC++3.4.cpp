#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

double ConvertD(string N, int b) 
{
    double result = 0.0;

    for (int i = 0; i < N.length(); ++i) 
    {
        char c = N[i];
        int value;

        if (c >= '0' && c <= '9') 
        {
            value = c - '0';
        }
        else if (c >= 'a' && c <= 'f') 
        {
            value = c - 'a' + 10;
        }
        else 
        {
            cout << "Error 3" << endl;
            return -1;
        }

        if (value >= b) 
        {
            cout << "Error 4" << endl;
            return -1;
        }
        result += value * (1.0 / pow(b, i + 1));
    }

    return result;
}

int main() 
{
    int b;
    string N;
    cin >> b;

    if (b < 2 || b > 16) 
    {
        cout << "Error 1" << endl;
        return 1;
    }

    cin >> N;

    if (N.length() > 50 || N[0] != '0' || N[1] != '.') 
    {
        cout << "Error 2" << endl;
        return 1;
    }

    double decValue = ConvertD(N.substr(2), b);
    if (decValue == -1)
    {
        return 1;
    }

    cout << fixed << setprecision(5);
    cout << decValue << endl;

    return 0;
}
