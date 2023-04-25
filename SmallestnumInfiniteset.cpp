// 6. Smallest Number in Infinite Set
// Medium
// 958
// 95
// Companies
// You have a set which contains all positive integers [1, 2, 3, 4, 5, ...].

// Implement the SmallestInfiniteSet class:

// SmallestInfiniteSet() Initializes the SmallestInfiniteSet object to contain all positive integers.
// int popSmallest() Removes and returns the smallest integer contained in the infinite set.
// void addBack(int num) Adds a positive integer num back into the infinite set, if it is not already in the infinite set.
 

// Example 1:

// Input
// ["SmallestInfiniteSet", "addBack", "popSmallest", "popSmallest", "popSmallest", "addBack", "popSmallest", "popSmallest", "popSmallest"]
// [[], [2], [], [], [], [1], [], [], []]
// Output
// [null, null, 1, 2, 3, null, 1, 4, 5]

// Explanation
// SmallestInfiniteSet smallestInfiniteSet = new SmallestInfiniteSet();
// smallestInfiniteSet.addBack(2);    // 2 is already in the set, so no change is made.
// smallestInfiniteSet.popSmallest(); // return 1, since 1 is the smallest number, and remove it from the set.
// smallestInfiniteSet.popSmallest(); // return 2, and remove it from the set.
// smallestInfiniteSet.popSmallest(); // return 3, and remove it from the set.
// smallestInfiniteSet.addBack(1);    // 1 is added back to the set.
// smallestInfiniteSet.popSmallest(); // return 1, since 1 was added back to the set and
//                                    // is the smallest number, and remove it from the set.
// smallestInfiniteSet.popSmallest(); // return 4, and remove it from the set.
// smallestInfiniteSet.popSmallest(); // return 5, and remove it from the set.
 

// Constraints:

// 1 <= num <= 1000
// At most 1000 calls will be made in total to popSmallest and addBack.
// Accepted
// 61.7K
// Submissions
// 82.8K
// Acceptance Rate
// 74.5%
//using Map
class SmallestInfiniteSet {
public:
    priority_queue<int,vector<int>,greater<int> > v;
    unordered_map<int,bool> mp; 
    SmallestInfiniteSet() {
        for(int i = 1;i<=1000;i++){
            v.push(i);
            mp[i] = true;
        }
    }
    
    int popSmallest() {
        int m = v.top();
        v.pop();
        mp.erase(m);
        return m;
    }
    
    void addBack(int num) {
        if(mp.count(num)>0)return;
        mp[num] = true;
        v.push(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */

//Using Set
class SmallestInfiniteSet {
public:
    set<int> s;
    SmallestInfiniteSet() {
        for(int i = 1;i<=1000;i++)s.insert(i);
    }
    
    int popSmallest() {
        int m = *s.begin();
        s.erase(s.begin());
        return m;
    }
    
    void addBack(int num) {
        s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */