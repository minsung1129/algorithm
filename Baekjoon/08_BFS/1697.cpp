#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, k;
queue<pair<int, int> > q;
vector<pair<int, int> > v;
bool visit[100001];
pair<int, int> cnt[100001];

int bfs(int start) {
    q.push(make_pair(start, 0));
    visit[start] = true;

    while (!q.empty()) {
        int node = q.front().first;
        int time = q.front().second;
        q.pop();

        if (node == k) {
            return time;
        }

        if (node + 1 < 100001 && !visit[node + 1]) {
            q.push(make_pair(node + 1, time + 1));
            visit[node + 1] = true;
            cnt[node + 1] = make_pair(node, time);
        }
        if (node - 1 >= 0 && !visit[node - 1]) {
            q.push(make_pair(node - 1, time + 1));
            visit[node - 1] = true;
            cnt[node - 1] = make_pair(node, time);
        }
        if (node * 2 < 100001 && !visit[node * 2]) {
            q.push(make_pair(node * 2, time + 1));
            visit[node * 2] = true;
            cnt[node * 2] = make_pair(node, time);
        }
    }
    return 0;
}

int main() {
    cin >> n >> k;
    pair<int, int> tmp = make_pair(k, bfs(n));
    cout << tmp.second << endl;

    while (1) {
        v.push_back(tmp);
        if (tmp.first == n) break;
        tmp = cnt[tmp.first];
    }
    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        cout << v[i].first << " ";
    }

    return 0;
}