class MyCalendarTwo {
public:
    map<int, int> ranges;

    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        int activeBookings = 0;

        ranges[start]++;
        ranges[end]--;
        
        for (auto& [time, count] : ranges) {
            activeBookings += count;

            if (activeBookings >= 3) {
                ranges[start]--;
                ranges[end]++;
                if (ranges[start] == 0) {
                    ranges.erase(start);
                }
                if (ranges[end] == 0) {
                    ranges.erase(end);
                }
                return false;
            }
        }

        return true;
    }
};
/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */