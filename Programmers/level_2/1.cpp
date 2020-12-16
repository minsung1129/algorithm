#include <algorithm>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q1;
    queue<int> q2;
    for (int i = 0; i < priorities.size(); i++) {
        q1.push(make_pair(priorities[i], i));
        q2.push(priorities[i]);
    }
    //sort(q2.front(), q2.back());
    //reverse(q2.front(), q2.back());
    while (!q1.empty()) {
        if (q1.front().first == q2.front()) {
            if (location == q1.front().second) {
                answer++;
                break;
            } else {
                answer++;
                q1.pop();
                q2.pop();
            }
        } else {
            q1.push(q1.front());
            q1.pop();
        }
    }

    return answer;
}