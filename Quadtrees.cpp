#include <iostream>
#include <algorithm>
using namespace std;
//p:灰 e:白 f:黑
long long count (const string &qt, int &idx, int depth) {
    long long sum = 0;
    if (qt[idx] == 'p') {
        ++idx;
        for (int i = 0; i < 4; ++i) {
            sum += count(qt, idx, depth + 1);
        }return sum;
    }
    return qt[idx++] == 'f' ? (1 << (30 - depth*2)) : 0;
}
long long merge(const string &qt1, const string &qt2, int &idx1, int &idx2, int depth) {
    if (qt1[idx1] == 'p' && qt2[idx2] == 'p') {
        ++idx1; ++idx2;
        long long sum = 0;
        for (int i = 0; i < 4; ++i) {
            sum += merge(qt1, qt2, idx1, idx2, depth + 1);
        }
        return sum;
    }else return max(count(qt1, idx1, depth), count(qt2, idx2, depth));//其他情況權重大的節點會把另一個覆蓋掉
}
int main(){
    int cases;
    cin >> cases;
    while (cases--) {
        string qt1, qt2;
        cin >> qt1 >> qt2;
        int idx1 = 0, idx2 = 0;
        cout << "There are " << merge(qt1, qt2, idx1, idx2, 0) << " black pixels." << endl;
    }
    return 0;
}
