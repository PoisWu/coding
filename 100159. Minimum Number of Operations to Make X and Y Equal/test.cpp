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
    int x1 = 26;
    int y1 = 1;
    int x2 = 54;
    int y2 = 2;
    int x3 = 25;
    int y3 = 30;
    
    cout << "start" << endl;
    cout << solver.minimumOperationsToMakeEqual(x1, y1) << endl;
    cout << solver.minimumOperationsToMakeEqual(x2, y2) << endl;
    cout << solver.minimumOperationsToMakeEqual(x3, y3) << endl;
    
}
