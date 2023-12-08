/**
 * Creater: Nonamefour
 * Creat data:2021-07-07
 * Purpose:leet 379.Kth Smallest Element in a Sorted Matrix
 * 
 * End data:07-07
 * Runtime:7.86%
 * Memory Usage:54%
 *		
 */

#include<iostream> 
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

struct pos{
    int val;
    int x;
    int y;
    pos(int _val,int _x,int _y):val(_val),x(_x),y(_y){}

};



int kthSmallest(vector<vector<int> > &m,int k){
    auto cmp = [&](pos &pos1,pos &pos2){ return (pos1.val>pos2.val);};
    int n = m.size();
    priority_queue<pos, vector<pos>,decltype(cmp)> pq(cmp);
    pq.push(pos(m[0][0],0,0));
    int a = 1;
    int tab_add[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            tab_add[i][j]=0;
        }
    }
    tab_add[0][0]=1;
    while(a<k){
        pos s = pq.top();
        cout << s.val <<endl;
        int x=s.x,y=s.y;
        pq.pop();
        if(x+1<n && !tab_add[x+1][y]) pq.push(pos(m[x+1][y],x+1,y));
        if(y+1<n && !tab_add[x][y+1]) pq.push(pos(m[x][y+1],x,y+1));
        tab_add[x+1][y]=1;
        tab_add[x][y+1]=1; a++; 
    } 
    return pq.top().val; 
} 

int main(){
    vector<vector<int> > v = vector<vector<int> >();
    vector<int> int_v = {1,5,9};
    v.push_back(int_v);
    int_v = {10,11,13};
    v.push_back(int_v);
    int_v = {12,13,15};
    v.push_back(int_v);
    kthSmallest(v,9);
    return 0;
}
