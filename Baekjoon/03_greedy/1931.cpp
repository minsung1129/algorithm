#include <algorithm>
#include <iostream>

using namespace std;

int n, ans;
pair<int, int> v[100005];
pair<int, int> cur;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> v[i].second >> v[i].first;
    }
    sort(v, v + n);
    cur = v[0];
    ans = 1;
    for (int i = 0; i < n; i++) {
        if (cur.first > v[i].second) continue;
        cur = v[i];
        ans++;
    }
    cout << ans << endl;
    return 0;
}