class MyCalendar {
public:
    // Custom hash function for pair<int, int>
    struct pair_hash {
        template <class T1, class T2>
        std::size_t operator() (const std::pair<T1, T2> &p) const {
            return std::hash<T1>()(p.first) ^ std::hash<T2>()(p.second);
        }
    };
    
    std::unordered_map<std::pair<int, int>, bool, pair_hash> mp;

    MyCalendar() {
    }

    bool book(int start, int end) {
        for (const auto& [slot, status] : mp) {
            if ((start >= slot.first && start < slot.second) || 
                (end > slot.first && end <= slot.second) ||
                (start <= slot.first && end >= slot.second)) {
                return false;
            }
        }
        mp[{start, end}] = true;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */