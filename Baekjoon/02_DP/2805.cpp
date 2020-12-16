#include <iostream>

using namespace std;

long long int n, m;
long long int arr[1000002];
long long int ll, rr = 1000000001;
long long int ans;

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    while (ll <= rr) {
        long long int mid = (ll + rr) / 2;
        long long int tmp = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] > mid)
                tmp += arr[i] - mid;
        }

        if (tmp >= m) {
            if (ans < mid)
                ans = mid;
            ll = mid + 1;
        } else {
            rr = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}