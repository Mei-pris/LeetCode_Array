#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1,num=target;
        vector<int> res(2);
        while (left < right) {
             num-= numbers[left];
            while (numbers[right] > num) --right;
            if (numbers[right] == num) {
                res[0] = left + 1;
                res[1] = right + 1;
                return res;
            }
            else { ++left; num = target;}
        }
        return res;
    }
};

int main() {
    vector<int> a{ 5,25,75}; vector<int>b;
    Solution mysolution;
    b = mysolution.twoSum(a,100);
    cout << b[0] << " " << b[1] << endl; 
}