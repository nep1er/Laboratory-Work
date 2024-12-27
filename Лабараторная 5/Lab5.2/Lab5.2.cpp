#include <iostream>
using namespace std;

int invtab_to_permut(int b[], int a[], int n) 
{
    bool used[1000] = { false };

    for (int i = 0; i < n; ++i) 
    {
        int inversions = b[i];
        int pos = 0;

        while (pos < n && inversions >= 0)
        {
            if (!used[pos]) 
            {
                --inversions;
            }
            if (inversions >= 0)
            {
                ++pos;
            }
        }

        if (pos >= n || used[pos]) 
        {
            return 0;
        }

        a[pos] = i + 1;
        used[pos] = true;
    }

    return 1;
}

int main() 
{
    int n;
    cin >> n;

    int b[1000], a[1000];

    for (int i = 0; i < n; ++i) 
    {
        cin >> b[i];
    }

    if (invtab_to_permut(b, a, n))
    {
        for (int i = 0; i < n; ++i) 
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
