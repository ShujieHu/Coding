#include <vector>
#include <iostream>
//#include <algorithm>
#include <stack>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    cin >> N;
    vector<int> arr(N + 1, 0);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    stack<int> stk;
    int maxA = 0;
    for (int i = 0; i < N + 1; i++) {
        while (!stk.empty() && arr[stk.top()] > arr[i]) {
            //need to maintain a non-decreasing sequence
            int idx = stk.top();
            stk.pop();
            int area = stk.empty() ?  arr[idx] * (i) : arr[idx] * (i - stk.top() - 1);
            maxA = max(maxA, area);
        }
        stk.push(i);
    }
    cout << maxA << endl;
    return 0;
}

