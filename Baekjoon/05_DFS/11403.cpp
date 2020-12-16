#include <iostream>

using namespace std;

int n;
int arr[102][102];
int visit[102];

void dfs(int s) {
    for (int i = 0; i < n; i++) {
        if (arr[s][i] && !visit[i]) {
            visit[i] = true;
            dfs(i);
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

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visit[j] = false;
        }
        dfs(i);
        for (int j = 0; j < n; j++) {
            if (visit[j]) arr[i][j] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}