#include <iostream>

using namespace std;
const int MAX = 1000000000;

int main(void) {
    long long X, Y;
    cin >> X >> Y;

    int Z = (Y * 100) / X;
    //확률이 바뀔 수 없는 경우
    if (Z >= 99) {
        cout << -1 << "\n";
        return 0;
    }

    int low = 0, high = MAX;
    int result = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int tempZ = (100 * (Y + mid)) / (X + mid);
        if (Z >= tempZ) {
            result = mid + 1;
            low = mid + 1;
        } else
            high = mid - 1;
    }
    cout << result << "\n";
    return 0;
}

/*
53찾기 (1~100)

low     high    mid
0       100     50    
51      100     75
51      74      62
51      61      56
51      55      53
*/