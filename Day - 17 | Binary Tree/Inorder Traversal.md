## Given the root of a binary tree, return the inorder traversal of its nodes' values.
![Sample Tree](https://assets.leetcode.com/uploads/2020/09/15/inorder_1.jpg)

Example 1:
```
Input: root = [1,null,2,3]
Output: [1,3,2]
```
Example 2:
```
Input: root = []
Output: []
```
Example 3:
```
Input: root = [1]
Output: [1]
```
Constraints:
- The number of nodes in the tree is in the range [0, 100].
- ```-100 <= Node.val <= 100```

### Code
#### Tree Structure
```
#include <bits/stdc++.h>
using namespace std;

struct node {
  int data;
  struct node *left, *right;
};

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}
```

#### Recursive Solution
```
void inorder(TreeNode* root, vector<int> &ans) {
    if(root == NULL) {
        return;
    }
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    inorder(root, ans);
    return ans;
}
```
- Time Complexity : $O(n)$
- Space Complexity : $O(n)$

#### Iterative Solution
```
vector<int> inorderTraversal(TreeNode *root) {
    vector <int> inOrder;
    stack <node*> s;
    while (true) {
        if (curr != NULL) {
            s.push(curr);
            curr = curr -> left;
        } 
        else {
            if (s.empty()) break;
            curr = s.top();
            inOrder.push_back(curr -> data);
            s.pop();
            curr = curr -> right;
        }
    }
    return inOrder;
}
```
- Time Complexity : $O(n)$
- Space Complexity : $O(n)$
