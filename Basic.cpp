/*
How to Identify Sliding Window Problems:
These problems generally require Finding Maximum/Minimum Subarray, Substrings which satisfy some specific condition.
The size of the subarray or substring ‘K’ will be given in some of the problems.
These problems can easily be solved in O(N2) time complexity using nested loops, using sliding window we can solve these in O(n) Time Complexity.
Required Time Complexity: O(N) or O(Nlog(N))
Constraints: N <= 106 , If N is the size of the Array/String.
*/

// How to get the Maximum Sum Window <<--
#include<bits/stdc++.h>
using namespace std;

int max_sum(vector<int> &arr, int k){
    if(arr.size() < k){
        cout << "Not Possible" << endl;
        return -1;
    }

    int n = arr.size();
    int max_sum = 0;
    for(int i=0; i<k; i++){
        max_sum = max_sum + arr[i];
    }

    int window_sum = max_sum;
    for(int i = k; i < n; i++){
        window_sum += arr[i] - arr[i-k];
        max_sum = max(max_sum, window_sum);
    }

    return max_sum;
}

int main(){
    int n;  cin>>n;
    int k;  cin>>k;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << max_sum(arr, 4) << endl;
    return 0;
}