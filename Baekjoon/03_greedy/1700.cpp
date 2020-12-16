#include <iostream>

using namespace std;

int n, k;
int arr[102];
int ans[102];
int ret;

int main() {
    cin >> n >> k;

    for (int i = 0; i < k; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < k; i++) {
        bool flag = false;
        // 이미 꽂혀 있는 경우
        for (int j = 0; j < n; j++) {
            if (ans[j] == arr[i]) {
                flag = true;
                break;
            }
        }
        if (flag) continue;

        //빈 곳이 잇으면 꽂기
        for (int j = 0; j < n; j++) {
            if (ans[j] == 0) {
                ans[j] = arr[i];
                flag = true;
                break;
            }
        }
        if (flag) continue;

        //제일 늦게 꽂을 예정인거 빼고 꽂기
        int tick = -1;
        int index;
        for (int j = 0; j < n; j++) {
            int tmp = 0;
            for (int a = i + 1; a < k; a++) {
                if (ans[j] == arr[a]) break;
                tmp++;
            }
            if (tmp > tick) {
                index = j;
                tick = tmp;
            }
        }

        ret++;
        ans[index] = arr[i];
    }
    cout << ret << endl;
    return 0;
}