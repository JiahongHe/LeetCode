class Solution {
public:
    int numJewelsInStones(string J, string S) {
        map<char, int> jewels;
        for (char c : J) {
            jewels.insert(make_pair(c, 0));
        }
        int counter = 0;
        for (char c : S) {
            if (jewels.find(c) != jewels.end()) counter += 1;
        }
        return counter;
    }
};