#include<string>
#include<iostream>
#include<limits.h>
#include<unordered_map>
#include<vector>
using namespace std;
class Solution {
public:
    bool check(int i,int j,int m,int n){
        if(i<0||i>=m||j<0||j>=n)return false;
        return true;
    }
    void dfs(int i,int j,vector<vector<char>>&grid){
        if(!check(i,j,grid.size(),grid[0].size())){
            return ;
        }
        if(grid[i][j]=='0'||grid[i][j]=='2')return;
        grid[i][j]='2';
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(i,j,grid);
                }
            }
        }
        return ans;
    }
};