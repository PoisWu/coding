# include "solution.cpp"
# include <iostream> 
# include <vector>
using namespace std;
template<typename T>
void print_2d_vector(vector<vector<T> > vvec){
    for (auto vec: vvec) {
        for (auto e: vec){
            cout << e << " ";
        }
        cout << endl;
    }
}

int main(){
    Solution solver;
    cout << "start" << endl;
    vector<int> v1 = {2,3,3,2,2,4,2,3,4};
    cout << solver.minOperations(v1) << endl;
    vector<int> v2 = {2,1,2,2,3,3};
    cout << solver.minOperations(v2) << endl;
           
    
}
