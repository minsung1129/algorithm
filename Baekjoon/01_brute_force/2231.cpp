#include <iostream>

using namespace std;

int n;
int arr[10];

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int tmp = i;
        int cmp_n = i;
        while (tmp)
        {
            cmp_n += tmp % 10;
            tmp /= 10;
        }
        if (cmp_n == n)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}