#include <iostream>
#include <algorithm>
using namespace std;

void next_permut(int a[], int n) 
{
    int k = -1;

    for (int i = n - 2; i >= 0; --i) 
    {
        if (a[i] < a[i + 1]) 
        {
            k = i;
            break;
        }
    }

    if (k == -1) 
    {
        reverse(a, a + n);
        return;
    }

    int l = -1;
    for (int i = n - 1; i > k; --i) 
    {
        if (a[i] > a[k]) 
        {
            l = i;
            break;
        }
    }
    swap(a[k], a[l]);

    reverse(a + k + 1, a + n);
}

int main() 
{
    int n;
    cin >> n;
    int* a = new int[n];

    for (int i = 0; i < n; ++i) 
    {
        cin >> a[i];
    }

    next_permut(a, n);

    for (int i = 0; i < n; ++i) 
    {
        cout << a[i] << " ";
    }
    cout << endl;

    delete[] a;
    return 0;
}
