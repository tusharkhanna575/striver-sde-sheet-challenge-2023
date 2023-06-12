## You're given a stack consisting of 'N' integers. Your task is to sort this stack in descending order. We can only use the following functions on this stack S.

- `is_empty(S)` : Tests whether stack is empty or not.
- `push(S)` : Adds a new element to the stack.
- `pop(S)` : Removes top element from the stack.
- `top(S)` : Returns value of the top element. Note that this function does not remove elements from the stack.

Note: 
1) Use of any loop constructs like while,
for..etc is not allowed.
2) The stack may contain duplicate
integers.
3) The stack may contain any integer i.e
it may either be negative, positive or
zero.

Constraints: 
- `n == stack.length`
- `1 <= n <= 300`
- `nums[i]` is an integer

Example 1:
```
Input: stack = [5,-2,9,-7,3]
Output: [9,5,3,-2,-7]
```

Example 2:
```
Input: stack = [-3,14,18,-5,30]
Output: [30,18,14,-3,-5]
```
### Code
#### Brute Force Approach
```
void sortStack(vector<int> &stack) {
    //simply by using built-in sort function
    sort(stack.begin(),stack.end());
}
```
- Time Complexity : $O(n * logn)$
- Space Complexity : $O(1)$
#### Better Approach
```
//recursive solution
void insert(stack<int>&s, int temp){
    if(s.empty()|| s.top()<temp){
        s.push(temp);
        return;
    }
    int val= s.top();
    s.pop();
    insert(s,temp);
    s.push(val);
    return;
}

void sortStack(stack<int>& s){
    // base case
    if(s.size()==0 || s.size()==1){
        return;
    }
    int temp= s.top();
    s.pop();
    sortStack(s);
    insert(s,temp);
    return;
}
```
- Time Complexity : $O(n^2)$
- Space Complexity : $O(n)$

### Another Solution
```
//non-recursive solution
void stackSorting(stack<int>& stack) {
    stack<int> t;
    while (!stack.empty()) {
        int item = stack.top();
        stack.pop();
        while (!t.empty() && t.top() > item) {
            stack.push(t.top());
            t.pop();
        }
        t.push(item);
    }
    while (!t.empty()) {
        stack.push(t.top());
        t.pop();
    }
}
```
- Time Complexity : $O(n^2)$
- Space Complexity : $O(n)$