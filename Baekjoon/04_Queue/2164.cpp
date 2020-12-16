#include <iostream>
#include <queue>

using namespace std;

queue<int> q;
int n;
int idx = 1;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    while (q.size() > 1) {
        if (idx % 2 == 1)
            q.pop();
        else {
            int tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        idx++;
    }
    cout << q.front() << endl;
    return 0;
}