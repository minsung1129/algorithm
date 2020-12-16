#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

double arr[200002];
vector<pair<int, double> > v;  // n번, 몇개

double cal(double n1, double n2) {
    return n1 / n2;
}

bool cmp(const pair<int, double> &a, const pair<int, double> &b) {
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    double people = stages.size();

    for (int i = 0; i < stages.size(); i++) {
        arr[stages[i]]++;
    }

    for (int i = 1; i <= N; i++) {
        v.push_back(make_pair(i, cal(arr[i], people)));
        people -= arr[i];
    }
    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < N; i++) {
        // answer.push_back(v[i].first);
        cout << v[i].first << " " << v[i].second << endl;
    }

    return answer;
}
int main() {
    vector<int> test;
    test.push_back(2);
    test.push_back(1);
    test.push_back(2);
    test.push_back(6);
    test.push_back(2);
    test.push_back(4);
    test.push_back(3);
    test.push_back(3);
    solution(5, test);

    return 0;
}