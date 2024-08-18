
class Solution {
public:
    int nthUglyNumber(int n) {
        set<long> st;  // Use set to keep elements sorted
        st.insert(1);        // Start with the first ugly number
        long ugly = 1;

        for (int i = 1; i < n; ++i) {
            ugly = *st.begin();  // Get the smallest element in the set
            st.erase(st.begin()); // Remove it from the set

            // Insert the next multiples of 2, 3, and 5
            st.insert(ugly * 2);
            st.insert(ugly * 3);
            st.insert(ugly * 5);
        }

        return *st.begin();  // The nth ugly number
    }
};