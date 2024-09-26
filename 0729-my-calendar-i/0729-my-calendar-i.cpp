class MyCalendar {
public:

    set<pair<int, int>> ranges;

    bool rangeCheck(int rangeFirst, int rangeSecond, int targetFirst, int targetSecond) {
        if (rangeFirst > targetFirst && rangeFirst < targetSecond) {
            return true;
        }

        if (rangeSecond > targetFirst && rangeSecond < targetSecond) {
            return true;
        }

        if (rangeFirst <= targetFirst && rangeSecond >= targetSecond) {
            return true;
        }

        return false;
    }

    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        pair<int, int> range = {start, end};

        auto it = ranges.lower_bound(range);

        if (it != ranges.end() && rangeCheck(start, end, it->first, it->second)) {
            return false;
        }

        if (it != ranges.begin()) {
            --it;
            if (rangeCheck(start, end, it->first, it->second)) {
                return false;
            }
        }

        ranges.insert(range);
        return true;
    }
};
