#include <string>
#include <vector>

using namespace std;

bool check[32];
int arr[32];

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    for (int i = 0; i < clothes.size(); i++) {
        if (check[i]) continue;
        for (int j = i; j < clothes.size(); j++) {
            if (clothes[i][1] == clothes[j][1]) {
                arr[i]++;
                check[j] = true;
            }
        }
    }
    for (int i = 0; i < clothes.size(); i++) {
        if (arr[i]) {
            if (answer == 0) answer = 1;
            answer *= arr[i] + 1;
        }
    }

    return answer - 1;
}