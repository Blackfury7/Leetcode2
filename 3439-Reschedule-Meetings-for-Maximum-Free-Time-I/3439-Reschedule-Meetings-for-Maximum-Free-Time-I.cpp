class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int left = 0, right = k - 1, n = startTime.size(), ans = 0;
        vector<int> prefix(n+1);
        prefix[0] = 0;
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += endTime[i] - startTime[i];
            prefix[i+1] = sum;
        }
        while(right < n){
            int totalTime = endTime[right] - startTime[left];
            int totalEventTime = prefix[right+1] - prefix[left];
            int freeTime = totalTime - totalEventTime;
            int start = (left - 1 >= 0) ? endTime[left - 1] : 0;
            freeTime += startTime[left] - start;
            int end = (right + 1 < n) ? startTime[right + 1] : eventTime;
            freeTime += end - endTime[right];
            ans = max(ans, freeTime);
            left++;
            right++; 
        }
        return ans;
    }
};