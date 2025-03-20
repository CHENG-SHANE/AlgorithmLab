#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

const double PI = acos(-1.0); // 定義PI值，用於計算圓面積
const int maxn = 10000; // 最大圓的數量

int number, f;
double A[maxn]; // 存儲每個圓的面積

// 檢查給定的面積是否足夠分成f+1塊
bool isOk(double area) {
    int sum = 0; // 用於累計可以分出的蛋糕塊數
    for (int i = 0; i < number; i++) sum += floor(A[i] / area); // 計算每個圓能分出多少塊
    return sum >= f + 1; // 如果累計塊數大於等於f+1，返回true
}

// 二分搜索函數，尋找最大的派塊大小
double binarySearch(double maxa) {
    double lower = 0, upper = maxa;
    while (upper - lower > 1e-3) { // 當左右邊界差距大於1e-3時繼續查找
        double mid = (lower + upper) / 2; // 計算中間值
        if (isOk(mid)) lower = mid; else upper = mid; // 調整左或右邊界
    }
    return lower; // 返回最大可能的派塊大小
}

int main() {
    int testCases; // 測試案例數
    cin >> testCases;
    while (testCases--) {
        cin >> number >> f; // 讀取圓的數量和朋友數量
        double maxa = 0; // 存儲最大圓面積
        for (int i = 0; i < number; i++) {
            int r; // 圓的半徑
            cin >> r;
            A[i] = PI * r * r; // 計算並存儲圓面積
            maxa = max(maxa, A[i]); // 更新最大圓面積
        }
        double result = binarySearch(maxa); // 進行二分搜索找最大的派塊大小
        cout << fixed << setprecision(5) << result << endl; // 輸出結果
    }
    return 0;
}

