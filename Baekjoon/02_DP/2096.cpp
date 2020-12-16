#include <algorithm>
#include <iostream>
using namespace std;

int n;
int a, b, c;
int dp[100003][3];
int dp2[100003][3];
int arr[100003][3];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];

    dp2[0][0] = arr[0][0];
    dp2[0][1] = arr[0][1];
    dp2[0][2] = arr[0][2];

    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + arr[i][0];
        dp[i][1] = max(max(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]) + arr[i][1];
        dp[i][2] = max(dp[i - 1][2], dp[i - 1][1]) + arr[i][2];
    }

    for (int i = 1; i < n; i++) {
        dp2[i][0] = min(dp2[i - 1][0], dp2[i - 1][1]) + arr[i][0];
        dp2[i][1] = min(min(dp2[i - 1][0], dp2[i - 1][1]), dp2[i - 1][2]) + arr[i][1];
        dp2[i][2] = min(dp2[i - 1][2], dp2[i - 1][1]) + arr[i][2];
    }

    int num1 = max(max(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]);
    int num2 = min(min(dp2[n - 1][0], dp2[n - 1][1]), dp2[n - 1][2]);
    cout << num1 << " " << num2 << endl;
    return 0;
}