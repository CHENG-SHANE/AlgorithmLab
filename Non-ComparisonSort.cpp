#include <iostream>
#include <vector>
using namespace std;

void countSort(vector<int> &arr, int NumberOfDigits){
    int output[arr.size()];
    int i; 
    int numberCount[10] = {0};//{紀錄數字0-9有多少}
    // 數字出現次數
    for (i = 0; i < arr.size(); i++)
        numberCount[(arr[i] / NumberOfDigits) % 10]++;
    // 小於等於i的數字有多少個
    for (i = 1; i < 10; i++)
        numberCount[i] += numberCount[i - 1];
    // 放到正確的位置
    for (i = arr.size() - 1; i >= 0; i--){
        output[numberCount[(arr[i] / NumberOfDigits) % 10] - 1] = arr[i];
        numberCount[(arr[i] / NumberOfDigits) % 10]--;//放完數字後減1
    } 
    // 複製回原本的陣列 
    for (i = 0; i < arr.size(); i++)
        arr[i] = output[i]; 
}

void radixSort(vector<int> &arr){
    countSort(arr, 1);  // 個位數排序
    countSort(arr, 10); // 十位數排序
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int numberOfPeople;
    while (cin >> numberOfPeople && numberOfPeople!=0){
        vector<int> ages(numberOfPeople);
        for (int i = 0; i < numberOfPeople; i++)
            cin >> ages[i];
        
        radixSort(ages);
        
        for (int i = 0; i < numberOfPeople; i++){
            if (i > 0)
                cout << " ";
            cout << ages[i];
        }
        cout << "\n";
    }
    return 0;
}
