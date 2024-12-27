#include <iostream>
using namespace std;

unsigned long long Factorial(int x) 
{
    unsigned long long result = 1;

    for (int i = 2; i <= x; ++i) 
    {
        result *= i;
    }
    return result;
}

unsigned long long BinomCoefficient(int n, int k) 
{
    if (k > n) return 0;
    return Factorial(n) / (Factorial(k) * Factorial(n - k));
}

void PrintPascalTriangle(int N) 
{
    for (int n = 0; n <= N; ++n) 
    {
        for (int k = 0; k <= n; ++k) 
        {
            cout << BinomCoefficient(n, k) << " ";
        }
        cout << endl;
    }
}

int main() 
{
    int N;
    cout << "N: ";
    cin >> N;

    if (N < 1 || N > 20) 
    {
        cout << "Ошибка! 1< N < 20." << endl;
        return 1;
    }

    PrintPascalTriangle(N);

    return 0;
}
