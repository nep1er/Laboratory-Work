#include <iostream>
using namespace std;

unsigned long long Factorial(int x)
{
    if (x <= 1)
        return 1;
    return x * Factorial(x - 1);
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
