#include <iostream>
#include <cstring>
using namespace std;

int T, N, G, MW;          // T：測試案例數, N：物品數量, G：家族成員數量, MW：最大承重
int P[1005], W[1005];     // 陣列 P：價格, W：重量
int dp[35];               // 動態規劃陣列 dp：儲存最大價值

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);                   
    
    cin >> T;                     
    while (T--) {                 // 迴圈處理每個測試案例
        cin >> N;                 // 輸入物品數量
        for (int i = 0; i < N; i++) {
            cin >> P[i] >> W[i];  // 輸入每個物品的價格和重量
        }
        cin >> G;                 // 輸入家族成員數量
        int ans = 0;              // 初始化最大價值總和
        while (G--) {             // 迴圈處理每個家族成員
            cin >> MW;            // 輸入每個成員的最大承重
            memset(dp, 0, sizeof(dp)); // 初始化動態規劃陣列 dp 為 0
            for (int i = 0; i < N; i++) { // 迴圈處理每個物品
                for (int j = MW; j >= W[i]; j--) { // 迴圈處理背包容量，從最大容量遞減
                    dp[j] = max(dp[j], dp[j - W[i]] + P[i]); // 計算在容量 j 下的最大價值
                }
            }
            int mx = 0;           // 初始化成員最大價值
            for (int i = 0; i <= MW; i++) { // 迴圈找出在最大承重下的最大價值
                mx = max(mx, dp[i]); 
            }
            ans += mx;            // 將成員的最大價值加到總和
        }
        cout << ans << "\n";      // 輸出每個測試案例的結果
    }
    return 0;
}
