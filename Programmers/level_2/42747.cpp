#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int cnt;
int wow;

int solution(vector<int> c) {
    int answer = 0;
    sort(c.begin(), c.end());
    int sz = c.size();
    for (int i = 0; i < c.size(); i++) {
        if (sz - i <= c[i]) return sz - i;
    }

    return answer;
}