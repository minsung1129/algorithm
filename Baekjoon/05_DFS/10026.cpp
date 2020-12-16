#include <iostream>
#include <string>
using namespace std;

// R == G , B

string s[102];
int n;
int nx[] = {-1, 0, 0, 1};
int ny[] = {0, -1, 1, 0};
int cnt_nomal, cnt_abnomal;
bool visit[102][102];
bool visit2[102][102];

void dfs(int x, int y, int cnt) {
    if (visit[x][y]) return;
    visit[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int dx = x + nx[i];
        int dy = y + ny[i];

        if (dx >= 0 && dx < n && dy >= 0 && dy < n && s[x][y] == s[dx][dy]) {
            dfs(dx, dy, cnt);
        }
    }
}

void dfs2(int x, int y, int cnt) {
    if (visit2[x][y]) return;
    visit2[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int dx = x + nx[i];
        int dy = y + ny[i];

        if (dx >= 0 && dx < n && dy >= 0 && dy < n) {
            if (s[x][y] != s[dx][dy]) {
                if (s[x][y] == 'B' || s[dx][dy] == 'B') continue;
            }
            dfs2(dx, dy, cnt);
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visit[i][j])
                dfs(i, j, cnt_nomal++);
            if (!visit2[i][j])
                dfs2(i, j, cnt_abnomal++);
        }
    }
    cout << cnt_nomal << " " << cnt_abnomal << endl;
    return 0;
}