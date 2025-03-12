// 2529. Maximum Count of Positive Integer and Negative Integer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>

using namespace std;
int binary_search(vector<int>& nums, int left, int right, bool is_negative, int size) {
    int center = (left + right) / 2;
    if (left == right) {
        return center;
    }
    if (is_negative) {
        if (nums[center] < 0) {
            return binary_search(nums, center + 1, right, is_negative, size);
        }
        else {
            return binary_search(nums, left, right - 1, is_negative, size);
        }
    }
    else {
        if (nums[center] <= 0) {
            return binary_search(nums, center + 1, right, is_negative, size);
        }
        else {
            return binary_search(nums, left, right - 1, is_negative, size);
        }
    }
}
int maximumCount(vector<int>& nums) {
    int size = nums.size();
    int last_neg = binary_search(nums, 0, size , true, size);
    int first_pos = binary_search(nums, 0, size, false, size);
    int neg_num = 0;
    int pos_num = 0;
    neg_num = last_neg;
    pos_num = size - first_pos;
    return max(neg_num, pos_num);
}
int main()
{
    std::cout << round(2.5);
    vector<int>s({ 0,0,0 });
    int res = maximumCount(s);
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
