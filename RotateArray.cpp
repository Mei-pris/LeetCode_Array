#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
  /*  //使用环状替换
  void rotate(vector<int>& nums, int k) {
        int m = nums.size(), previous = 0, temp = 0,current=0, next = 0,count=0;
        k = k % m;
        for (int start = 0; count < m; ++start) {
            current = start;
            previous = nums[start];
            do {
                next= (current + k) % m;
                temp = nums[next];
                nums[next] = previous;
                previous = temp;
                current=next;
                ++count;
            } while (current != start);
        }
      
    }*/

    //使用三次反转
    void rotate(vector<int>& nums, int k) {
        int m = nums.size();
        k = k % m;
        reverse(nums,0,m-1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, m - 1);

    }

    void reverse(vector<int>& num, int start, int end) {
        while (start < end) {
            swap(num[start],num[end]);
            ++start;
            --end;
        }
    }

};

int main() {
    vector<int> a = { 1,3,4,2,5,8,9};
    Solution mysolution;
    mysolution.rotate(a, 2);
    for (unsigned int i = 0; i < a.size(); ++i) {
        cout << a[i] << endl;
    }



}