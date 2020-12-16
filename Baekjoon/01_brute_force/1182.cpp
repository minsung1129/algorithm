#include <iostream>

using namespace std;

int n, sum, ans;
int arr[21];

void cal(int index, int cal_sum) {
    cal_sum += arr[index];

    if (index >= n)
        return;
    if (sum == cal_sum)
        ans++;

    cal(index + 1, cal_sum - arr[index]);
    cal(index + 1, cal_sum);
}
/*
for(int j=0;orders[i].length();j++){
                while(1){
                    arr[k][index++] = 
                }
            }
*/
int main() {
    cin >> n >> sum;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cal(0, 0);
    cout << ans << endl;

    return 0;
}