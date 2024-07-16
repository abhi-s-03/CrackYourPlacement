class RandomizedCollection {
public:
    vector<int> arr;
    unordered_map<int,unordered_set<int>>m;
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        arr.push_back(val);
        m[val].insert(arr.size()-1);
        return m[val].size()==1;
    }
    
    bool remove(int val) {
        if(m[val].size()==0)
            return false;

        int i=*m[val].begin();
        m[val].erase(i);
        int num=arr.back();
        arr[i]=num;     
        m[num].insert(i);
        m[num].erase(arr.size()-1);

        if (m[val].empty())
            m.erase(val);
        arr.pop_back();
        return true;
    }
    
    int getRandom() {
        return arr[rand()%arr.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */