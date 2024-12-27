#include <iostream>

int Longest(int n)
{
    int max = 0;
    int current = 0;

    for (int i = 0; i < 32; i++)
    {
        if (n & (1 << i))
        {
            current++;
            if (current > max)
            {
                max = current;
            }
        }
        else
        {
            current = 0;
        }
    }

    return max;
}

int main()
{
    int n;
    std::cin >> n;
    std::cout << Longest(n) << std::endl;
    return 0;
}
