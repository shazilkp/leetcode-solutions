class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        vector<vector<int>> result;
        int cx,cy;
        for(int i = 0 ; i  < n ; i++){
            cx = intervals[i][0];
            cy = intervals[i][1];
            while(i < n - 1 && cy >= intervals[i+1][0]){
                cy = max(intervals[i+1][1], cy);
                i++;
            }
            result.push_back({cx,cy});
        }
        return result;
    }
};
