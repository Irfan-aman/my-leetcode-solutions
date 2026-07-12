class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int s=stoi(startTime.substr(0,2))*3600+stoi(startTime.substr(3,2))*60+stoi(startTime.substr(6,2));
        int e=stoi(endTime.substr(0,2))*3600+stoi(endTime.substr(3,2))*60+stoi(endTime.substr(6,2));
        return e-s;
    }
};