#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(int bl, int weight, vector<int> tw) {
    int answer = 0;
    int time = 0;
    int cur = 0;
    queue<int> q;

    for (int i = 0; i < tw.size(); i++) {
        while (1) {
            if (q.size() == bl) {  // 트럭이 다리에서 내려올때
                cur -= q.front();
                q.pop();
            } else {
                if (cur + tw[i] <= weight) {  //다리에 트럭이 더 올라갈 수 있을때
                    q.push(tw[i]);
                    cur += tw[i];
                    time++;
                    break;
                } else {  // 다리에 트럭이 더 못올라갈떄
                    q.push(0);
                    time++;
                }
            }
        }
    }
    answer = time + bl;
    return answer;
}