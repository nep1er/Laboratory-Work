#include <iostream>
#include <string>
using namespace std;

string ConvertB(double N, int b, int y)
{
    string result = "0.";
    const char roots[] = "0123456789abcdef";

    for (int i = 0; i < y; ++i) 
    {
        N *= b;
        int root = static_cast<int>(N);
        result += roots[root];
        N -= root;
        if (N == 0) break;
    }

    return result;
}

int main() 
{
    int b, y;
    double N;
    cin >> b;
    cin >> y;

    if (b < 2 || b > 16 || y < 1 || y > 20) 
    {
        cout << "Error 1" << endl;
        return 1;
    }

    cin >> N;

    if (N <= 0 || N >= 1) 
    {
        cout << "Error 2" << endl;
        return 1;
    }

    string result = ConvertB(N, b, y);
    cout << result << endl;

    return 0;
}
