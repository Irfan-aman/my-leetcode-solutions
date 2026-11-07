class Solution {
public:
    typedef long long ll;
    typedef tuple<ll, int, int> tupleInt;
    typedef pair<ll, int> pi;
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        priority_queue<tupleInt, vector<tupleInt>, greater<tupleInt>>
            busyServers; //<time,weight,serverIdx>
        priority_queue<pi, vector<pi>, greater<pi>>
            freeServers; //<weight,serverIdx>
        for (int i = 0; i < n; i++) {
            freeServers.push({servers[i], i});
        }
        vector<int> result(m);
        ll currTime = 0;
        for (int i = 0; i < m; i++) {
            currTime = max(currTime, (ll)i);
            while (!busyServers.empty() &&
                   get<0>(busyServers.top()) <= currTime) {
                auto [time, wt, serverIdx] = busyServers.top();
                freeServers.push({wt, serverIdx});
                busyServers.pop();
            }
            if (freeServers.empty()) {
                currTime = get<0>(busyServers.top());
                while (!busyServers.empty() &&
                       get<0>(busyServers.top()) <= currTime) {
                    auto [time, wt, serverIdx] = busyServers.top();
                    freeServers.push({wt, serverIdx});
                    busyServers.pop();
                }
            }
            auto minTop = freeServers.top();
            freeServers.pop();
            result[i] = minTop.second;
            busyServers.push(
                {currTime + tasks[i], minTop.first, minTop.second});
        }
        return result;
    }
};