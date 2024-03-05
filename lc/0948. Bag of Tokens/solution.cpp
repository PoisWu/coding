#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>


using namespace std;
using lli = long long int;

template <typename T>
void print_2d_vector(vector<vector<T> > vvec);
template <typename T>
void print_vector(vector<T> vec);

class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        sort(tokens.begin(), tokens.end());
        // Question: why greedy is the solution?
        int max_score = 0;
        int score = 0;
        int left = 0;
        int right = tokens.size() - 1;
        // Must stop when right < left
        while (left <= right) {
            if (power >= tokens[left]) {
                power -= tokens[left];
                score++;
                left++;
                max_score = max(score, max_score);
            } else {
                if (score == 0)
                    break;
                power += tokens[right];
                score--;
                right--;
            }
        }
        return max_score;
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {100, 200, 300, 400};
    cout << solver.bagOfTokensScore(v1, 200) << endl;
    return 0;
}

template <typename T>
void print_vector(vector<T> vec)
{
    for (auto e : vec) {
        cout << e << " ";
    }
    cout << endl;
}

template <typename T>
void print_2d_vector(vector<vector<T> > vvec)
{
    for (auto vec : vvec) {
        for (auto e : vec) {
            cout << e << " ";
        }
        cout << endl;
    }
}
