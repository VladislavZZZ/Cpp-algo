// 1749. Maximum Absolute Sum of Any Subarray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<math.h>

using namespace  std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int abs_max = 0;

        int size = nums.size();
        vector<vector<int>> db_sum_matrx = {};
        for (auto num: nums) {
            vector<int> start = { num };
            db_sum_matrx.push_back(start);
            abs_max = max(abs(num), abs_max);
        }

        for (int i = 1; i < size -1; i++)
        {
            for (int j = i; j < size; j++)
            {
                int new_val = 0;
                if (i == 1) {
                    new_val = db_sum_matrx[j - 1][i - 1] + db_sum_matrx[j][i-1];
                }
                else {
                    new_val = db_sum_matrx[j - 1][i- 1] + db_sum_matrx[j][i-1] - db_sum_matrx[j-1][i-2];
                }
                db_sum_matrx[j].push_back(new_val);
                abs_max = max(abs(new_val), abs_max);
            }
        }

        return abs_max;
    }
};

int main()
{
    Solution* sol = new Solution();
    vector<int> arr = { 1, -3, 2, 3, -4 };
    int res = sol->maxAbsoluteSum(arr);
    std::cout << res;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
