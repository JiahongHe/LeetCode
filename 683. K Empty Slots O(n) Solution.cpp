class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        int N = flowers.size();
        if (k > N - 1) return -1;
        int numBucket = (N + k) / (k + 1);
        vector<int> bucketLow (numBucket, INT_MAX);
        vector<int> bucketHigh (numBucket, INT_MIN);
        for (int i = 0; i < N; i++) {
            int pos = flowers[i];
            int bucketNumber = pos / (k + 1);
            if (pos < bucketLow[bucketNumber]) {
                bucketLow[bucketNumber] = pos;
                if (bucketNumber > 0 && bucketHigh[bucketNumber - 1] == pos - k - 1) return i + 1;
            }
            if (pos > bucketHigh[bucketNumber]) {
                bucketHigh[bucketNumber] = pos;
                if (bucketNumber < (numBucket - 1) && bucketLow[bucketNumber + 1] == pos + k + 1) return i + 1;
            }
        }
        return -1;
    }
};