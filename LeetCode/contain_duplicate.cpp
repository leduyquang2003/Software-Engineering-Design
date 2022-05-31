#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm> 
#include <set>



using namespace std;

//Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.





class Solution {
public:
    bool containsDuplicate(vector<int> & nums) {

        
        //Sort solution
        std::sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] == nums[i + 1]) {
                return true;
            }
        }
        return false;
        
        //Set solution
        set<int, greater<int>> s;
        s.insert(nums.begin(), nums.end());
        if(s.size() != nums.size()) {
            return true;
        } else {
            return false;
        }
        
    }

};

int main() {
    vector<int> nums = {1,2,3,4,5,6,7,8,10,9,11,12,13};
    Solution func;
    func.containsDuplicate(nums);

    return 0;
}