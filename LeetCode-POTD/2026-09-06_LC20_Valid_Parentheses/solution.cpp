#include <string>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        while (s.find("()") != string::npos || s.find("[]") != string::npos || s.find("{}") != string::npos) {
            size_t p = s.find("()");
            if (p != string::npos) s.erase(p, 2);
            p = s.find("[]");
            if (p != string::npos) s.erase(p, 2);
            p = s.find("{}");
            if (p != string::npos) s.erase(p, 2);
        }
        return s.empty();
    }
};