## Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue. We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

Constraints:

- `n == nums.length`
- `1 <= n <= 300`
- `nums[i]` is either 0, 1, or 2.
 
Example 1:
```
Input: nums = [2,0,2,1,1,0]                  
Output: [0,0,1,1,2,2]
```

Example 2:
```
Input: nums = [2,0,1]
Output: [0,1,2]
```
### Code
#### Brute Force Approach
``` 
void sort012(vector<int> &arr) {
    //simply sorting the values of the given array
    sort(arr.begin(),arr.end());
}
```
- Time Complexity : $O(n * logn)$
- Space Complexity : $O(1)$

#### Better Approach
``` 
void sort012(vector<int> &arr) {
    //by using the charecter count method
    int count0 = 0, count1 = 0, count2 = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == 0) count0++;
        else if(arr[i] == 1) count1++;
        else count2++;
    }   
    int i = 0;
    while(count0--) arr[i++] = 0;
    while(count1--) arr[i++] = 1;
    while(count2--) arr[i++] = 2;
}
```
- Time Complexity : $O(n)$
- Space Complexity : $O(n)$

#### Optimal
```
void sort012(vector<int> &arr) {
    //by using dutch national flag algorithm
    int low = 0, mid = 0, high = arr.size() - 1;
    while(mid <= high) {
        if(arr[mid] == 0) {
            swap(arr[low++], arr[mid++]);
        }
        else if(arr[mid] == 1) {
            mid++;
        }
        else {
            swap(arr[mid], arr[high--]);
        }
    }
}    
```
- Time Complexity : $O(n)$
- Space Complexity : $O(n)$
