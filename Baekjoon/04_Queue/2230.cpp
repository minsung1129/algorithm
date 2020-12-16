#include <algorithm>
#include <iostream>
using namespace std;

int n, m;
int arr[100002];
int ll, rr;
int tmp_minSub;
//m이상이면서 가장 작은 수 출력
int main() {
    int ans = 2100000000;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    // 1 3 5
    while (rr < n && ll <= rr) {
        if (arr[rr] - arr[ll] < m) {
            rr++;
        } else {
            tmp_minSub = arr[rr] - arr[ll];
            ans = min(tmp_minSub, ans);
            ll++;
        }
    }
    cout << ans << endl;
    return 0;
}