#include <iostream>

using namespace std;

int g;
bool flag;
long long int ll = 1, rr = 1;

int main() {
    cin >> g;
    while (1) {
        if (rr - ll == 1 && rr * rr - ll * ll > g) break;
        if (rr * rr - ll * ll < g) {
            rr++;
        } else {
            if (rr * rr - ll * ll == g) {
                cout << rr << endl;
                flag = true;
            }
            ll++;
        }
    }
    if (!flag) cout << -1 << endl;
    return 0;
}
