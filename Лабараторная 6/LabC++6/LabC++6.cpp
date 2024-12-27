#include <iostream>
using namespace std;

struct Element {
    int value;
    int original_index;
};

void shake_sort(Element a[], int n)
{
    int start = 0;
    int end = n - 1;

    while (start < end)
    {
        for (int i = start; i < end; ++i)
        {
            if (a[i].value > a[i + 1].value)
            {
                swap(a[i], a[i + 1]);
            }
        }
        --end;

        for (int i = end; i > start; --i)
        {
            if (a[i].value < a[i - 1].value)
            {
                swap(a[i], a[i - 1]);
            }
        }
        ++start;
    }
}

int binary_search_with_for(Element a[], int n, int x)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (a[mid].value == x)
        {
            return a[mid].original_index;
        }
        else if (a[mid].value < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int n, x;
    cin >> n >> x;
    Element* a = new Element[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].value;
        a[i].original_index = i;
    }

    shake_sort(a, n);

    int result = binary_search_with_for(a, n, x);
    cout << result << endl;

    return 0;
}
