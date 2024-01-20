#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        int res = 0;
        int pre = 0;
        for (auto s : bank) {
            int nb_one = count(s.begin(), s.end(), '1');
            cout << nb_one << endl;

            if (nb_one) {
                res += nb_one * pre;
                pre = nb_one;
            }
        }
        return res;
    }
};
