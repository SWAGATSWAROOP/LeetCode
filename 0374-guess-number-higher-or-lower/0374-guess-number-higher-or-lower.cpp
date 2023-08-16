/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * 
 */
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int i = 1;
        while(i<=n){
            int mid = i + (n-i)/2;
            switch(guess(mid)){
                case -1:
                n = mid-1;
                break;
                 
                case 1:
                i = mid+1;
                break;

                case 0:
                return mid;
            }
        }
        return -1;
    }
};