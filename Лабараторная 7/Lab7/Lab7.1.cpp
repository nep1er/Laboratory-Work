#include <iostream>
using namespace std;

void ins_sort(int a[], int n) 
{
    for (int i = 1; i < n; ++i) 
    {
        int current = a[i];
        int position = i;

        for (int j = i - 1; j < i; --j) 
        {
            if (a[j] > current) 
            {
                a[j + 1] = a[j];
                position = j;
            }
            else 
            {
                break;
            }
        }

        a[position] = current;
    }
}

void select_sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;

        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min_index])
            {
                min_index = j;
            }
        }


        int temp = a[i];
        a[i] = a[min_index];
        a[min_index] = temp;
    }
}


void shake_sort(int a[], int n) 
{
    int start = 0;
    int end = n - 1;

    for (int i = 0; i< n-1; i++)
    {
        for (int i = start; i < end; ++i) 
        {
            if (a[i] > a[i + 1]) 
            {
                swap(a[i], a[i + 1]);
            }
        }
        --end;

        for (int i = end; i > start; --i) 
        {
            if (a[i] < a[i - 1]) 
            {
                swap(a[i], a[i - 1]);
            }
        }
        ++start;
    }
}

int main()
{
    int n;
    std::cin >> n;
    int* nums = new int[n];

    for (int i = 0; i < n; ++i) 
    {
        std::cin >> nums[i];
    }

    //ins_sort(nums, n);
    //select_sort(nums, n);
    shake_sort(nums, n);

    for (int i = 0; i < n; ++i) 
    {
        std::cout << nums[i] << " ";
    }
    return 0;
}
