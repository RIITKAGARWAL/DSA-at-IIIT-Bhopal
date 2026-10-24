#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (const auto& row : matrix) {
            for (int x : row) {
                if (x == target) return true;
            }
        }
        return false;
    }
};