#include<iostream>
#include<unordered_map>
#include<limits.h>
#include<string>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>need,window;
        for(char c:t){
            need[c]++;
        }
        int valid=0;
        int l=0;
        int r=0;

        int start=0;
        int len=INT_MAX;
        while(r<s.size()){
            char a=s[r];
            r++;
            if(need.count(a)){
                window[a]++;
                if(window[a]==need[a]){
                    valid++;
                }
            }
            while(valid==need.size()){
                if(r-l<len){
                    start=l;
                    len=r-l+1;
                }
                char b=s[l];
                l++;
                if(need.count(b)){
                    window[b]--;
                    if(window[b]<need[b]){
                        valid--;
                    }
                }
            }   
        }
        return len==INT_MAX?"":s.substr(start,len-1);
    }
};
