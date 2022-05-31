#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm> 
using namespace std;

void sortString(string &str) {
    sort(str.begin(), str.end());
}

void counter_character(string str) {
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] == )
    }
}

class Solution {
public:
    bool isAnagram(string &s, string &t) {
        #if 0
        sortString(s);
        sortString(t);
        if(s == t)
            return true;
        else
            return false;
        #endif
        return true;

    }
};

int main() {
    Solution sol;
    string s = "anagram";
    string t = "nagarab";



    //cout << sol.isAnagram(s, t);



    return 0;
}