#include <algorithm>
#include <iostream>
using namespace std;

int n, d, k, c;
int arr[33012];
int kind[3002];
int ans, max_tmp;
//접시의 수 N, 초밥의 가짓수 d, 연속해서 먹는 접시의 수 k, 쿠폰 번호 c
/*
8 30 4 30
7
9
7
30
2
7
9
25
*/
int main() {
    cin >> n >> d >> k >> c;
    int ll, rr = k - 1;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = n; i < n + k; i++) {
        arr[i] = arr[i - n];
    }
    kind[c]++;
    for (int i = 0; i < k; i++) {
        kind[arr[i]]++;
    }
    while (1) {
        if (rr == n + k) break;
        max_tmp = 0;
        for (int i = 0; i <= 3000; i++) {
            if (kind[i] > 0) max_tmp++;
        }
        kind[arr[ll]]--;
        rr++;
        ll++;
        kind[arr[rr]]++;
        ans = max(ans, max_tmp);
    }
    cout << ans << endl;
    return 0;
}