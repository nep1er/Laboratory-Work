#include <iostream>
#include <vector>
#include <cmath>

int Calculate(int number)
{
    int ki = 0;

    while (number % 2 == 0) 
    {
        number /= 2;
        ki++;
    }

    return pow(2, ki);
}

int main() 
{
    int n;
    std::cin >> n;
    std::vector<int> results;

    for (int i = 0; i < n; ++i) 
    {
        int num;
        std::cin >> num;
        results.push_back(Calculate(num));
    }

    for (int result : results) 
    {
        std::cout << result << std::endl;
    }

    return 0;
}
