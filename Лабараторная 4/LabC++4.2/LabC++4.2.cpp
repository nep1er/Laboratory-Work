#include <iostream>

int Reverse(int n)
{
    int revers = 0;

    for (int i = 0; i < 32; i++)
    {
        revers = (revers << 1) | (n & 1);
        n >>= 1;
    }

    return revers;
}

void PrintBin(int n) 
{
    for (int i = 31; i >= 0; --i) 
    {
        std::cout << ((n >> i) & 1);
    }
    std::cout << std::endl;
}

int main() 
{
    int n;
    std::cin >> n;

    PrintBin(n);

    int reversed = Reverse(n);
    std::cout << reversed << std::endl;

    PrintBin(reversed);

    return 0;
}