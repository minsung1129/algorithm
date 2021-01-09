#include <iostream>
#include <string>
#include <vector>

using namespace std;

int arr[1002][1002];
int a, b;
bool tmp1, tmp2, tmp3;
bool flag;

vector<int> solution(int n) {
    vector<int> answer;
    int cnt = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            arr[i][j] = -1;
        }
    }
    while (1) {
        flag = false;
        if (tmp1 == false) {
            if (n == a + 1 || arr[a + 1][b] != -1) tmp1 = true;
            arr[a][b] = cnt++;
            a++;
            continue;
        } else if (tmp2 == false) {
            if (n == b + 1 || arr[a][b + 1] != -1) tmp2 = true;
            b++;
            arr[a][b] = cnt++;
            continue;
        } else if (tmp3 == false) {
            if (arr[a - 1][b - 1] != -1) tmp3 = true;
            a--;
            b--;
            arr[a][b] = cnt++;
            continue;
        } else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < i + 1; j++) {
                    if (arr[i][j] = -1) flag = true;
                }
            }
            if (flag == false) break;
            tmp1 = false;
            tmp2 = false;
            tmp3 = false;
            a++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return answer;
}