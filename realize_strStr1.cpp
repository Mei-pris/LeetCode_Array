#include <iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        int n1 = haystack.size(), n2 = needle.size(), ii = 0, jj = 0;
        if (n1 < n2) return -1;
        vector<int>next = CalNext(needle);
        while (ii < n1 && jj < n2) {
            if (jj == -1 || haystack[ii] == needle[jj]) {
                ++ii;
                ++jj;
            }
            else jj = next[jj];
        }
        if (jj == n2)  return ii - jj;
        else  return -1;
    }

    vector<int> CalNext(string a) {
        int m = a.size(), k = -1, j = 0;
        vector<int>c(m);
        c[j] = k;
        while (j < m - 1) {
            if (k == -1 || a[k] == a[j]) {
                ++j;
                ++k;
                c[j] = k;
            }
            else k = c[k];
        }
        return c;


    }
};


int main() {
    string aa = "abcdabcd";
    string  bb = "abcab";
    Solution mysolution;
    int c = mysolution.strStr(aa, bb);
    cout << c << endl;

}