#include <iostream>
#include <vector>
using namespace std;
int n;
int num, ball, strike;
int a, b, c;
int aa, bb, cc;
int cnt_bal, cnt_stk;
int ans;

vector<int> v;

int main()
{
    cin >> n;
    for (int i = 100; i <= 999; i++)
    {
        a = i / 100;
        b = i / 10 % 10;
        c = i % 10;
        if (b == 0 || c == 0)
            continue;
        if (a == b || b == c || c == a)
            continue;
        v.push_back(i);
    }
    while (n--)
    {
        cin >> num >> strike >> ball;
        aa = num / 100;
        bb = num / 10 % 10;
        cc = num % 10;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == 0)
                continue;
            cnt_bal = 0;
            cnt_stk = 0;
            a = v[i] / 100;
            b = v[i] / 10 % 10;
            c = v[i] % 10;

            if (a == aa)
                cnt_stk++;
            if (b == bb)
                cnt_stk++;
            if (c == cc)
                cnt_stk++;

            if (a == bb || a == cc)
                cnt_bal++;
            if (b == aa || b == cc)
                cnt_bal++;
            if (c == bb || c == aa)
                cnt_bal++;

            if (cnt_stk != strike || cnt_bal != ball)
                v[i] = 0;
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] != 0)
            ans++;
    }
    cout << ans << endl;
    return 0;
}