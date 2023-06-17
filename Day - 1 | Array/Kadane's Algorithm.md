## Given an integer array nums, find the subarray with the largest sum, and return its sum.

Example 1:
```
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
```
Example 2:
```
Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
```
Example 3:
```
Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
``` 

Constraints:
- `1 <= nums.length <= 10^5`
- `-10^4 <= nums[i] <= 10^4`

### Code
#### Brute Force Approach
```
int maxSubArray(vector<int>& nums) {
    int maxSum = INT_MIN, n = nums.size(); 
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;
            for (int k = i; k <= j; k++) {
                sum += nums[k];
            }
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}
```
- Time Complexity : $O(n^3)$
- Space Complexity : $O(1)$

#### Better Approach
```
int maxSubArray(vector<int> &nums) {
    int maxSum = INT_MIN, n = nums.size(); 
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += nums[j];
            maxSum = max(maxSum, sum); 
        }
    }
    return maxSum;
}
```
- Time Complexity : $O(n^2)$
- Space Complexity : $O(1)$

### Optimal Approach
```
//Kadane's Algorithm
int maxSubArray(vector<int> &nums) {
    long long maxSum = LONG_MIN;
    long long sum = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        maxSum = max(maxSum, sum);
        sum = max(sum, 0);
    }
    return maxSum;
}
```
- Time Complexity : $O(n)$
- Space Complexity : $O(n)$