#include <iostream>
#include <queue>

using namespace std;

int t, n, m;
char c;
char arr[1002][1002];
int nx[] = {-1, 0, 0, 1};
int ny[] = {0, -1, 1, 0};
pair<int, int> start;
queue<pair<int, int> > q;
queue<pair<int, int> > fire;

int bfs(int a, int b) {
    q.push(make_pair(a, b));
    int time = 0;
    while (!q.empty()) {
        time++;
        int wow = fire.size();
        for (int i = 0; i < wow; i++) {
            int fireX = fire.front().first;
            int fireY = fire.front().second;
            fire.pop();
            for (int j = 0; j < 4; j++) {
                int x = fireX + nx[j];
                int y = fireY + ny[j];

                if (x >= 0 && x < n && y >= 0 && y < m) {
                    if (arr[x][y] == '.' || arr[x][y] == '@') {
                        fire.push(make_pair(x, y));
                        arr[x][y] = '*';
                    }
                }
            }
        }
        wow = q.size();
        for (int i = 0; i < wow; i++) {
            int perX = q.front().first;
            int perY = q.front().second;
            q.pop();
            for (int j = 0; j < 4; j++) {
                int xx = perX + nx[j];
                int yy = perY + ny[j];
                if (xx == 0 || xx == n - 1 || yy == 0 || yy == m - 1) {
                    if (arr[xx][yy] == '.') {
                        return time + 1;
                    }
                }
                if (xx >= 0 && xx < n && yy >= 0 && yy < m) {
                    if (arr[xx][yy] == '.') {
                        q.push(make_pair(xx, yy));
                        arr[xx][yy] = '@';
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    cin >> t;
    while (t--) {
        cin >> m >> n;
        while (!q.empty()) {
            q.pop();
        }
        while (!fire.empty()) {
            fire.pop();
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> c;
                arr[i][j] = c;
                if (c == '@') start = make_pair(i, j);
                if (c == '*') fire.push(make_pair(i, j));
            }
        }

        int tmp = bfs(start.first, start.second);
        if (start.first == 0 || start.first == n - 1 || start.second == 0 || start.second == m - 1) {
            cout << 1 << endl;
            continue;
        }
        if (tmp == -1)
            cout << "IMPOSSIBLE" << endl;
        else
            cout << tmp << endl;
    }
    return 0;
}