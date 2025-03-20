#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int main() {
    // �w�q?@?ӳ̤j��?]�w�]��?��^
    priority_queue<int> maxHeap;
    maxHeap.push(3);
    maxHeap.push(1);
    maxHeap.push(4);
    maxHeap.push(1);
    maxHeap.push(5);

    cout << "不要亂碼" << endl;
    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " "; // ��?L��?j��??
        maxHeap.pop(); // ������?j��??
    }
    cout << endl;

    // �w�q?@?ӳ̤p��
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(3);
    minHeap.push(1);
    minHeap.push(4);
    minHeap.push(1);
    minHeap.push(5);

    cout << "你好嗎:" << endl;
    while (!minHeap.empty()) {
        cout << minHeap.top() << " "; // ��?L��?p��??
        minHeap.pop(); // ������?p��??
    }
    cout << endl;

    return 0;
}
