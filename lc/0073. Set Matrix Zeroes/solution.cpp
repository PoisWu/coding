#include "../include/helper.h"

class Solution{
public: 
    void setZeroes(vector<vector<int>>& matrix){
        int m = matrix.size();
        int n = matrix[0].size();
        bool first_column = false;

        for (int i = 0; i<m; i++){
            for (int j = 0; j<n; j++){
                if (matrix[i][j] == 0 ){
                    if (j == 0){
                        first_column = true;
                    }else{
                        matrix[0][j] = 0;
                    }
                    matrix[i][0] = 0;
                }
            }
        }
        for (int j = 1; j<n; j++){
            if (matrix[0][j] == 0){
                for (int i = 0; i<m; i++){
                    matrix[i][j] = 0;
                }
            }
        }

        for (int i = 0; i<m; i++){
            if (matrix[i][0] == 0){
                for (int j = 0; j<n; j++){
                    matrix[i][j] = 0;
                }
            }
        }
        if (first_column){
            for (int i = 0; i<m; i++){
                matrix[i][0] = 0;
            }

        }

    }
};


int main()
{
    Solution solver;
    vector<vector<int>> v1 = {};
    v1.push_back({1});
    v1.push_back({0});
    v1.push_back({3});
    string s1 = "";
    string t1 = "";
    solver.setZeroes(v1);
    print_2d_vector(v1);
    return 0;
}

