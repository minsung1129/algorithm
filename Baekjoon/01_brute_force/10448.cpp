#include <iostream>

using namespace std;

int arr[1000];
int n, t;

int main()
{
    cin >> t;
    int tmp = 1;
    for (int i = 0; i < 1000; i++)
    {
        arr[i] += tmp;
        tmp += i + 2;
    }
    while (t--)
    {
        bool flag = false;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            if (flag)
                break;
            for (int j = 0; j < n; j++)
            {
                if (flag)
                    break;
                for (int k = 0; k < n; k++)
                {
                    if (arr[i] + arr[j] + arr[k] > n)
                        continue;
                    if (arr[i] + arr[j] + arr[k] == n)
                    {
                        cout << 1 << endl;
                        flag = true;
                        break;
                    }
                }
            }
        }
        if (flag == false)
            cout << 0 << endl;
    }

    return 0;
}