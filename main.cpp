#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int loop;
    cin >> loop;
    while (loop--) {
        int size;
        cin >> size;
        vector<int> data(size, 0);
        for (int i = 0; i < size; ++i) {
            cin >> data[i];
        }

        vector<int> dp(size, 0);
        int big = 0;
        int sum = 0;
        int start = -1;
        for (int i = 0; i < size; i++) {
            int val = sum + data[i];

            if (val > 0) {
                if (sum == 0) {
                    start = i;
                }
                sum = val;
            } else {
                sum = 0;
            }

            if (sum > big) {
                big = sum;
            }
        }

        if (start == -1) {
            cout << data[0] << " ";
        } else {
            cout << big << " ";
        }

        sum = 0;
        start = -1;
        for (int i = 0; i < size; ++i) {
            if (data[i] > 0) {
                start = i;
                sum += data[i];
            }
        }

        if (start == -1) {
            cout << data[0] << endl;
        } else {
            cout << sum << endl;
        }
    }
    return 0;
}
