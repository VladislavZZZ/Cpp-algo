// 1028. Recover a Tree From Preorder Traversal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    pair<int, string>* v = new pair<int, string>(0, "");
    pair<int, string>* get_value_str(string str, int depth) {
        int size = str.size();
        if (size == 0) {
            return nullptr;
        }
        int position = depth;
        string val_s = "";
        for (int i = position; i < size && str[i] != '-'; i++)
        {
            val_s += str[i];
            position = i + 1;
        }
        v->first = stoi(val_s);
        v->second = str.substr(position);
        return v;
    }

    int get_left_right_subtrees(string& str, int depth) {
        int local_size = str.size();
        int local_depth = 0;
        for (int i = depth + 1; i < local_size; i++) {
            if (str[i] != '-' && local_depth == depth) {
                return i - depth;
            }
            else if (str[i] != '-') {
                local_depth = 0;
            }
            else {
                local_depth++;
            }
        }
        return local_size;
    }


    TreeNode* build_tree(string substring, int curr_depth, int value) {
        TreeNode* new_node = new TreeNode(value);
        if (substring.size() == 0) {
            return new_node;
        }

        int split_position = get_left_right_subtrees(substring, curr_depth);


        pair<int, string>* substrs_left = get_value_str(substring.substr(0, split_position), curr_depth);
        new_node->left = build_tree(substrs_left->second, curr_depth + 1, substrs_left->first);


        pair<int, string>* substrs_right = get_value_str(substring.substr(split_position), curr_depth);
        if (substrs_right) {
            new_node->right = build_tree(substrs_right->second, curr_depth + 1, substrs_right->first);
        }

        return new_node;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        int ind = 0;
        char ch = traversal[ind];
        string val_s = "";
        for (int i = 0; i < traversal.size() && traversal[i] != '-'; i++)
        {
            val_s += traversal[i];
            ind = i + 1;
        }
        int val = stoi(val_s);
        int depth = 1;
        TreeNode* root = build_tree(traversal.substr(ind), depth, val);
        return root;
    }
};

int main()
{
    string traversal = "3";
    Solution* sol = new Solution();
    TreeNode* res = sol->recoverFromPreorder(traversal);
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
