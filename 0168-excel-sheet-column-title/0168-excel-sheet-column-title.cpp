class Solution {
public:
    int arr1[6];
    int arr2[6];
    string arr3 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string c(int col){
        if(col <= 26)return arr3.substr(col-1,1);
        int num = arr1[5];
        for(int i = 1;i<6;i++){
            if(col <= arr2[i]){
                num = arr1[i-1];
                break;
            }
        }
        string a = arr3.substr((col-1)/num -1,1);
        int b = col%num;
        if(!(b))b = col - num*((col-1)/num);
        a += c(b);
        return a;
    }

    string convertToTitle(int columnNumber) {
        if(columnNumber <= 26)return arr3.substr(columnNumber-1,1);
        arr1[0] = 26,arr2[0] = 26;
        for(int i = 1;i<=5;i++){
            arr1[i] = 26 * arr1[i-1];
            arr2[i] = arr1[i] + arr2[i-1];
        }
        string a = c(columnNumber);
        return a;
    }
};