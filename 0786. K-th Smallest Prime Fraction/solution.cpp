# include <vector>
# include <algorithm>    
# include <iostream>

using namespace std;

class Solution{
public: 
    static bool cmp(pair<int, int> a, pair<int, int> b){
        return (a.first*b.second < a.second*b.first);
    }
    // Construct all the fraction
    // Sort with cmp function
    // pick kth item (start with 1)
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k){
        vector<pair<int, int> > fractions;
        for (auto n_it = arr.begin(); n_it!=arr.end(); ++n_it){
            for (auto d_it = n_it+1; d_it!=arr.end(); ++d_it){
                fractions.push_back(make_pair(*n_it, *d_it));
            }
        }
        sort(fractions.begin(), fractions.end(), cmp); 

        return vector<int>{fractions[k-1].first, fractions[k-1].second};
    }
};

