#include <algorithm>
#include <iostream>
#include <map>
#include <vector>


using namespace std;

class Solution
{
public:
    int minimumOperationsToMakeEqual(int x, int y)
    {
        if (y >= x) {
            return y - x;
        }
        int res5 = x % 5;
        int res11 = x % 11;
        int c5;
        int c11;
        if (res5 < 3) {
            c5 = res5 + 1 + minimumOperationsToMakeEqual(x / 5, y);
        } else {
            c5 = 5 - res5 + 1 + minimumOperationsToMakeEqual(x / 5 + 1, y);
        }
        if (res11 < 6) {
            c11 = res11 + minimumOperationsToMakeEqual(x / 11, y) + 1;
        } else {
            c11 = 11 - res11 + minimumOperationsToMakeEqual(x / 11 + 1, y) + 1;
        }
        // cout << "x and y " << x << "  " << y << endl;
        // cout << "c5 " << c5 << endl;
        // cout << "c11 " << c11 << endl;
        // cout << "x-y " << x-y << endl;


        return min(min(c5, c11), x - y);
    }
};
