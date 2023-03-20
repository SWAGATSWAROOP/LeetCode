// 605. Can Place Flowers
// Easy
// 4.7K
// 812
// Companies
// You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

// Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule.

 

// Example 1:

// Input: flowerbed = [1,0,0,0,1], n = 1
// Output: true
// Example 2:

// Input: flowerbed = [1,0,0,0,1], n = 2
// Output: false
 

// Constraints:

// 1 <= flowerbed.length <= 2 * 104
// flowerbed[i] is 0 or 1.
// There are no two adjacent flowers in flowerbed.
// 0 <= n <= flowerbed.length
// Accepted
// 410.3K
// Submissions
// 1.2M
// Acceptance Rate
// 32.9%

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0,m = flowerbed.size();
        for(int i = 0;i<m;){
            if(flowerbed[i])i+=2;
            else if(i+1<m && flowerbed[i+1])i += 3;
            else{
                count++;
                i+=2;
            }
        }
        return (count>= n);
    }
};