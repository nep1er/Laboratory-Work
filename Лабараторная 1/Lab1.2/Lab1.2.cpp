#include <iostream>
using namespace std;

int main() 
{
    setlocale(LC_ALL, "Russian");

    int n;
    cout << "Введите число N: ";
    cin >> n;

    for (int i = 2; i <= n; ++i) 
    {
        bool isPrime = true;

        for (int j = 2; j * j <= i; ++j) 
        {
            if (i % j == 0)
            {
                isPrime = false;
                break;
            }
        }

        if (isPrime)
            cout << i << " ";
    }

    return 0;
}
