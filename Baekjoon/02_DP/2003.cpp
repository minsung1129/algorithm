#include <iostream>

using namespace std;

int n, m;
int arr[10002];
int rr, ll;
int tmp, ans;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    tmp = arr[0];
    while (ll < n) {
        if (tmp < m) {
            rr++;
            tmp += arr[rr];
        } else {
            if (tmp == m) ans++;
            tmp -= arr[ll];
            ll++;
        }
    }
    cout << ans << endl;
    return 0;
}