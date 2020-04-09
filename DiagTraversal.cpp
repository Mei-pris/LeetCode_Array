#include<iostream>
#include<vector>
using namespace  std;
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty())return res;
        int M = matrix.size() - 1, N = matrix[0].size() - 1;
        for (int i = 0; i < N + M + 1; i++) {
            if (i & 1) {//ÆæÊý
                int j =0,k = i;
                if (i > N)
                {
                    j = i - N;
                    k = N;
                }
                while (j <= M && k >= 0) {
                    res.push_back(matrix[j][k]);
                    ++j;
                    --k;
                }
            }
            else {
                int j = i, k = 0;
                if (i > M)
                {
                    j = M;
                    k = i - M;
                }
                while (k <= N && j >= 0) {
                    res.push_back(matrix[j][k]);
                    --j;
                    k++; 
                }
            }
        }
        return res;
       
    }

};

int main() {
    vector<vector<int>>matrix{ {1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int>ans;
    Solution mysolution;
    ans = mysolution.findDiagonalOrder(matrix);
    for (unsigned int i = 0; i < ans.size();++i) {
        cout << ans[i] << ' ';
    }


}