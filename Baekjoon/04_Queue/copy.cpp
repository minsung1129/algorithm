#include <string.h>

#include <iostream>
#include <vector>

using namespace std;

vector<int> q[25];
char str[21];

int main() {
    int n, k;
    long long int cnt = 0;
    long long int tmp = 0;
    int charlen;

    scanf("%d %d", &n, &k);

    // 이름을 입력 받았을 때 이름 길이에 해당하는
    // q 벡터에 이름이 아닌 그 이름이 나온 순서를 넣어준다.
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        charlen = strlen(str);
        q[charlen].push_back(i);
    }

    for (int i = 2; i <= 20; i++) {
        int idxlen = q[i].size();
        int left = 0, right = 0;
        // 큐가 비어있는 경우 다음 큐로 간다.
        if (!idxlen)
            continue;
        // left가 idxlen(해당하는 큐의 크기)에 도달할 때 까지
        while (left < idxlen - 1) {
            // right가 끝에 도달하지 않았고, 좋은 친구에 해당 될 때
            if (right < idxlen - 1 && q[i][right] - q[i][left] <= k) {
                // right를 한칸 옮겨주고 tmp++
                right++;
                tmp++;
                // right를 한칸 옮겼을 때 q[][right] - q[][left] == k일 때
                if (q[i][right] - q[i][left] == k) {
                    // 모아둔 tmp를 더해주고 left를 한칸 옮기기에 tmp는 하나 빼준다.
                    cnt += tmp;
                    tmp--;
                    left++;
                }
            }
            // 그외 경우
            else {
                // q[][right] - q[][left] <= k 일때만 더해준다.
                if (q[i][right] - q[i][left] <= k)
                    cnt += tmp;

                // 그게 아니라면 tmp -1을 한 값을 더해준다.
                else
                    cnt += tmp - 1;
                tmp--;
                left++;
            }
        }
        // 해당하는 큐가 끝나면 tmp = 0으로 초기화
        tmp = 0;
    }

    printf("%lld", cnt);

    return 0;
}