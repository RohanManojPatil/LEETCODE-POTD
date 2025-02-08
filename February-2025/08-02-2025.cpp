*******************************LEETCODE POTD*************************
*	               T.C = O(1)							                * 
*	               							                        * 
*	               S.C = O(N)                                           * 
*	                                                                * 
*********************************************************************
class NumberContainers {
public:
    unordered_map<int, set<int>> positions;
    unordered_map<int, int> mp;

    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(mp.find(index) != mp.end())
        {
            int value = mp[index];
            positions[value].erase(index);
            if(positions[value].size() == 0)
            {
                positions.erase(value);
            }
        }

        mp[index] = number;
        positions[number].insert(index);
    }
    
    int find(int number) {
        if(positions.find(number) == positions.end())
        {
            return -1;
        }

        return *(positions[number].begin());
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */