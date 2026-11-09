class Solution {
public:
    typedef pair<int, int> pi; //<finish time, server no>
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();
        set<int> availableServers;
        for (int i = 0; i < k; i++)
            availableServers.insert(i);
        priority_queue<pi, vector<pi>, greater<pi>> busyServers;
        int maxFreqUsed = 0;
        vector<int> freqServerUsed(k, 0);
        for (int i = 0; i < n; i++) {
            int currTime = arrival[i];
            while (!busyServers.empty() &&
                   busyServers.top().first <= currTime) {
                availableServers.insert(busyServers.top().second);
                busyServers.pop();
            }
            if (availableServers.empty()) {
                continue;
            }
            int server = i % k;
            auto it = availableServers.lower_bound(server);
            if (it == availableServers.end())
                it = availableServers.begin();
            int toBeAssigned = *it;
            freqServerUsed[toBeAssigned]++;
            maxFreqUsed = max(maxFreqUsed, freqServerUsed[toBeAssigned]);
            availableServers.erase(toBeAssigned);
            busyServers.push({currTime + load[i], toBeAssigned});
        }
        vector<int> res;
        for (int i = 0; i < k; i++) {
            if (freqServerUsed[i] == maxFreqUsed) {
                res.push_back(i);
            }
        }
        return res;
    }
};