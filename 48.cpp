class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int left = 0;
        int right = matrix.size()-1;
        while(left<right)
        {
            for(int i =0;i<right-left;i++)
            {
                int top = left,bottom=right;

                int topLeft = matrix[top][left+i];

                matrix[top][left+i] = matrix[bottom-i][left];
                matrix[bottom-i][left] = matrix[bottom][right-i];
                matrix[bottom][right-i] = matrix[top+i][right];
                matrix[top+i][right] = topLeft;
            }
            left++;
            right--;
        }
    }
};


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i =0;i<matrix.size();i++)
        {
            for(int j =i+1;j<matrix.size();j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i =0;i<matrix.size();i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};