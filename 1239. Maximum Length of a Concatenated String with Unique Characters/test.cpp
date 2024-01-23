#include <iostream>
#include <vector>
#include "solution.cpp"
using namespace std;
template <typename T>
void print_2d_vector(vector<vector<T> > vvec)
{
    for (auto vec : vvec) {
        for (auto e : vec) {
            cout << e << " ";
        }
        cout << endl;
    }
}

int main()
{
    Solution solver;
    cout << "start" << endl;
    vector<string> v1 = {"un", "iq", "ue"};
    vector<string> v2 = {"char", "r", "act", "ers"};
    vector<string> v3 = {"abcdefghijklmnopqrstuvwxy",
                         "ab",
                         "cd",
                         "ef",
                         "gh",
                         "ij",
                         "kl",
                         "mn",
                         "op",
                         "qr",
                         "st",
                         "uv",
                         "wx",
                         "yz"};
    vector<string> v4 = {"aa", "bb"};
    vector<string> v5 = {"jnfbyktlrqumowxd", "mvhgcpxnjzrdei"};
    cout << solver.maxLength(v1) << endl;
    cout << solver.maxLength(v2) << endl;
    cout << solver.maxLength(v3) << endl;
    cout << solver.maxLength(v4) << endl;
    cout << solver.maxLength(v5) << endl;
}
