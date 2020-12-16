#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int n, a, b, c;
int ret;
pair<int, int> arr[22];  // 넓이, 갯수

int cal(int a, int b, int c) {
    if (a == 0 || b == 0 || c == 0) return 0;
    for (int i = 0; i < n; i++) {
        if (a >= arr[i].first && b >= arr[i].first && c >= arr[i].first && arr[i].second > 0) {
            ret++;
            arr[i].second--;
            cal(a, b, c - arr[i].first);
            cal(arr[i].first, b - arr[i].first, arr[i].first);
            cal(a - arr[i].first, b, arr[i].first);
            return ret;
        }
    }
    return -1;
}

int main() {
    cin >> a >> b >> c >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
        arr[i].first = pow(2, arr[i].first);
    }
    sort(arr, arr + n);
    reverse(arr, arr + n);
    cout << cal(a, b, c) << endl;
    return 0;
}