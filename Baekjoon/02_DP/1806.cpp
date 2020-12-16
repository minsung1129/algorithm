#include <algorithm>
#include <iostream>
using namespace std;

int n, m;
int arr[100002];
int tmp, ret = 999999;
int rr, ll;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    tmp = arr[0];
    while (rr < n) {
        if (tmp < m) {
            rr++;
            tmp += arr[rr];
        } else {
            ret = min(ret, rr - ll + 1);
            tmp -= arr[ll];
            ll++;
        }
    }
    if (ret == 999999)
        cout << 0 << endl;
    else
        cout << ret << endl;
    return 0;
}