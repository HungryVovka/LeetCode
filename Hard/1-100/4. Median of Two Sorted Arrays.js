// 4. Median of Two Sorted Arrays
//
// Given two sorted arrays nums1 and nums2 of size m and n 
// respectively, return the median of the two sorted arrays.
// 
// The overall run time complexity should be O(log (m+n)).
// 
// 
// Example 1:
// 
// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.
// 
// Example 2:
// 
// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
//  
// 
// Constraints:
// 
// nums1.length == m
// nums2.length == n
// 0 <= m <= 1000
// 0 <= n <= 1000
// 1 <= m + n <= 2000
// -10^6 <= nums1[i], nums2[i] <= 10^6

"use strict";
/*
Built'un libraries used:
Math
// Math.floor()
// Math.max()
// Math.min()
*/

/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(nums1, nums2){
    var arrayA;
    var arrayB;
    var lengthA;
    var lengthB;
    
    var left;
    var right;
    var partitionA;
    var partitionB;

    var maxLeftA;
    var minRightA;
    var maxLeftB;
    var minRightB;

    var totalLength;
    var halfLength;

    // binary search
    if (nums1.length <= nums2.length){
        arrayA = nums1;
        arrayB = nums2;
    } else {
        arrayA = nums2;
        arrayB = nums1;
    }

    lengthA = arrayA.length;
    lengthB = arrayB.length;

    totalLength = lengthA + lengthB;
    halfLength = Math.floor((totalLength + 1) / 2);

    left = 0;
    right = lengthA;

    while (left <= right){
        partitionA = Math.floor((left + right) / 2);
        partitionB = halfLength - partitionA;

        maxLeftA = (partitionA === 0) ? -Infinity : arrayA[partitionA - 1];
        minRightA = (partitionA === lengthA) ? Infinity : arrayA[partitionA];

        maxLeftB = (partitionB === 0) ? -Infinity : arrayB[partitionB - 1];
        minRightB = (partitionB === lengthB) ? Infinity : arrayB[partitionB];

        if (maxLeftA <= minRightB && maxLeftB <= minRightA){
            if (totalLength % 2 === 1){
                return Math.max(maxLeftA, maxLeftB);
            }
            return (Math.max(maxLeftA, maxLeftB) + Math.min(minRightA, minRightB)) / 2;
        } else if (maxLeftA > minRightB){
            right = partitionA - 1;
        } else {
            left = partitionA + 1;
        }
    } 
    return 0;
};

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).