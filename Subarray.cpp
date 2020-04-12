#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int m = nums.size(), i = 0, j = 0, num = s, minnum = m + 1;
        if (m == 0) return 0;
        num -= nums[i];
        while (i < m) {
            while (num > 0 && j <= m - 2) {
                ++j;
                num -= nums[j];
            }
            if (num <= 0) minnum = min(minnum, j - i + 1);
            num += nums[i];
            ++i;
        }
        return (minnum < m + 1 ? minnum : 0);

    }
};

int main() {
    Solution mysolution;
    vector<int>a={2,3,1,2,4,3};
    int ans = mysolution.minSubArrayLen(3,a);
    cout << ans << endl;

}

