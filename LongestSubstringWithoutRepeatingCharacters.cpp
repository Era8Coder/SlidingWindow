#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s, map<char,int> &mp){
    int max_window = 0;
    int start = -1;
    int i = 0;
    for(int i=0; i<s.size(); i++){
        if(mp[s[i]] > start){
            start = mp[s[i]];
        }
        mp[s[i]] = i;
        max_window = max(max_window, i - start);
    }
    return max_window;
}

int main(){
    string s = "pwwkew";
    map<char,int> mp;
    for(char i = 'a'; i <= 'z'; i++){
        mp[i] = -1;
    }
    cout << lengthOfLongestSubstring(s,mp)  << endl;
    return 0;
}