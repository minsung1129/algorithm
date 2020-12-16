#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, num;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num;
        if (num != 0) {
            pq.push(make_pair(abs(num), num));
        } else {
            if (pq.empty()) {
                cout << 0 << endl;
            } else {
                cout << pq.top().second << endl;
                pq.pop();
            }
        }
    }

    return 0;
}