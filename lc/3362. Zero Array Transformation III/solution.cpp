#include "../include/helper.h"

class Solution{
public: 
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries){
        sort(queries.begin(), queries.end());
        priority_queue<int> good_to_use; // big to small 
        priority_queue<int, vector<int>, greater<int>> currently_using; // small to big
        
        int n = nums.size();
        int q_idx = 0;
        int q_len = queries.size();
        int cnt = 0;
        for (int idx = 0; idx < n; idx++){
            int required_idx = nums[idx];

            while (q_idx < q_len && queries[q_idx][0]<=idx){
                good_to_use.push(queries[q_idx][1]);
                q_idx++;
            }

            while(!currently_using.empty() && currently_using.top()<idx){
                currently_using.pop();
            }

            while(currently_using.size()<required_idx){
                if (good_to_use.empty() || good_to_use.top()<idx){
                    return -1;
                }
                int r = good_to_use.top();
                good_to_use.pop();
                currently_using.push(r);
                cnt++;
            }
        }
        return q_len - cnt;
    }
};


int main()
{
    Solution solver;
    vector<int> v1 = {2,0,2};
    vector<vector<int>> q1 = {};
    q1.push_back({1,1});
    q1.push_back({0,2});
    q1.push_back({0,2});
    string s1 = "";
    string t1 = "";
    cout<< solver.maxRemoval(v1, q1)<<endl;
    /*cout << solver.<< endl;*/
    return 0;
}

