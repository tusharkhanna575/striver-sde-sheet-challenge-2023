## Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target. You may assume that each input would have exactly one solution, and you may not use the same element twice. You can return the answer in any order.

Constraints:

- `2 <= nums.length <= 104`
- `-109 <= nums[i] <= 109`
- `-109 <= target <= 109`
- Only one valid answer exists.

Example 1:
```
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
```
Example 2:
```
Input: nums = [3,2,4], target = 6
Output: [1,2]
```
Example 3:
```
Input: nums = [3,3], target = 6
Output: [0,1]
```

### Code
#### Brute Force Approach
```
vector<int> twoSum(int n, vector<int> &arr, int target) {
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return { -1, -1};
}
```
#### Better Approach
```
vector<int> twoSum(int n, vector<int> &arr, int target) {
    //by using hashing
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        int moreNeeded = target - num;
        if (mpp.find(moreNeeded) != mpp.end()) {
            return {mpp[moreNeeded], i};
        }
        mpp[num] = i;
    }
    return { -1, -1};
}
```
#### Optimal Approach
```
vector<int> twoSum(vector<int>& nums, int target) {
    int high=nums.size()-1;
    int low=0;
    vector<int>v;
    vector<int>temp;
    for(int i=0;i<nums.size();i++){
        temp.push_back(nums[i]);
    }
    sort(nums.begin(),nums.end());
    while(low<=high){
        if(nums[low]+nums[high]==target){
            break;
        }
        else if(nums[low]+nums[high]>target){
            high--;
        }
        else if(nums[low]+nums[high]<target){
            low++;
        }
    }
    for(int i=0;i<nums.size();i++){
        if(temp[i]==nums[low]){
            v.push_back(i);
        }
        else if(temp[i]==nums[high]){
            v.push_back(i);
        }
    }
    return v;
}
```
- Time Complexity : $O(n *logn)$
- Space Complexity : $O(1)$