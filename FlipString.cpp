#include <iostream>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    /*string reverseWords(string s) {
        int m = s.size(), start = 0, end = 0,idx=0,cnt=0;
        reverse(s.begin(),s.end());
        string res;
        for (int i = 0; i <m; ++i) {
            if (s[i] != ' ') {
                start = i;
                while (i < m && s[i] != ' ') {
                    ++cnt;
                    ++i;
                }
                res += s.substr(start,cnt)+" ";
                reverse(res.begin() + idx, res.begin() + idx + cnt);
                idx += cnt+1;
                cnt = 0;
            }
        }
        if (!res.empty()) res.erase(res.end() - 1);
        return res;
    }*/
    string reverseWords(string s) {
        int m = s.size(), start = 0, end = 0, idx = 0;
        reverse(s.begin(), s.end());
        for (start = 0; start < m; ++start) {
            if (s[start] != ' ') {
                if (idx != 0)
                    s[idx++] = ' ';
                end = start;
                while (end < m && s[end] != ' ')
                    s[idx++] = s[end++];
                reverse(s.begin() + idx - (end - start), s.begin() + idx);
                start = end;
            }
        }
        s.erase(s.begin() + idx, s.end());
        return s;
    }

};

int main() {
    string a = "a good   example";
    string ans;
    Solution mysolution;
    ans = mysolution.reverseWords(a);
    cout << ans << endl;
}
