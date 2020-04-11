#include <iostream>
#include<string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        int m = haystack.size(), n = needle.size(), idx = 0;
        if (m < n) return -1;
        string d;
        while (idx <= m) {
            d = haystack.substr(idx, n);
            if (d == needle) return idx;
            else {
                if (idx + n >=m) return -1;
                idx += CalShift(needle, haystack[idx + n], n);
            }
        }

        return -1;
    }

    int CalShift(string a, char b, int& c) {
        int pos = a.find_last_of(b);
        if (pos == -1) return c;
        else return c-pos;
    }
};


int main() {
    string a = "mississippi";
	string  b = "issipi";
    Solution mysolution;
	 int c = mysolution.strStr(a,b);
	cout << c << endl;
}