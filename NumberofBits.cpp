// 191. Number of 1 Bits
// Easy
// 5.1K
// 1.1K
// Companies
// Write a function that takes the binary representation of an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

// Note:

// Note that in some languages, such as Java, there is no unsigned integer type. In this case, the input will be given as a signed integer type. It should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
// In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 3, the input represents the signed integer. -3.
 

// Example 1:

// Input: n = 00000000000000000000000000001011
// Output: 3
// Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.
// Example 2:

// Input: n = 00000000000000000000000010000000
// Output: 1
// Explanation: The input binary string 00000000000000000000000010000000 has a total of one '1' bit.
// Example 3:

// Input: n = 11111111111111111111111111111101
// Output: 31
// Explanation: The input binary string 11111111111111111111111111111101 has a total of thirty one '1' bits.
 

// Constraints:

// The input must be a binary string of length 32.
 

// Follow up: If this function is called many times, how would you optimize it?

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n){
            if(1 & n) count++;
            n >>= 1;
        } 
        return count;
    }
};

//Approach 2
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n){
            n &= (n-1);
            count++;
        } 
        return count;
    }
};

// 3rd approach (also a good approach, but you must know bitset class)

// Bitset is a array of bools (why are we using it here? because the values here are only in 0's and 1's similar to true and false which are 1 & 0 respectively)

// It is a more compact version of arrays & vectors and have some other restrictions (like you must mention the total size at the time of declaration, etc)

// We use count to see how many bools are true (or how many bits are 1, which we actually want)

class Solution {
public:
    int hammingWeight(uint32_t n) {
        return bitset<32>(n).count();
    }
};