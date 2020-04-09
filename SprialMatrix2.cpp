#include<iostream>
#include<vector>
using namespace  std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty())return res;
        int m= matrix.size(), n = matrix[0].size();
        int up = 0, left = 0, down = m - 1, right = n - 1;
        while (true) {
            for (int i = left; i <= right; ++i) res.push_back(matrix[up][i]);
            ++up;
            if (up > down) break;         
            for (int i = up; i <= down; ++i) res.push_back(matrix[i][right]);
            --right;
            if (right < 0) break;            
            for (int i = right; i >= left; --i)    res.push_back(matrix[down][i]);
            --down;
            if (down < 0) break;           
            for (int i = down; i >= up; --i) res.push_back(matrix[i][left]);
            ++left;
            if (left > right) break;
            
        }
       
        return res;

    }
};

int main() {
    vector<vector<int>>matrix{ {1,2,3},{4,5,6},{7,8,9},{10,11,12} };
    vector<int>ans;
    Solution mysolution;
    ans = mysolution.spiralOrder(matrix);
    for (unsigned int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << ' ';
    }


}