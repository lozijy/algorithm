#include<string>
#include<iostream>
#include<limits.h>
#include<unordered_map>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        unordered_map<char,int>need,window;
        int valid=0;
        for(char c:p)need[c]++;
        int l=0;
        int r=0;
        while(r<s.size()){
            char a=s[r];
            r++;
            if(need.count(a)){
                window[a]++;
                if(window[a]==need[a])valid++;
            }
            while(r-l>=p.size()){
                if(valid==need.size())ans.push_back(l);
                char b=s[l];
                l++;
                if(need.count(b)){
                    if(window[b]==need[b])
                        valid--;
                    window[b]--;

                }
            }
        }
        return ans;
    }
};