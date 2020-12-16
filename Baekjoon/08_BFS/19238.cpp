#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, k;
int arr[22][22];
bool visit[22][22];
int a, b, c, d;
int nx[] = {-1, 0, 0, 1};
int ny[] = {0, -1, 1, 0};
pair<int, int> start;
queue<pair<pair<int, int>, int>> q;
vector<pair<pair<int, int>, pair<int, int>>> v;
vector<pair<int, pair<pair<int, int>, pair<int, int>>>> guest_list;

int cal_bfs(int startX, int startY, int destX, int destY) {
    q.push(make_pair(make_pair(startX, startY), 0));
    visit[startX][startY] = true;
    while (!q.empty()) {
        int fir = q.front().first.first;
        int sec = q.front().first.second;
        int time = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x = fir + nx[i];
            int y = sec + ny[i];

            if (x == destX && y == destY) {
                return time + 1;
            }

            if (x >= 0 && x < n && y >= 0 && y < n) {
                if (arr[x][y] != 1 && !visit[x][y]) {
                    q.push(make_pair(make_pair(x, y), time + 1));
                    visit[x][y] = true;
                }
            }
        }
    }
    return -1;
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    cin >> a >> b;
    start.first = a - 1;
    start.second = b - 1;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c >> d;
        v.push_back(make_pair(make_pair(a - 1, b - 1), make_pair(c - 1, d - 1)));
    }
    while (!v.empty()) {
        for (int a = 0; a < n; a++) {
            for (int b = 0; b < n; b++) {
                visit[a][b] = false;
            }
        }
        for (int i = 0; i < m; i++) {
            guest_list.push_back(make_pair(cal_bfs(start.first, start.second, v[i].first.first, v[i].first.second), make_pair(make_pair(a, b), make_pair(c, d))));
            for (int a = 0; a < n; a++) {
                for (int b = 0; b < n; b++) {
                    visit[a][b] = false;
                }
            }
        }

        sort(guest_list.begin(), guest_list.end());
        for (int i = 0; i < guest_list.size(); i++) {
            cout << guest_list[i].first << endl;
        }
        cout << endl;

        start.first = guest_list[0].second.first.first;
        start.second = guest_list[0].second.first.second;

        k -= guest_list[0].first;
        int len = cal_bfs(start.first, start.second, guest_list[0].second.second.first, guest_list[0].second.second.second);
        k -= len;
        // cout << start.first << " " << start.second << endl;
        if (k < 0) {
            cout << -1 << endl;
            return 0;
        }
        k += len * 2;

        for (int i = 0; i < m; i++) {
            if (v[i].first.first == start.first && v[i].first.second == start.second) {
                v.erase(v.begin() + i);
            }
        }
    }
    cout << k << endl;
    return 0;
}