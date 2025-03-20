#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

const double PI = acos(-1.0);// cos(pi) = -1.0
const int maxn = 10000;

int number, f;
double A[maxn]; // 存儲每個圓的面積

// 檢查給定的體積是否足夠分成f+1塊
bool isOk(double volume) {
    int sum = 0; // 累計可以分出的塊數
    for (int i = 0; i < number; i++) {
        sum += floor(A[i] / volume); // 計算每個圓能分出多少塊
    }
    return sum >= f + 1;// true if sum >= f+1
}

double findMaxVolume() {
    double lower = 0;
    double totalVolume = 0; // 總體積
    for (int i = 0; i < number; i++) {
        totalVolume = A[i] + totalVolume;
    }
    double upper = totalVolume / (f + 1); // 體積上界
    // 開始二分搜索
    while (upper - lower > 1e-5) { // 當左右邊界差距大於1e-5時繼續查找
        double mid = (lower + upper) / 2; // 計算中間值
        if (isOk(mid)) {
            lower = mid;//代表切的太少，可以再多切一點
        }else upper = mid;
    }
    return lower; // 最大可能的體積
}

int main() {
    int testCases;
    cin >> testCases;
    while (testCases--) {
        cin >> number >> f;
        for (int i = 0; i < number; i++) {
            int r;
            cin >> r;
            A[i] = PI * r * r;
        }

        // 找最大可切的體積
        double result = findMaxVolume();
        cout << fixed << setprecision(4) << result << endl;
    }
    return 0;
}
