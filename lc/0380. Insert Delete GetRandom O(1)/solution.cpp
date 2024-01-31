#include <algorithm>
#include <array>
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
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

class Solution
{
public:
};

class RandomizedSet
{
private:
    unordered_set<int> set;

public:
    RandomizedSet() {}

    bool insert(int val)
    {
        if (this->set.find(val) != set.end()) {
            return false;
        }
        this->set.insert(val);
        return true;
    }

    bool remove(int val)
    {
        if (this->set.find(val) != set.end()) {
            this->set.erase(val);
            return true;
        }
        return false;
    }

    int getRandom()
    {
        int random_num = rand() % this->set.size();
        return *next(this->set.begin(), random_num);
    }
}
