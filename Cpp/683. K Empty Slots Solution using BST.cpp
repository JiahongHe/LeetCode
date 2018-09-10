class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        int N = flowers.size();
        if (k > N - 2) return -1;
        set<int> Set;
        for (int i = 0; i < N; i++) {
            int day = flowers[i];
            auto it1 = Set.insert(day).first;
            auto it2 = it1;
            if (++it1 != Set.end() && *it1 == day + k + 1) return i + 1;
            if (it2 != Set.begin() && *(--it2) == day - k - 1) return i + 1;
        }
        return -1;
    }
};