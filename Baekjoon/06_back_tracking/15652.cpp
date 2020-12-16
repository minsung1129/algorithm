#include <iostream>

using namespace std;

int arr[10];
int n, m;

void dfs(int cnt, int idx) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = idx; i <= n; i++) {
        arr[cnt] = i;
        dfs(cnt + 1, i);
    }
}

int main() {
    cin >> n >> m;
    dfs(0, 1);

    return 0;
}