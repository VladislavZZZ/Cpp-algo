// ParenthesesString.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//A parentheses string is a non - empty string consisting only of '(' and ')'.It is valid if any of the following conditions is true:

//It is().
//It can be written as AB(A concatenated with B), where Aand B are valid parentheses strings.
//It can be written as(A), where A is a valid parentheses string.
//You are given a parentheses string sand a string locked, both of length n.locked is a binary string consisting only of '0's and '1's.For each index i of locked,

//If locked[i] is '1', you cannot change s[i].
//But if locked[i] is '0', you can change s[i] to either '(' or ')'.
//Return true if you can make s a valid parentheses string.Otherwise, return false.

#include <iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    stack<bool> st = {};
    bool canBeValid(string s, string locked) {
        if (s.size() % 2 == 1) {
            return false;
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(true);
            }
            else if (st.empty()){
                if (locked[i] != '0') {
                    return false;
                }
                else {
                    st.push(true);
                }
                
            }
            else {
                st.pop();
            } 
        }
        if (st.empty()) {
            return true;
        }
        else {
            return false;
        }
       
    }
};

int main()
{
    Solution* sol = new Solution();
    string s = "))()))";
    string locked = "010100";
    bool answer = sol->canBeValid(s, locked);
    std::cout << answer;
}
