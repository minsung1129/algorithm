#include <algorithm>
#include <iostream>

using namespace std;

int arr[10002];
int d[10002];
int n, k, ans;

/*
6
2
1 6 9 3 6 7
*/
// 1 3 6 6 7 9 => 2 3 0 1 2 => 3 2 2 1 0

int main() {
    cin >> n >> k;
    if (k > n) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    for (int i = 0; i < n - 1; i++) {
        d[i] = arr[i + 1] - arr[i];
    }
    sort(d, d + n - 1);

    for (int i = 0; i < n - k; i++) {
        ans += d[i];
    }
    cout << ans << endl;
    return 0;
}