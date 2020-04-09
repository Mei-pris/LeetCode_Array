#include <iostream>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
   /* string addBinary(string a, string b){
        string c;
        int n1 = a.size()-1, n2 = b.size()-1,n;
        if (n1 >= n2) { c=a; n = n1; }
        else { c=b; n = n2; }
        char lastflag = '0',newflag='0';
        while(n1>=0&&n2>=0){
            lastflag = newflag; newflag = '0';
            c[n] = Add(a[n1], b[n2], newflag);        
            if (lastflag == '1')  c[n] = Add(c[n], lastflag, newflag);
            --n;
            --n1; --n2;
        }

        while (n >=0){
            lastflag = newflag; newflag = '0';
            if (lastflag == '0') return c;
            c[n] = Add(c[n], lastflag, newflag);
            --n;
        }        
        if (newflag == '1') return "1" + c;
        else   return c;
    }*/
  
    /*char Add(char m, char n,char &upflag) {
        char res='0';
        if (m =='0') {
            if (n == '0') { res = '0'; return res;}
            else { res = '1'; return res; }
        }
        else {
            if (n == '0') { res = '1'; return res; }
            else { res='0'; upflag='1'; return res;}

        }
    }*/

    string addBinary(string a, string b) {
        string c;
        int sum = 0, n1 = a.size() - 1, n2 = b.size()-1,up=0;
        while (n1>=0 ||n2>=0) {
            sum = up;
            sum += (n1>=0?a[n1]-'0':0);
            sum += (n2>=0?b[n2]-'0':0);
            string cc = to_string(sum % 2);
            c.append(cc);
            up = sum / 2;
            --n1; --n2;
        }
        if (up == 1) c.append("1");
        reverse(c.begin(),c.end());
        return c;

    }



};
int main() {
    string s1 = "1011",s2="11";
    Solution mysolution;
    string ans = mysolution.addBinary(s1, s2);
    cout << ans << endl;
  
}