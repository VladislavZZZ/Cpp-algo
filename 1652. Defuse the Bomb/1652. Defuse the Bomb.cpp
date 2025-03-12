// 1652. Defuse the Bomb.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int size = code.size();
        vector<int> result(size, 0);
        if (k > 0) {
            for (int i = 0; i < size; i++) {
                for (int l = 1; l <= k; l++) {
                    if (i + l >= size) {
                        result[i] += code[-size + i + l];
                    }
                    else {
                        result[i] += code[i + l];
                    }
                }
            }
        }
        if (k < 0) {
            for (int i = 0; i < size; i++) {
                for (int l = 1; l <= abs(k); l++) {
                    if (i - l < 0) {
                        result[i] += code[size + i - l];
                    }
                    else {
                        result[i] += code[i - l];
                    }
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution* sol = new Solution();
    vector<int>a({ 2,4,9,3 });
    sol->decrypt(a, -2);
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
