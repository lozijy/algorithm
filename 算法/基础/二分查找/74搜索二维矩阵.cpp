#include<vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            int l=0;
            int r=n-1;
            while(l<r){
                int mid=(l+r)>>1;
                if(matrix[i][mid]>=target)r=mid;
                else l=mid+1;
            }
            if(l>=0&&l<=n-1&&matrix[i][l]==target)return true;
        }
        return false;
    }
};