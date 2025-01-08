// PrefixSuffixPairs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//      You are given a 0-indexed string array words.

//Let's define a boolean function isPrefixAndSuffix that takes two strings, str1 and str2:

// isPrefixAndSuffix(str1, str2) returns true if str1 is both a prefix and a suffix
//of str2, and false otherwise.
//For example, isPrefixAndSuffix("aba", "ababa") is true because "aba" is a prefix of "ababa" and also a suffix, but isPrefixAndSuffix("abc", "abcd") is false.

//Return an integer denoting the number of index pairs(i, j) such that i < j, and isPrefixAndSuffix(words[i], words[j]) is true.

#include <iostream>
#include <vector>
#include<string>
using namespace std;

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int counter = 0;
        for (auto it1 = begin(words); it1 != end(words); ++it1) {
            for (auto it2 = it1+1; it2 != end(words); ++it2) {
                if (it1->length() <= it2->length() && this->isPrefixAndSuffix(*it1,*it2)) {
                    counter++;
                }
            }
        }
        return counter;
    };
private:
    bool isPrefixAndSuffix(string word1,string word2) {
        return word1 == word2.substr(0, word1.length()) && word1==word2.substr(word2.length() - word1.length(), word1.length());
    };
};
int main()
{
    vector<string> words = { "a","aba","ababa","aa" };
    Solution* sol = new Solution();
    int count  = sol->countPrefixSuffixPairs(words);
    std::cout << count << endl;
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
