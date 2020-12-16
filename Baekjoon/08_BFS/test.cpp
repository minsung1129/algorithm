#include <iostream>
#include <queue>

using namespace std;

queue<pair<int, int> > q;
int arr[10][10];
bool visit[10][10];
int nx[] = {-1, 0, 0, 1};
int ny[] = {0, -1, 1, 0};

void bfs(int a, int b) {
    q.push(make_pair(a, b));
    visit[a][b] = true;
    int cnt = 0;
    arr[a][b] = cnt;
    while (!q.empty()) {
        int fir = q.front().first;
        int sec = q.front().second;
        q.pop();
        visit[fir][sec] = true;
        for (int i = 0; i < 4; i++) {
            int x = fir + nx[i];
            int y = sec + ny[i];
            if (x >= 0 && x < 10 && y >= 0 && y < 10) {
                if (!visit[x][y]) {
                    q.push(make_pair(x, y));
                    // visit[x][y] = true;
                    arr[x][y] = arr[fir][sec] + 1;
                }
            }
        }
    }
}

int main() {
    bfs(0, 0);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }
    return 0;
}