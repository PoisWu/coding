# include <vector>
# include <algorithm>    
# include <iostream>

using namespace std;

class Solution{
public: 
    vector<vector<int>> findMatrix(vector<int>& arr){
        // sort arr
        sort(arr.begin(), arr.end());
        vector<vector<int> > res;
        int maxlen=0;
        int counter=1;
        for (int i = 1; i < arr.size(); i++){
            if (arr[i-1] == arr[i]) counter++;
            else{
                maxlen = max(counter, maxlen);
                counter = 1;
            }
        }
        maxlen = max(counter, maxlen);
        cout << maxlen << endl;

        for (int i = 0; i < maxlen; i++){
            res.push_back(vector<int>());
        }
        res[0].push_back(arr[0]);
        int idx = 1;
        for (int i = 1; i < arr.size(); i++){
            if (arr[i-1] == arr[i]){
                res[idx].push_back(arr[i]);
                idx++;
            }else{
                res[0].push_back(arr[i]);
                idx = 1;
            }
        }
        return res;
    }
};

