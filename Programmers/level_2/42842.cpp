#include <string>
#include <vector>
using namespace std;

int a, b;
vector<int> solution(int brown, int red) {
    vector<int> answer;

    for (int i = 1; i < brown; i++) {
        a = i;
        b = (red + brown) / a;

        if ((a - 2) * (b - 2) == red) {
            answer.push_back(b);
            answer.push_back(a);
            break;
        }
    }

    return answer;
}