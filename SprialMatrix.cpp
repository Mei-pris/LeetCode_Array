#include<iostream>
#include<vector>
using namespace  std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty())return res;
        int M = matrix.size() - 1, N = matrix[0].size() - 1;
        int x = 0, y = 0, dx = 0, dy = 1, n = 0;
        while ( M>0 && N>0) {
            dx = 0; dy = 1;
            x = n; y = n;
            while (1){
                res.push_back(matrix[x][y]);
                if (x == n && y == n+N){dx = 1; dy = 0;}
                else if (x == n+M && y == n+N) { dx = 0; dy = -1; }
                else if(x==n+M && y==n){dx = -1; dy = 0; }
                x = x + dx; y = y + dy;                              
                if ((x == n) && (y == n)) break;
            }
            ++n;
            M = M - 2;
            N = N - 2;
        }
        x = n; y = n;
        if (M == 0) {
            while (y <= n+N) 
            {
                res.push_back(matrix[x][y]);
                ++y;
            }
        }
        else if(N==0) {
            while (x <= n + M)
            {
                res.push_back(matrix[x][y]);
                ++x;
            }

        }

        return res;

    }
};

int main() {
    vector<vector<int>>matrix{ {1,2,3},{4,5,6},{7,8,9} };
    vector<int>ans;
    Solution mysolution;
    ans = mysolution.spiralOrder(matrix);
    for (unsigned int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << ' ';
    }


}