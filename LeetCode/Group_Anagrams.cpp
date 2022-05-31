#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm> 
using namespace std;

void sortString(string &str) {
    sort(str.begin(), str.end());
}

class Solution {
public:
    void groupAnagrams(vector<string>& strs) {
        
        vector<string> temp = strs; 
        
        for(int i = 0; i < strs.size(); i++) {
            sortString(strs[i]);
        }

        sort(strs.begin(), strs.end());
        


    }
};

int main() {
    vector<string> strs = {
        "eat","tea","tan","ate","nat","bat"
    };

    

    Solution sol;
    sol.groupAnagrams(strs);

    return 0;
}
