#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int idx = 0;
    int tmp = 0;
    while (1) {
        if (idx == progresses.size()) break;
        int cnt = 0;
        int day = (100 - progresses[idx]) / speeds[idx];
        if ((100 - progresses[idx]) % speeds[idx]) day += 1;

        for (int i = idx; i < progresses.size(); i++) {
            progresses[i] += speeds[i] * day;
        }

        for (int i = idx; i < progresses.size(); i++) {
            if (progresses[i] >= 100 && i == progresses.size() - 1) {
                cnt++;
                answer.push_back(cnt);
                return answer;
            } else if (progresses[i] >= 100)
                cnt++;
            else {
                answer.push_back(cnt);
                idx = i;
                break;
            }
        }
    }

    return answer;
}