class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Sort intervals based on the start time
        sort(intervals.begin(), intervals.end());
        stack<pair<int, int>> st;

        for (const auto& itv : intervals) {
            int start = itv[0], end = itv[1];

            if (st.empty() || st.top().second < start) {
                // No overlap, push interval
                st.push({start, end});
            } else {
                // Overlap, so merge
                auto top = st.top(); st.pop();
                st.push({top.first, max(top.second, end)});
            }
        }

        // Collect from stack (reverse order)
        vector<vector<int>> result;
        while (!st.empty()) {
            result.push_back({st.top().first, st.top().second});
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
