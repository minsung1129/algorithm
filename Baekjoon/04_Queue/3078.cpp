#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> v[22];
int n, k;
string s;
int ans;

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> s;
        v[s.size()].push_back(i);
    }

    for (int i = 1; i <= 20; i++) {
        int ll = 0;
        int rr = 0;
        if (v[i].size() == 0) continue;
        while (1) {
            cout << ll << " ll " << rr << " rr" << endl;
            if (rr == v[i].size() - 1 && ll == rr) break;
            if (rr == ll) {
                rr++;
                continue;
            }
            if (v[i][rr] - v[i][ll] <= k) {
                ans++;
                if (rr < v[i].size() - 1)
                    rr++;
                else
                    ll++;
            } else {
                ll++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}