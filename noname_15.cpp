#include <iostream> 
#include <vector> 
#include <utility>  
#include <map>

using namespace std;


bool sort_vector(vector<int> v1,vector<int> v2){
    //cout << v1.size() << " " <<v2.size() <<endl;
    for(int i=0;i<3;i++){
            if(v2[i]!=v1[i]) return v1[i]<v2[i];
    }
    return false;
}

class Solution{
    public: 
        vector<vector<int> > threeSum(vector<int>& nums){
            vector<vector<int> > output = vector<vector<int> >() ;
            sort(nums.begin(),nums.end());
            //cout << "creat output"<<endl;
            if(nums.size()<3) return output;
                map<int,vector< pair<int,int> > > table = map<int,vector<pair<int,int> > >();
            //cout<< "creat table" <<endl;
            for(int i=0; i<nums.size();i++){
                for(int j=i+1;j<nums.size();j++){
                    int two_Sum = nums[i]+nums[j];
                    if(!table.count(two_Sum)){
                        table[two_Sum]=vector<pair<int,int> >();
                    } 
                    table[two_Sum].push_back(pair<int,int> (i,j));
                }
            }     
            //cout <<"table done"<<endl;

            int buff[3];
            for(int i = 0 ; i < nums.size(); i++){
                int target_i = nums[i]*(-1);
                if(table.count(target_i)){
                    for(int j = 0 ; j<table[target_i].size();j++){
                        int fst = table[target_i][j].first;
                        int scd = table[target_i][j].second;
                        if(i!=fst && i!=scd){
                            int index_3[3]={i,fst,scd};
                            sort(index_3,index_3+3);
                            buff[0]=nums[index_3[0]];
                            buff[1]=nums[index_3[1]];
                            buff[2]=nums[index_3[2]];
                            vector<int> buf_vect(buff,buff+3);
                            output.push_back(buf_vect);
                        }
                    }
                }
            }

            //cout<<"output done" <<endl; 

            if(output.size()==0||output.size()==1) return output; 
            //cout << output.size() <<endl;
            sort(output.begin(),output.begin()+output.size(),sort_vector);

            //cout << "output sorted" <<endl;

            vector<vector<int> > refine_output = vector<vector<int> >();
            refine_output.push_back(output[0]);
            int pointer=0;
            for(int i=1;i<output.size();i++){
                if(output[i][0]>refine_output[pointer][0]||output[i][1]>refine_output[pointer][1]|| output[i][2]>refine_output[pointer][2]){
                    refine_output.push_back(output[i]);
                    pointer++;
                }
            };
            //cout << "refine_output" << endl;
            return refine_output;
        }
};

int main(){
    Solution s = Solution();
    vector<int> vec1;
    vector<vector<int> > vec2 = vector<vector<int> >();
    vec1.push_back(3);
    vec1.push_back(0);
    vec1.push_back(-2);
    vec1.push_back(-1);
    vec1.push_back(1);
    vec1.push_back(2);

    vec2 = s.threeSum(vec1);
    cout << '[';
    for (vector<vector<int> >::size_type i = 0; i < vec2.size(); i++ ){
        cout << '[';
         for (vector<int>::size_type j = 0; j < vec2[i].size(); j++ ){
              cout << vec2[i][j];
              if (j < vec2[i].size() - 1)
              {
                 cout << ','; 
              }
         }
         cout << ']';
    }
    cout << ']';
    return 0;
}
