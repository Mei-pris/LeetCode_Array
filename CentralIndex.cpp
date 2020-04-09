#include<iostream>
#include<vector>
using namespace  std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.size() < 3) return -1;
        int rightsum = 0, leftsum = 0;
        for (unsigned int i = 0; i < nums.size(); ++i) {
            rightsum += nums[i];
        }

        for (unsigned int j = 0; j < nums.size(); ++j) {
            if (rightsum - leftsum - nums[j] == leftsum) return j;
            leftsum += nums[j];
        }
        return -1;
    }
};

int main() {
    vector<int>nums{1,7,3,6,5,6};
    Solution mysolution;
    cout << mysolution.pivotIndex(nums) << endl;
}