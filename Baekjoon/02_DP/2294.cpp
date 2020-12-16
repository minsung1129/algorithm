#include <iostream>

using namespace std;

int dp[10002];
int n, k;
int arr[105];

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    dp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i]; j <= k; j++)
        {
            if (j - arr[i] >= 0)
                dp[j] += dp[j - arr[i]];
        }
    }
    return 0;
}
