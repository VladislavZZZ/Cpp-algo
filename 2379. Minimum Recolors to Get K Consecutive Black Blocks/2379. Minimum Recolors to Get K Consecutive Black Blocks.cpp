// 2379. Minimum Recolors to Get K Consecutive Black Blocks.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>

using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int size = blocks.size();
        int min_recolors = k;
        int recolors = 0;
            for (int i = 0; i < k; i++) {
                if(blocks[i] == 'W') recolors++;
            }
        min_recolors = recolors;
        for (int i = k; i < size; i++) {
            if (blocks[i - k] == 'W') recolors--;
            if (blocks[i] == 'W') recolors++;
            if (recolors < min_recolors) min_recolors = recolors;
        }
        return min_recolors;
    }
};

int main()
{
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
