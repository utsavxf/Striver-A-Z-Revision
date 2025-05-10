class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        //so what we want is that we want each group to have groupSize cards and the numbers written on them should be consecutive
        int n=hand.size();
        if(n%groupSize!=0)return false;
        //pretty easy we can have an ordered map right?
        map<int, int> count;
        for (int card : hand) count[card]++;

        while (!count.empty()) {
            int start = count.begin()->first;
            for (int i = 0; i < groupSize; ++i) {
                int curr = start + i;
                if (count.find(curr) == count.end()) return false;
                if (--count[curr] == 0) count.erase(curr);
            }
        }
        return true;
    }
};
