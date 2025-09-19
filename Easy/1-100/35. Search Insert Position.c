// 35. Search Insert Position
// 
// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, 
// return the index where it would be if it were inserted in order.
// 
// You must write an algorithm with O(log n) runtime complexity.
// 
//  
// 
// Example 1:
// 
// Input: nums = [1,3,5,6], target = 5
// Output: 2
// Example 2:
// 
// Input: nums = [1,3,5,6], target = 2
// Output: 1
// Example 3:
// 
// Input: nums = [1,3,5,6], target = 7
// Output: 4
//  
// 
// Constraints:
// 
// 1 <= nums.length <= 104
// -104 <= nums[i] <= 104
// nums contains distinct values sorted in ascending order.
// -104 <= target <= 104

int searchInsert(int* nums, int nums_size, int target){
    int left, right, mid;
    
    left = 0;
    right = nums_size - 1;

    while (left <= right){
        mid = left + (right - left) / 2;    // evita overflow
        if (nums[mid] == target){
            return mid;                     // trovato esattamente
        } else if (nums[mid] < target){
            left = mid + 1;                 // cerca a destra
        } else {
            right = mid - 1;                // cerca a sinistra
        }
    }
    return left;        // se non trovato -> posizione d'inserimento
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).