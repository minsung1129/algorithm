#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> &A) {
    int answer = 0;
    vector<int> B;
    for (int i = 1; i <= A.size(); i++) {
        B.push_back(i);
    }
    sort(A.begin(), A.end());

    for (int i = 0; i < A.size(); i++) {
        answer += abs(A[i] - B[i]);
        if (answer > 1000000000) return -1;
    }

    return answer;
}
