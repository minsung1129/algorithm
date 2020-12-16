#include <iostream>

using namespace std;

int n, m;
int arr[10];
bool visit[10];
void dfs(int cnt, int idx) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = idx; i <= n; i++) {
        if (!visit[i]) {
            visit[i] = true;
            arr[cnt] = i;
            dfs(cnt + 1, i + 1);
            visit[i] = false;
        }
    }
}

int main() {
    cin >> n >> m;
    dfs(0, 1);

    return 0;
}