#include<bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
    map<char, int> mp;
    set<char> st(t.begin(), t.end());
    int n = st.size();

    // Initialize the map with the frequencies of characters in t
    for (char c : t) {
        mp[c]++;
    }

    int count = 0;
    int mini = INT_MAX;
    int start = 0; // to keep track of the start of the minimum window

    int i = 0;
    int j = 0;
    while (j < s.size()) {
        // Expand the window by moving j to the right
        if (mp[s[j]] > 0) {
            count++;
        }
        mp[s[j]]--;

        // When the window contains all characters of t
        while (count >= t.size()) {
            if (j - i + 1 < mini) {
                mini = j - i + 1;
                start = i;
            }
            
            // Try to shrink the window by moving i to the right
            mp[s[i]]++;
            if (mp[s[i]] > 0) {
                count--;
            }
            i++;
        }
        j++;
    }

    if (mini == INT_MAX) {
        return "";
    } else {
        return s.substr(start, mini);
    }
}

int main(){
    string s;   cin>>s;
    string t;   cin>>t;
    cout << minWindow(s,t) << endl; 
    return 0;
}