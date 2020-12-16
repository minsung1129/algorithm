#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, indexS, indexE;
int a, b;
pair<int, int> c[200005];
priority_queue<int, vector<int>, greater<int> > pq;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> c[i].first >> c[i].second;
    }
    sort(c, c + n);
    pq.push(c[0].second);
    for (int i = 1; i < n; i++) {
        if (pq.top() > c[i].first) {
            pq.push(c[i].second);
        } else {
            pq.pop();
            pq.push(c[i].second);
        }
    }
    cout << pq.size() << endl;
    return 0;
}