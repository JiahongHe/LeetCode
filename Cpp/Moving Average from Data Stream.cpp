class MovingAverage {
public:
    /** Initialize your data structure here. */
    queue<int> que;
    int k;
    double avg;
    MovingAverage(int size) {
        queue<int> que;
        k = size;
        avg = 0;
    }
    
    double next(int val) {
        if (que.size() < k) {
            avg = ((avg * que.size()) + val) / ((double)que.size() + 1);
            que.push(val);
        }
        else {
            int last_val = que.front();
            avg = ((avg * que.size()) - last_val + val) / (double)que.size();
            que.pop();
            que.push(val);
        }
        return avg;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */