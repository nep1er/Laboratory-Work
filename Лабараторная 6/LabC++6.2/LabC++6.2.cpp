#include <iostream>
#include <cmath>
using namespace std;

struct Element {
    double value;
    int original_index;
};

void shake_sort(Element a[], int n)
{
    int start = 0;
    int end = n - 1;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = start; j < end; ++j)
        {
            if (a[j].value > a[j + 1].value)
            {
                swap(a[j], a[j + 1]);
            }
        }
        --end;

        for (int j = end; j > start; --j)
        {
            if (a[j].value < a[j - 1].value)
            {
                swap(a[j], a[j - 1]);
            }
        }
        ++start;
    }
}

int find_closest(Element a[], int n, double x)
{
    int left = 0;
    int right = n - 1;
    int closest_index = 0;
    double closest_diff = fabs(a[0].value - x);

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        double current_diff = fabs(a[mid].value - x);

        if (current_diff < closest_diff)
        {
            closest_diff = current_diff;
            closest_index = mid;
        }

        else if (current_diff == closest_diff && mid < closest_index)
        {
            closest_index = mid;
        }

        if (a[mid].value < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return a[closest_index].original_index;
}

int main()
{
    int n;
    double x;
    cin >> n >> x;
    Element* arr = new Element[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i].value;
        arr[i].original_index = i;
    }

    shake_sort(arr, n);

    cout << find_closest(arr, n, x) << endl;

    return 0;
}
