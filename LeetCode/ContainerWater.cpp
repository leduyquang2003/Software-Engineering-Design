#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int length = 0;
        int width = 0;
        int area = 0;
        int Max  = 0;


            


        #if 0
        for(int i = 0; i < height.size(); i++) {
            for(int j = i + 1; j < height.size(); j++) {
                //length
                if(height[i] < height[j]) {
                    length = height[i]; 
                } else {
                    length = height[j];
                }

                //width
                width = j - i;
                area = length * width;
                if(area >= Max)
                    Max = area;
            }
        }
        #endif

        //length vector & width vector
        return Max;
    }
};

int main() {
    Solution Problem;
    int result; //max area
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    result = Problem.maxArea(height);
    cout << result << "\n";
    return 0;
}
