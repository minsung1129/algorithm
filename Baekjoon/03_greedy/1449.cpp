#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, a;
int ans;
vector<int> v;

int main()
{
    cin >> n >> a;
    for (int i = 0; i < n; i++)
    {
        int b;
        cin >> b;
        v.push_back(b);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    {
        if (v[i] == 0)
            continue;
        ans++;
        for (int j = i + 1; j < n; j++)
        {
            if (v[i] + (a - 1) >= v[j])
            {
                v[j] = 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}