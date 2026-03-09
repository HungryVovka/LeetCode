// 11. Container With Most Water
//
// You are given an integer array height of length n. There are n vertical lines drawn 
// such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
// 
// Find two lines that together with the x-axis form a container, such that the container 
// contains the most water.
// 
// Return the maximum amount of water a container can store.
// 
// Notice that you may not slant the container.
// 
// 
// Example 1:
// 
// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. 
// In this case, the max area of water (blue section) the container can contain is 49.
// 
// Example 2:
// 
// Input: height = [1,1]
// Output: 1
//  
// 
// Constraints:
// 
// n == height.length
// 2 <= n <= 10^5
// 0 <= height[i] <= 10^4

int maxArea(int* height, int heightSize){
    int l = 0;
    int r = heightSize - 1;
    int max_area = 0;

    while (l < r){
        int h = height[l] < height[r] ? height[l] : height[r];
        int width = r - l;
        int area = h * width;
        if (area > max_area) max_area = area;
        if (height[l] < height[r]){
            l++;
        } else {
            r--;
        }
    }
    return max_area;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).