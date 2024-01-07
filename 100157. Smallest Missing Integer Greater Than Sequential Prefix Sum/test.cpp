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
    vector<int> v1 = {1,2,3,2,5};
    vector<int> v2 = {3,4,5,1,12,14,13};
    vector<int> v3 = {4,5,6,7,8,8,9,4,3,2,7};
    cout << solver.missingInteger(v1) << endl;;
    cout << solver.missingInteger(v2) << endl;;
    cout << solver.missingInteger(v3) << endl;;

    cout << "start" << endl;
    
}
