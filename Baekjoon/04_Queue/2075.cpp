#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int arr[1502][1502];
stack<int> q[1502];
vector<int> v;
int n, a;
pair<int, int> large;  // 수 , 인덱스

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a;
            q[i].push(a);
        }
    }

    for (int i = 0; i < n; i++) {
        if (v.size() >= n) break;
        large = make_pair(0, 0);
        for (int j = 0; j < n; j++) {
            if (large.first < q[j].top()) {
                large.first = q[j].top();
                large.second = j;
            }
        }
        v.push_back(large.first);
        q[large.second].pop();
    }

    cout << v[n - 1] << endl;

    return 0;
}