class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        stack<int> st;

        int i = 0;
        int currTime = 0;

        while (i < logs.size()) {
            stringstream ss(logs[i]);
            string id, type, time;

            getline(ss, id, ':');
            getline(ss, type, ':');
            getline(ss, time, ':');

            int func = stoi(id);
            int t = stoi(time);

            while (currTime < t) {
                if (!st.empty())
                    ans[st.top()]++;
                currTime++;
            }

            if (type == "start") {
                st.push(func);
            } else {
                ans[st.top()]++;
                st.pop();
                currTime++;
            }

            i++;
        }

        return ans;
    }
};