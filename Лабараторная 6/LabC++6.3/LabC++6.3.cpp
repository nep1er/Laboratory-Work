#include <iostream>
#include <string>
using namespace std;

void search(string T, string P)
{
    int N = T.length();
    int M = P.length();

    int* positions = new int[N];
    int count = 0;

    for (int i = 0; i <= N - M; ++i)
    {
        bool match = true;

        for (int j = 0; j < M; ++j)
        {
            if (T[i + j] != P[j])
            {
                match = false;
                break;
            }
        }

        if (match)
        {
            positions[count++] = i;
        }
    }

    cout << count << endl;
    for (int i = 0; i < count; ++i)
    {
        cout << positions[i] << endl;
    }

}

int main()
{
    string T, P;
    cin >> T >> P;
    search(T, P);
    return 0;
}
