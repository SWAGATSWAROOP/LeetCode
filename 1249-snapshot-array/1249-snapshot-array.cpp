class SnapshotArray {
public:
    vector<vector<pair<int,int>>> v;
    int a;
    SnapshotArray(int length) {
        a = 0;
        for(int i = 0;i<length;i++){
            vector<pair<int,int>> l(1,make_pair(0,0));
            v.push_back(l);
        }
    }
    
    void set(int index, int val) {
        v[index].push_back(make_pair(a,val));
    }
    
    int snap() {
        return a++;
    }
    
    int get(int index, int snap_id) {
        auto itr = upper_bound(v[index].begin(),v[index].end(),make_pair(snap_id,INT_MAX));
        return prev(itr)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */