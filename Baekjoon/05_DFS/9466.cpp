#include <iostream>

using namespace std;

int n, t, cnt;
int arr[100002];
int visit[100002];  // -1 : 찐따, 0 아직 , 1 팀
bool done[100002];

void dfs(int num) {
    if (visit[num] == -1 || done[num]) return;

    if (visit[num] == 0)
        visit[num] = 1;
    else if (visit[num] == 1) {
        done[num] = true;
        cnt++;
    }

    dfs(arr[num]);
    visit[num] = -1;
}

int main() {
    cin >> t;

    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        for (int i = 1; i <= n; i++) {
            if (visit[i] == 0) dfs(i);
        }
        cout << n - cnt << endl;
        for (int i = 1; i <= n; i++) {
            arr[i] = 0;
            visit[i] = 0;
            done[i] = false;
        }
        cnt = 0;
    }
    return 0;
}