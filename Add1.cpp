#include<iostream>
#include<vector>
using namespace  std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        unsigned int i = n - 1;
        while (i >= 1) {
            if (digits[i] == 9)  digits[i] = 0;
            else {
                ++digits[i];
                return digits;
            }
            --i;
        }

        if (digits[0] == 9) {
            digits.push_back(0);
            digits[0] = 0;
            for (unsigned int j = 0; j < n; ++j) {
                digits[j + 1] = digits[j];
            }
            digits[0] = 1;
            return digits;
        }
        else
            ++digits[0];
        return digits;

    }
};

int main() {
    vector<int>nums{9};
    vector<int> a;
    Solution mysolution;
    a=mysolution.plusOne(nums);
    for (unsigned int i = 0; i < a.size(); ++i) {
        cout << a[i] << ' ';
    }
}