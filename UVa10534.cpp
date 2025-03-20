#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
int Length;
int sequence[10005];// 儲存輸入的序列
int lIS[10005]; // 儲存每個lIS長度
int lDS[10005]; // 儲存每個lDS長度
int dpArray[10005]; // 輔助陣列

// 反轉陣列
void reverseArr(int arr[], int size) {
    int left = 0;
    int right = size - 1;
    while (left < right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;                   
        right--;                  
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> Length) {
        // 初始化
        memset(sequence, 0, sizeof(sequence));
        memset(lIS, 0, sizeof(lIS)); 
        memset(lDS, 0, sizeof(lDS)); 
        int ans = 0; // 結果

        for (int i = 0; i < Length; i++)
            cin >> sequence[i];
        for (int i = 1; i <= Length; i++)
            dpArray[i] = INF; // 初始化dpArray
        // 計算遞增子序列
        for (int i = 0; i < Length; i++) {
            int pos = lower_bound(dpArray + 1, dpArray + Length + 1, sequence[i]) - dpArray;// 找到第一個大於或等於sequence[i]的位置，- dpArray是為了取得索引
            lIS[i] = pos;
            dpArray[pos] = sequence[i];
        }
        
        reverseArr(sequence, Length); // 反轉序列
        for (int i = 1; i <= Length; i++)
            dpArray[i] = INF; // lower_bound重新初始化dpArray
        for (int i = 0; i < Length; i++) {
            int pos = lower_bound(dpArray + 1, dpArray + Length + 1, sequence[i]) - dpArray;
            lDS[i] = pos;
            dpArray[pos] = sequence[i];
        }
        reverseArr(lDS, Length); // 反轉最長遞減子序列陣列
        
        for (int i = 0; i < Length; i++)
            ans = max(ans, (min(lIS[i], lDS[i]) * 2 - 1)); // 計算最長的Wavio序列長度
            //min(lIS[i], lDS[i])確保了我們在選擇從點 i 向左和向右擴展時，不會超過任何一邊實際能達到的長度
        
        cout << ans << '\n';
    }
    return 0;
}
