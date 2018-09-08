class Solution {
    unordered_set<string> allPermutations(string time) {
        unordered_set<string> result;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int m = 0; m < 4; m++) {
                    for (int n = 0; n < 4; n++) {
                        if (i == 0 && j == 1 && m == 2 && n == 3) continue;
                        char permu[] = {time[i], time[j], time[m], time[n], '\0'};
                        string permuStr(permu);
                        if (isValidTime(permuStr)) result.insert(permuStr);
                    }
                }
            }
        }
        return result;
    }
    
    bool isValidTime(string permu) {
        if (permu[0] - '0' > 2) return false;
        if (permu[1] - '0' > 3) {
            if (permu[0] - '0' > 1) return false;
        }
        if (permu[2] - '0' > 5) return false;
        return true;
    }
    
    int timeToMinutes (string time) {
        int hour = (time[0] - '0') * 10 + (time[1] - '0');
        int minute = (time[2] - '0') * 10 + (time[3] - '0');
        return hour * 60 + minute;
    }
    
    int timeDiff(string time1, string time2) {
        int timeMin1 = timeToMinutes(time1);
        int timeMin2 = timeToMinutes(time2);
        int diff = timeMin2 - timeMin1;
        return diff > 0 ? diff : diff + 3600;
    }
    
public:
    string nextClosestTime(string time) {
        time = time.substr(0, 2) + time.substr(3, 2);
        unordered_set<string> allTime = allPermutations(time);
        int minDiff = INT_MAX;
        string minTime = "";
        for (auto it = allTime.begin(); it != allTime.end(); it++) {
            int diff = timeDiff(time, *it);
            if (diff < minDiff) {
                minDiff = diff;
                minTime = *it;
            }
        }
        return minTime.substr(0, 2) + ':' + minTime.substr(2, 2);
    }
};