#include <iostream>

using namespace std;

int n, k;
bool visit[100001];
int cnt[100001];
int min_cnt = 987654321;

void dfs(int start, int time) {
    if (start == k) {
        cnt[time]++;
        min_cnt = min(min_cnt, time);
        cout << time << endl;
        return;
    }

    if (start + 1 < 100001 && !visit[start + 1]) {
        visit[start + 1] = true;
        time++;
        dfs(start + 1, time);
        time--;
        visit[start + 1] = false;
    }

    if (start - 1 >= 0 && visit[start - 1]) {
        visit[start - 1] = true;
        time++;
        dfs(start - 1, time);
        time--;
        visit[start - 1] = false;
    }

    if (start * 2 < 100001 && !visit[start * 2]) {
        visit[start * 2] = true;
        time++;
        dfs(start * 2, time);
        time--;
        visit[start * 2] = false;
    }
}

int main() {
    cin >> n >> k;
    visit[n] = true;
    dfs(n, 0);

    cout << min_cnt << endl
         << cnt[min_cnt] << endl;
    return 0;
}