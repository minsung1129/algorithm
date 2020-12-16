#include <iostream>

using namespace std;

int n, k;
int ll, rr;
int tmp_sum;
int ans;
int arr[10005];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    while (rr < n + 1) {
        if (tmp_sum <= k) {
            if (tmp_sum == k) ans++;
            tmp_sum += arr[rr];
            rr++;
        } else {
            tmp_sum -= arr[ll];
            ll++;
        }
    }
    cout << ans << endl;
    return 0;
}