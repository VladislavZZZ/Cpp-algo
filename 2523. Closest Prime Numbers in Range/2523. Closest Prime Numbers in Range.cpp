// 2523. Closest Prime Numbers in Range.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>


using namespace std;

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        if (left == 1) {
            left = 2;
        }

        int min_distance = INT_MAX;
        int res_ind = -1;

        vector<int> nums(right+1, 1);
        nums[0] = 0;
        nums[1] = 0;
        int size = nums.size();

        for (int elem = 2; elem*elem < size; elem++)
        {
            if (nums[elem] != 0) {
                for (int i = elem*elem; i < size; i+=elem)
                {
                    nums[i] = 0;
                }
            }
        }

        vector<int> primes = {};
        for (int start = left; start < size; start++)
        {
            if (nums[start] != 0) {
                primes.push_back(start);
            }
        }
        size = primes.size();

        for (int start = 0; start < size-1; start++)
        {
            if (primes[start + 1] - primes[start] < min_distance) {
                min_distance = primes[start + 1] - primes[start];
                res_ind = start;
                if (min_distance <= 2) {
                    break;
                }
            }
        }
        if (res_ind != -1) {
            return  vector<int>({ primes[res_ind], primes[res_ind + 1] });
        }
        else {
            return vector<int>({ -1, -1 });
        }

    }
};

int main()
{
    Solution* sol = new Solution();

    vector<int> ans  = sol->closestPrimes(10, 19);
    std::cout << "Hello World!\n";
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
