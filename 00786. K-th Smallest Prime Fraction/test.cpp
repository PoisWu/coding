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

template<typename T>
void print_vector(vector<T> vec){
    for (auto e: vec){
        cout << e << " ";
    }
    cout << endl;
}

int main(){
    Solution solver;
    cout << "start" << endl;
    vector<int> v1 = {1,2,3,5};
    vector<int> v2 = {1,7};
    print_vector(solver.kthSmallestPrimeFraction(v1, 3));
    print_vector(solver.kthSmallestPrimeFraction(v1, 4));
    print_vector(solver.kthSmallestPrimeFraction(v2, 1));

}
