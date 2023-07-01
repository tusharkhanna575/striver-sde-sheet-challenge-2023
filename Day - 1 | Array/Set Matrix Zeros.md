## Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's. You must do it in place.

Example 1:

![](https://assets.leetcode.com/uploads/2020/08/17/mat1.jpg)
```
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
```
Example 2:

![](https://assets.leetcode.com/uploads/2020/08/17/mat2.jpg)
```
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
```

Constraints:
- `m == matrix.length`
- `n == matrix[0].length`
- `1 <= m, n <= 200`
- `-2^31 <= matrix[i][j] <= 2^31 - 1`

### Code
#### Brute Force Approach
```
void row(vector<vector<int>> &matrix, int n, int m, int i) {
    for(int j=0;j<m;j++) {
        if(matrix[i][j]!=0) {
            matrix[i][j]=-1;
        }
    }
}
void col(vector<vector<int>> &matrix, int n, int m, int j) {
    for(int i=0;i<n;i++) {
        if(matrix[i][j]!=0) {
            matrix[i][j]=-1;
        }
    }
}
void setZeroes(vector<vector<int>>& matrix) {
    int n=matrix.size(), m=matrix[0].size();
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(matrix[i][j]==0) {
                row(matrix,n,m,i);
                col(matrix,n,m,j);
            }
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(matrix[i][j]==-1) {
                matrix[i][j]=0;
            }
        }
    }
}
```
- Time Complexity : $O(n^3)$
- Space Complexity : $O(1)$

#### Better Approach
```
void setZeroes(vector<vector<int>>& matrix) {
    int n=matrix.size(), m=matrix[0].size();
    vector<int> row(n,0), col(m,0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (row[i] || col[j]) {
                matrix[i][j] = 0;
            }
        }
    }
}
```
- Time Complexity : $O(n^2)$
- Space Complexity : $O(n)$

#### Optimal Approach
```
void setZeros(vector<vector<int>> &matrix) {
    int n=matrix.size(), m=matrix[0].size();
    int col0 = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                if (j != 0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] != 0) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
    if (matrix[0][0] == 0) {
        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }
    if (col0 == 0) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }
    return matrix;
}
```
- Time Complexity : $O(n^2)$
- Space Complexity : $O(1)$
