#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int a, b;
int arr[302][302];
int brr[302][302];
bool visit[302][302];
int nx[] = {-1, 0, 0, 1};
int ny[] = {0, -1, 1, 0};
queue<pair<int, int> > q;

void wow() {
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            if (arr[i][j]) {
                int cnt = 0;
                for (int k = 0; k < 4; k++) {
                    int x = i + nx[k];
                    int y = j + ny[k];
                    if (x >= 0 && x < a && y >= 0 && y < b) {
                        if (arr[x][y] == 0) cnt++;
                    }
                }
                brr[i][j] = max(arr[i][j] - cnt, 0);
            }
        }
    }

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            arr[i][j] = brr[i][j];
        }
    }
}

void bfs(int aa, int bb) {
    q.push(make_pair(aa, bb));
    visit[aa][bb] = true;

    while (!q.empty()) {
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int fir = xx + nx[i];
            int sec = yy + ny[i];

            if (fir >= 0 && fir < a && sec >= 0 && sec < b) {
                if (!visit[fir][sec] && arr[fir][sec] != 0) {
                    q.push(make_pair(fir, sec));
                    visit[fir][sec] = true;
                }
            }
        }
    }
}

int cal() {
    int time = 0;
    while (1) {
        int num = 0;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if (!visit[i][j] && arr[i][j] != 0) {
                    bfs(i, j);
                    num++;
                }
            }
        }
        if (num >= 2) return time;
        if (num == 0) return 0;
        time++;
        wow();

        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                visit[i][j] = false;
            }
        }
    }
}

int main() {
    cin >> a >> b;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cin >> arr[i][j];
        }
    }
    cout << cal();

    return 0;
}