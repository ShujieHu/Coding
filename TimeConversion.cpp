#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string time;
    cin >> time;
    int n = time.size();
    if (time[n-2] == 'A' || time[n-2] == 'a') {
        //morning
        int hr = stoi(time.substr(0, 2));
        if (hr == 12) {
            time[0] = '0';
            time[1] = '0';
        }
    } else {
        // in the afternoon
        int hr = stoi(time.substr(0, 2));
        if (hr != 12) {
            hr += 12;
            time[0] = hr / 10 + '0';
            time[1] = hr % 10 + '0';
        }
    }
    time.resize(n - 2);
    cout << time << endl;
    return 0;
}

