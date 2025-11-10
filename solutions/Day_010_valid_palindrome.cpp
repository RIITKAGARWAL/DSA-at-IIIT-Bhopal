/**
 * Problem: Valid Palindrome
 * Day: 10 / 288
 * Category: Two Pointers
 * Approach: Alphanumeric boundary convergence
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            while (l < r && !isalnum(s[l])) l++;
            while (l < r && !isalnum(s[r])) r--;
            if (tolower(s[l]) != tolower(s[r])) return false;
            l++; r--;
        }
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    bool res = s.isPalindrome("A man, a plan, a canal: Panama");

    cout << "Passed test for Valid Palindrome" << endl;
    return 0;
}
