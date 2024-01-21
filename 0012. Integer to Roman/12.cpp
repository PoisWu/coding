#include <iostream>

using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        int byte[4] = {0};
        for (int i = 0; i < 4; i++) {
            byte[i] = num % 10;
            num = num / 10;
        }
        string numRoman = "";
        for (int i = 3; i >= 0; i--) {
            if (i == 3)
                numRoman += string(byte[i], 'M');
            if (i == 2) {
                if (byte[i] >)
            }
        }
    }
};

int main()
{
    int a = 0;
    int bbb = 12;
}
