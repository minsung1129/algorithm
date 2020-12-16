#include <algorithm>
#include <iostream>
using namespace std;

int n;
int nx[] = {-1, 0, 0, 1};
int ny[] = {0, -1, 1, 0};
int arr[102][102];
bool visit[102][102];
int max_ans;

void dfs(int x, int y, int cnt, int h) {
    if (visit[x][y]) return;
    visit[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int dx = x + nx[i];
        int dy = y + ny[i];
        if (dx >= 0 && dx < n && dy >= 0 && dy < n && arr[dx][dy] > h) {
            dfs(dx, dy, cnt, h);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i <= 100; i++) {
        int cnt = 0;
        for (int a = 0; a < n; a++) {
            for (int b = 0; b < n; b++) {
                visit[a][b] = false;
            }
        }

        for (int a = 0; a < n; a++) {
            for (int b = 0; b < n; b++) {
                if (!visit[a][b] && arr[a][b] > i)
                    dfs(a, b, cnt++, i);
            }
        }
        max_ans = max(max_ans, cnt);
    }
    cout << max_ans << endl;
    return 0;
}