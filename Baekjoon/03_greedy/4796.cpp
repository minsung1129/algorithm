#include <iostream>
#include <algorithm>
using namespace std;

int a, b, c;

int main()
{
    int index = 1;
    while (1)
    {
        int ans = 0;
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0)
            break;

        ans += c / b * a;
        int tmp = c % b;
        ans += min(tmp, a);

        cout << "Case " << index << ": " << ans << endl;

        index++;
    }
    return 0;
}