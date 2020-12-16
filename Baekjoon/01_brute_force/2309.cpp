#include <iostream>
#include <algorithm>

using namespace std;
int arr[10];

void cal(int *arr)
{
    int sum = 0;
    for (int i = 0; i < 9; i++)
    {
        sum += arr[i];
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            if (sum - arr[i] - arr[j] == 100)
            {
                arr[i] = -1;
                arr[j] = -1;
                return;
            }
        }
    }
    return;
}

int main()
{
    for (int i = 0; i < 9; i++)
    {
        cin >> arr[i];
    }

    cal(arr);
    sort(arr, arr + 9);

    for (int i = 0; i < 9; i++)
    {
        if (arr[i] == -1)
            continue;
        cout << arr[i] << endl;
    }

    return 0;
}