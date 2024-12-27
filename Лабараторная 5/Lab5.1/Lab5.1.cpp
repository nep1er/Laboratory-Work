#include <iostream> 
using namespace std;

void shake_sort(int a[], int n, int b[])
{
    int start = 0;
    int end = n - 1;

    for (int i = 0; i < n - 1; i++)
    {
        for (int i = start; i < end; ++i)
        {
            if (a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                swap(b[i], b[i + 1]);
            }
        }
        --end;

        for (int i = end; i > start; --i)
        {
            if (a[i] < a[i - 1])
            {
                swap(a[i], a[i - 1]);
                swap(b[i], b[i - 1]);
            }
        }
        ++start;
    }
}

void permut_to_invtab(int a[], int b[], int n) 
{
    for (int i = 0; i < n; ++i) 
    {
        b[i] = 0;
        for (int j = 0; j < i; ++j) 
        {
            if (a[j] > a[i])
            {
                b[i]++;
            }
        }
    }
}


int main() 
{
    int n;
    cin >> n; 
    int a[1000], b[1000];

    for (int i = 0; i < n; ++i) 
    {
        cin >> a[i];
    }

    permut_to_invtab(a, b, n);
    shake_sort(a, n, b);

    for (int i = 0; i < n; ++i) 
    {
        cout << b[i] << " ";
    }
    cout << endl;

    return 0;
}