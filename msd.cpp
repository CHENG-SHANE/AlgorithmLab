#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 獲取數字的位數
int getDigit(int number, int digitPosition) {
    return (number / static_cast<int>(pow(10, digitPosition))) % 10;
}

// 計算數字的最大位數
int getMaxDigits(const vector<int>& array) {
    int maxVal = 0;
    for (int num : array) {
        if (num > maxVal) maxVal = num;
    }
    return static_cast<int>(log10(maxVal) + 1);
}

/*
起點：最左側的數字。
過程：根據最高位的數字（0-9）將數字分配到對應的桶中。
遞迴：每當數字被放入一個桶後，
MSD會對每個桶內的數字進行遞迴排序*/
void sort_by_digit(vector<int>& A, int digitPosition) {
    if (A.size() <= 1) return; // 基本情況
    int r = 10; // 基底為10
    vector<int> buckets[r], B(A.size());
    // 將數字放入桶中
    for (int num : A) {
        int digit = getDigit(num, digitPosition);
        buckets[digit].push_back(num);
    }
    int index = 0;
    // 將每個桶中的數字放回原陣列
    for (int i = 0; i < r; ++i) {
        sort_by_digit(buckets[i], digitPosition - 1); // 遞迴排序每個桶
        for (int num : buckets[i]) {
            B[index++] = num;
        }
    }
    A = B; // 複製回原陣列
}

void msd_radix_sort(vector<int>& A) {
    int maxDigits = getMaxDigits(A);
    for (int digitPosition = maxDigits - 1; digitPosition >= 0; --digitPosition) {
        sort_by_digit(A, digitPosition);
    }
}

int main() {
    vector<int> array = {170, 45, 75, 2, 802, 24, 66};
    msd_radix_sort(array);
    for (int num : array) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
