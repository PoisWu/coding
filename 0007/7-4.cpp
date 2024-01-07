/**
 * Creater: Nonamefour
 * Creat data:2021-07-04
 * Purpose:Leet Conut Vowels Permutation
 *
 * End data:07-04
 * Runtime:
 *
 * Memory Usage:
 *
 */

#include <iostream>

using namespace std;

const unsigned long long int mod = 1000000007;

class Solution
{
public:
    int countVowelPermutation(int n)
    {
        // 'a e i o u '
        unsigned long long int a = 1, e = 1, i = 1, o = 1, u = 1;
        for (int x = 1; x < n; x++) {
            unsigned long long int auxa = a;
            unsigned long long int auxe = e;
            unsigned long long int auxi = i;
            unsigned long long int auxo = o;
            unsigned long long int auxu = u;
            a = (auxe + auxi + auxu) % mod;
            e = (auxa + auxi) % mod;
            i = (auxe + auxo) % mod;
            o = auxi % mod;
            u = (auxi + auxo) % mod;
        }
        unsigned long long int rest = 0;
        rest = (rest + a) % mod;
        rest = (rest + i) % mod;
        rest = (rest + e) % mod;
        rest = (rest + o) % mod;
        rest = (rest + u) % mod;
        return rest;
    }
};

int main()
{
    Solution s = Solution();
    cout << s.countVowelPermutation(144) << endl;

    return 0;
}
