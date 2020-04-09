#include<iostream>
#include<vector>
using namespace  std;
class Solution {
public :
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>>res(numRows);
		for (unsigned int i = 0; i < numRows; ++i) {
			res[i].resize(i + 1, 1);
			for (int j = 1; j < i; ++j) {
				res[i][j] = res[i - 1][j - 1] + res[i-1][j];
			}
		}
		return res;
	}
};

int main() {
	vector<vector<int>>matrix;
	Solution mysolution;
	matrix = mysolution.generate(5);
	for (int i = 0; i < matrix.size(); ++i) {
		int m = matrix[i].size();
		for( int j=0;j<m;++j)
		cout << matrix[i][j] << ' ';
		cout << endl;
	}


}