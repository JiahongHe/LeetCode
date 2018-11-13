class Solution {
    vector<int> getNums(int num) {
        vector<int> nums;
        while (num > 0) {
            nums.push_back(num % 10);
            num = num / 10;
        }
        reverse(nums.begin(), nums.end());
        return nums;
    }
public:
    int maximumSwap(int num) {
        vector<int> nums = getNums(num);
        int N = nums.size();
        if (N == 0) return 0;
        vector<int> largest (N, -1);
        vector<int> pos (N, -1);
        largest[N-1] = nums[N-1];
        pos[N-1] = N-1;
        for (int i = N-2; i >= 0; i--) {
            if (nums[i] > largest[i+1]) {
                largest[i] = nums[i];
                pos[i] = i;
            } else {
                largest[i] = largest[i+1];
                pos[i] = pos[i+1];
            }
        }
        for (int i = 0; i < N; i++) {
            if (nums[i] != largest[i]) {
                swap(nums[i], nums[pos[i]]);
                break;
            }
        }
        int result = 0;
        for (int i = N-1; i >= 0; i--) {
            result += nums[i] * pow(10, N-1-i);
        }
        return result;
    }
};