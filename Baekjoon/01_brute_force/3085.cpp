#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int n;
string s[52];
int nx[] = {-1, 0, 0, 1};
int ny[] = {0, -1, 1, 0};
int ans;

int cal() {
    int cnt1 = 1;
    int cnt2 = 1;
    int ret1 = 1;
    int ret2 = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (s[i][j] == s[i][j + 1]) {
                cnt1++;
            } else {
                ret1 = max(cnt1, ret1);
                cnt1 = 1;
            }
        }
        for (int j = 0; j < n - 1; j++) {
            if (s[j][i] == s[j + 1][i]) {
                cnt2++;
            } else {
                ret2 = max(cnt2, ret2);
                cnt2 = 1;
            }
        }
        ret1 = max(cnt1, ret1);
        cnt1 = 1;
        ret2 = max(cnt2, ret2);
        cnt2 = 1;
    }
    return max(ret1, ret2);
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 4; k++) {
                if (i + nx[k] < 0 || i + nx[k] >= n || j + ny[k] < 0 || j + ny[k] >= n)
                    continue;
                char tmp = s[i][j];
                s[i][j] = s[i + nx[k]][j + ny[k]];
                s[i + nx[k]][j + ny[k]] = tmp;
                // swap(s[i + nx[k]][j + ny[k]], s[i][j]);
                ans = max(ans, cal());
                // swap(s[i + nx[k]][j + ny[k]], s[i][j]);
                s[i + nx[k]][j + ny[k]] = s[i][j];
                s[i][j] = tmp;
            }
        }
    }
    cout << ans << endl;
    return 0;
}