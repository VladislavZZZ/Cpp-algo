// 46. Permutations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;


class Solution {
public:
   
    vector<vector<int>> permute(vector<int>nums) {
        vector<vector<int>> permutations;
        if (nums.size() == 1) {
            permutations.push_back(nums);
            return permutations;
        }


        for (int i = nums.size() -1; i != -1; i--) {
            int num = nums.back();
            nums.pop_back();
            vector<vector<int>> sub_perms = permute(nums);

            for (auto it = sub_perms.begin(); it != sub_perms.end(); it++) {
                it->push_back(num);
            }
            permutations.insert(permutations.end(), sub_perms.begin(), sub_perms.end());
            nums.push_back(num);
        }
        return permutations;
    }
        
};

int main()
{
    Solution* sol = new Solution();
    vector<int> s = {1,2,3};
    vector<vector<int>> v = sol->permute(s);
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
