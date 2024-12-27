#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int ConvertDec(string N, int p) 
{
    int decValue = 0;

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

        if (value >= p) 
        {
            cout << "Error 3" << endl;
            return -1;
        }

        decValue = decValue * p + value;
    }
    return decValue;
}


string ConvertB(int N, int q) 
{
    if (N == 0) return "0";

    string result;

    while (N > 0) 
    {
        int rem = N % q;

        if (rem < 10) 
        {
            result += (rem + '0');
        }
        else 
        {
            result += (rem - 10 + 'a');
        }
        N /= q;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() 
{
    int p, q;
    string N;

    cin >> p >> q >> N;

    if (p < 2 || p > 36 || q < 2 || q > 36) 
    {
        cout << "Error 1" << endl;
        return 1;
    }

    int declValue = ConvertDec(N, p);
    if (declValue == -1)
    {
        return 1;
    }

    string result = ConvertB(declValue, q);

    cout << result << endl;

    return 0;
}
