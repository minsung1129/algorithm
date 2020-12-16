#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int nx[] = {-1, 0, 0, 1};
int ny[] = {0, -1, 1, 0};
int n, m, k;
int cnt, val;
bool visit[102][102];
pair<int, int> rect[102][2];  // 왼아 x, y | 오위 x, y
vector<int> v;

void dfs(int x, int y, int cnt) {
    if (visit[x][y]) return;
    val++;
    visit[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int dx = x + nx[i];
        int dy = y + ny[i];
        if (dx >= 0 && dx < m && dy >= 0 && dy < n) {
            dfs(dx, dy, cnt);
        }
    }
}

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < k; i++) {
        cin >> rect[i][0].first >> rect[i][0].second >> rect[i][1].first >> rect[i][1].second;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (visit[i][j]) continue;
            for (int a = 0; a < k; a++) {
                if (i >= rect[a][0].first && i < rect[a][1].first && j >= rect[a][0].second && j < rect[a][1].second) {
                    visit[i][j] = true;
                }
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (visit[i][j]) continue;
            val = 0;
            dfs(i, j, cnt++);
            v.push_back(val);
        }
    }
    cout << cnt << endl;
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    return 0;
}