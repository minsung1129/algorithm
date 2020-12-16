#include <algorithm>
#include <iostream>

using namespace std;
int n, ans;
pair<int, int> work[1005];
int day[1005];

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.second == b.second) {
        return a.first > b.first;
    } else {
        return a.second > b.second;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> work[i].first >> work[i].second;
    }
    sort(work, work + n, cmp);

    for (int i = 0; i < n; i++) {
        for (int j = work[i].first; j > 0; j--) {
            if (day[j] == 0) {
                day[j] = work[i].second;
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        ans += day[i];
    }
    cout << ans << endl;
    return 0;
}