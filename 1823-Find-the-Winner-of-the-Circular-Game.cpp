class Solution {
public:
    int findTheWinner(int n, int k) {
        int sz = n,top;
        queue<int> q;
        for(int i = 1;i <= n;i++)q.push(i);
        int count = 1;
        while(!q.empty()){
            top = q.front();
            q.pop();
            if(count != k)q.push(top);
            else count = 0;
            count++;
            
        }
        return top;
    }
};