#include<bits/stdc++.h>
using namespace std;
    
int min_subarray_len(vector<int> &nums, int target){
    int min_window = INT_MAX;
    int curr_sum = 0;

    // using Sliding window
    int low = 0;
    int high= 0;

    while(high < nums.size()){
        // Find the current size and increasing the Window Size
        curr_sum = curr_sum + nums[high];
        high++;

        // Reducing the Window Size
        while(curr_sum >= target){
            min_window = min(min_window, high - low);
            curr_sum = curr_sum - nums[low];
            low++;              // Increasing the Lower Pointer :)
        }
    }
    if(min_window == INT_MAX){
        return 0;
    }
    return min_window;
}

int main(){
    int target;  cin>>target;
    vector<int> v = {1, 1, 1, 1, 1, 1, 1, 1};
    cout << min_subarray_len(v, target) << endl;
    return 0;
}