#include <iostream>

unsigned long long BinomCofficent(int n, int k)
{
    if (k > n) return 0;
    if (k > n - k) k = n - k;

    unsigned long long result = 1;

    for (int i = 0; i < k; i++)
    {
        result *= (n - i);
        result /= (i + 1);
    }

    return result;
}


void PrintBinomCofficent(int N)
{
    for (int n = 0; n <= N; n++)
    {
        for (int k = 0; k <= n; k++)
        {
            std::cout << BinomCofficent(n, k) << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    int N;
    std::cout << "N: ";
    std::cin >> N;

    if (N < 0)
    {
        std::cout << "Error 1" << std::endl;
        return 1;
    }

    PrintBinomCofficent(N);

    return 0;
}
