#include <iostream>
#include <string>

using namespace std;

int ConvertB(string N, int b) 
{
    int result = 0;
    const char root[] = "0123456789abcdefghijklmnopqrstuvwxyz";

    for (char c : N) 
    {
        int value;
        if (c >= '0' && c <= '9') 
        {
            value = c - '0';
        }
        else if (c >= 'a' && c <= 'z') 
        {
            value = c - 'a' + 10;
        }
        else 
        {
            cout << "Error 2" << endl;
            return -1;
        }

        if (value >= b) 
        {
            cout << "Error 3" << endl;
            return -1;
        }

        result = result * b + value;
    }

    return result;
}

int main() 
{
    int b;
    string N;

    cin >> b;
    cin >> N;

    if (b < 2 || b > 16) 
    {
        cout << "Error 1" << endl;
        return 1;
    }

    int decValue = ConvertB(N, b);
    if (decValue == -1)
    {
        return 1;
    }

    cout << decValue << endl;

    return 0;
}
