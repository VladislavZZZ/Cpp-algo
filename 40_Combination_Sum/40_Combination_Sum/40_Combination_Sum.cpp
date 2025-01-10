// 40_Combination_Sum.cpp : This file contains the 'main' function. Program execution begins and ends there.


//Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

//Each number in candidates may only be used once in the combination.
//
//Note: The solution set must not contain duplicate combinations.

#include <iostream>
#include <vector>
#include<set>
using namespace std;


class Solution {
public:
    vector<vector<int>> res = {};
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> sequence = {};
        int n = candidates.size();
        quickSort(candidates, 0, n - 1);
        int prev = -1;
        find_all_subseqs(-1, sequence, 0, -1, candidates, target);
        return res;
    }

private:
    int partition(vector<int>& vec, int low, int high) {

        int pivot = vec[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {
            if (vec[j] <= pivot) {
                i++;
                swap(vec[i], vec[j]);
            }
        }

        swap(vec[i + 1], vec[high]);

        return (i + 1);
    }

    void quickSort(vector<int>& vec, int low, int high) {

        if (low < high) {

            int pi = partition(vec, low, high);

            quickSort(vec, low, pi - 1);
            quickSort(vec, pi + 1, high);
        }
    }
    void find_all_subseqs(int position, vector<int>& sequence,int sum,int prev, vector<int>& candidates, int target) {
        for (int i = position+1; i < candidates.size(); i++)
        {
            if (prev == candidates[i]) {
                continue;
            }
            sequence.push_back(candidates[i]);
            sum += candidates[i];
            if (sum == target) {
                res.push_back(sequence);
            }
            if (sum < target) {
                find_all_subseqs(i, sequence, sum, prev, candidates, target);
                prev = sequence.back();
                sum -= prev;
                sequence.pop_back();
            }else {
                sequence.pop_back();
                return;
            }
        } 
        return;
    }
};


int main()
{
    Solution* sol = new Solution();
    vector<int> candidates = { 10,1,2,7,6,1,5 };
    int target = 8;
    vector<vector<int>> res  = sol->combinationSum2(candidates, target);
    cout << "[" << endl;
    for (auto i :res)
    {
        cout << "[";
        for (int j : i)
        {

            cout << j << ", ";
        }
        cout << "]" << endl;
    }
    
}
   