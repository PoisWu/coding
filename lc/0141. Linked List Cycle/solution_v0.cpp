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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){};
};

class Solution
{
private:
    static const int mod = 1000000007;

public:
    bool hasCycle(ListNode *head)
    {
        if (!head) {
            return false;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        bool hascycle = true;
        do {
            if (fast->next && fast->next->next) {
                fast = fast->next->next;
                slow = slow->next;
            } else {
                hascycle = false;
                break;
            }
        } while (slow != fast);
        return hascycle;
    }
};

int main()
{
    Solution solver;
    vector<int> v1 = {};
    string s1 = "";
    string t1 = "";
    // cout << solver.<< endl;
    // print_vector(solver.);
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
