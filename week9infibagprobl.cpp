#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> Time(10005);
vector<int> num(10005);

void Knapsack(int m, int t)
{
    for (int i = 0; i + m <= t; ++i)
        if (Time[i + m] < Time[i] + m) {
            Time[i + m] = Time[i] + m;
            num[i + m] = num[i] + 1;
        }
}

int main()
{
    int m, n, t;
    while (cin >> m >> n >> t) {
        fill(Time.begin(), Time.begin() + t + 1, 0);
        fill(num.begin(), num.begin() + t + 1, 0);
        if (m > n) swap(m, n);

        Knapsack(m, t);
        Knapsack(n, t);

        if (Time[t] == t) cout << num[t] << endl;
        else cout << num[Time[t]] << " " << t - Time[t] << endl;
    }
    return 0;
}
