#include <string>
#include <vector>
#include <iostream>
#include <algorithm>    // std::max
using namespace std;

class Solution {
public:
    string componentRoman(int num1, int num2){
        vector<string> vec1;
        string str1 = ""; 

        vec1.push_back("I");
        vec1.push_back("V");
        vec1.push_back("X");
        vec1.push_back("L");
        vec1.push_back("C");
        vec1.push_back("D");
        vec1.push_back("M");
          
        switch(num2){
           case 1:
              str1 += vec1[num1*2];
              return str1;
           case 2:
              for(int i = 0; i <2;i++){
                 str1 += vec1[num1*2]; 
              }
              return str1;
           case 3:
              for(int i = 0; i < 3;i++){
                 str1 += vec1[num1*2]; 
              }
              return str1;
           case 4:
              str1 += vec1[num1*2];
              str1 += vec1[num1*2+1];
              return str1;
           case 5:
              return vec1[num1*2+1]; 
           case 6:
              str1 += vec1[num1*2+1];
              str1 += vec1[num1*2];
              return str1;
           case 7:
              str1 += vec1[num1*2+1];
              for(int i = 0; i <2;i++){
                 str1 += vec1[num1*2]; 
              }
              return str1;
           case 8:
              str1 += vec1[num1*2+1];
              for(int i = 0; i <3;i++){
                 str1 += vec1[num1*2]; 
              }
              return str1;
           case 9:
              str1 += vec1[num1*2];
              str1 += vec1[num1*2+2];
              return str1;
           default: 
                break; 
           cout<< str1 <<endl;       
        }       
    }

    string intToRoman(int num){
        string str ="";
        vector<int> vec;
        int numlen = to_string(num).length(); 
        int n = 10;

        for (int i = 0; i < numlen; i++){
            vec.push_back(num % n);
            num = num / n;
        }

        for (int i = vec.size() - 1; i >= 0 ; i--){
            str += componentRoman(i,vec[i]);
        }
        return str;
    }
};

int main(){
    int num = 1994;
    Solution s = Solution();
    cout<<s.intToRoman(num)<<endl;
}    