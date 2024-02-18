#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right)
    {
    }
};

using namespace std;

template <typename T>
void print_2d_vector(vector<vector<T>> vvec);
template <typename T>
void print_vector(vector<T> vec);
using lli = long long int;

class Solution
{
private:
    static const int mod = 1000000007;

public:
    int mostBooked(int n, vector<vector<int>> &meetings)
    {
        vector<pair<lli, lli>> meetings_interval;
        for (int i = 0; i < meetings.size(); i++) {
            meetings_interval.emplace_back((lli) meetings[i][0],
                                           (lli) meetings[i][1]);
        }
        sort(meetings_interval.begin(), meetings_interval.end());
        priority_queue<lli, vector<lli>, greater<lli>> avalible_room;
        priority_queue<pair<lli, lli>, vector<pair<lli, lli>>,
                       greater<pair<lli, lli>>>
            occupied_room;  // end, id
        for (lli i = 0; i < n; i++) {
            avalible_room.push(i);
        }
        int freq[100] = {0};
        for (int i = 0; i < meetings_interval.size(); i++) {
            lli start = meetings_interval[i].first;
            lli end = meetings_interval[i].second;
            while (!occupied_room.empty() &&
                   occupied_room.top().first <= start) {
                avalible_room.push(occupied_room.top().second);
                occupied_room.pop();
            }
            if (!avalible_room.empty()) {
                lli room_id = avalible_room.top();
                avalible_room.pop();
                occupied_room.emplace(end, room_id);
                freq[room_id]++;
            } else {
                pair<lli, lli> room_status = occupied_room.top();
                lli avalible_time = room_status.first;
                lli room_id = room_status.second;
                occupied_room.pop();
                occupied_room.emplace(avalible_time + end - start, room_id);
                freq[room_id]++;
            }
        }
        int nb_max = 0;
        int idx = 0;
        for (int i = 0; i < n; i++) {
            if (freq[i] > nb_max) {
                nb_max = freq[i];
                idx = i;
            }
        }
        return idx;
    }
};

int main()
{
    Solution solver;
    vector<vector<int>> v1 = {};
    v1.push_back({0, 10});
    v1.push_back({1, 5});
    v1.push_back({2, 7});
    v1.push_back({3, 4});

    vector<vector<int>> v2 = {};
    v2.push_back({1, 20});
    v2.push_back({2, 10});
    v2.push_back({3, 5});
    v2.push_back({4, 9});
    v2.push_back({6, 8});
    cout << solver.mostBooked(2, v1) << endl;
    cout << solver.mostBooked(3, v2) << endl;
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
void print_2d_vector(vector<vector<T>> vvec)
{
    for (auto vec : vvec) {
        for (auto e : vec) {
            cout << e << " ";
        }
        cout << endl;
    }
}
