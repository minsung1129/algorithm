#include <iostream>
#include <algorithm>
using namespace std;

int arr[53][53];
int a, b;
char c;
int ret1, ret2;

int brr[8][8] = {{0, 1, 0, 1, 0, 1, 0, 1}, {1, 0, 1, 0, 1, 0, 1, 0}, {0, 1, 0, 1, 0, 1, 0, 1}, {1, 0, 1, 0, 1, 0, 1, 0}, {0, 1, 0, 1, 0, 1, 0, 1}, {1, 0, 1, 0, 1, 0, 1, 0}, {0, 1, 0, 1, 0, 1, 0, 1}, {1, 0, 1, 0, 1, 0, 1, 0}};
int crr[8][8] = {{1, 0, 1, 0, 1, 0, 1, 0}, {0, 1, 0, 1, 0, 1, 0, 1}, {1, 0, 1, 0, 1, 0, 1, 0}, {0, 1, 0, 1, 0, 1, 0, 1}, {1, 0, 1, 0, 1, 0, 1, 0}, {0, 1, 0, 1, 0, 1, 0, 1}, {1, 0, 1, 0, 1, 0, 1, 0}, {0, 1, 0, 1, 0, 1, 0, 1}};

int main()
{
    cin >> a >> b;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cin >> c;
            if (c == 'W')
                arr[i][j] = 0;
            else
                arr[i][j] = 1;
        }
    }
    int ans = 99999999;
    for (int i = 0; i < a - 7; i++)
    {
        for (int j = 0; j < b - 7; j++)
        {
            ret1 = 0;
            ret2 = 0;
            for (int x = 0; x < 8; x++)
            {
                for (int y = 0; y < 8; y++)
                {
                    if (arr[i + x][j + y] != brr[x][y])
                    {
                        ret1++;
                    }
                    if (arr[i + x][j + y] != crr[x][y])
                    {
                        ret2++;
                    }
                }
            }
            ans = min(ans, min(ret1, ret2));
        }
    }
    cout << ans << endl;

    return 0;
}