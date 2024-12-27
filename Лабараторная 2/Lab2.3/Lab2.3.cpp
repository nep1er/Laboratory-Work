#include <iostream>
using namespace std;

unsigned long long PascalTriangle(int n, int k)
{
    if (k == 0 || k == n) return 1;
    return PascalTriangle(n - 1, k - 1) + PascalTriangle(n - 1, k);
}

void PrintPascalTriangleRecursive(int N)
{
    for (int n = 0; n <= N; ++n) 
    {
        for (int k = 0; k <= n; ++k) 
        {
            cout << PascalTriangle(n, k) << " ";
        }
        cout << endl;
    }
}

int main() 
{
    int N;
    cout << "N: ";
    cin >> N;

    if (N < 1 || N > 31) 
    {
        cout << "Ошибка! 1 < N < 31." << endl;
        return 1;
    }

    PrintPascalTriangleRecursive(N);

    return 0;
}
