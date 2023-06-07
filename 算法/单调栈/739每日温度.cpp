#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
     stack<int>stk;
     int m=temperatures.size();
     vector<int>ans(m);
     for(int i=m-1;i>=0;i--){
         while(!stk.empty()&&temperatures[stk.top()]<=temperatures[i])stk.pop();
        ans[i]=stk.empty()?0:stk.top()-i;
        stk.push(i);
     }   
     return ans;
    }
};