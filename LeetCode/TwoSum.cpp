#include <iostream>
#include <vector>
#include <string>
using namespace std;



class Solution{
    public:
        vector<int> twoSum(vector<int> &nums, int target) {
            vector<int> result;
            for(int i = 0; i < nums.size(); i++){
                vector<int> result;
                for(int j = i + 1; j < nums.size(); j++){
                    if(nums[i] + nums[j] == target){
                        result.push_back(i);
                        result.push_back(j);
                        return result;
                    }
                }
            }
            return result;          
        }
        
};

int main()
{
    Solution ex1;
    vector<int> nums = {3, 3};
    int target = 6;
    vector<int> result = ex1.twoSum(nums, target);

    cout << "Result:\n";
    for(auto each : result) {
        cout << each << "\n";
    }
    

    return 0;
}