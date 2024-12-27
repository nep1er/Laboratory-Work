#include <iostream>
#include <string>

using namespace std;

string ConvertB(int N, int b) 
{
    string result = "";
    const char root[] = "0123456789abcdefghijklmnopqrstuvwxyz";
    
    while (N > 0) 
    {
        int rem = N % b;
        result = root[rem] + result;
        N /= b;
    }
    
    return result == "" ? "0" : result;
}

int main()
{
    int b, N;
    cin >> b;
    cin >> N;

    if (b < 2 || b > 36) 
    {
        cout << "Error 1" << endl;
        return 1;
    }

    string result = ConvertB(N, b);
    cout << result << endl;
    
    return 0;
}