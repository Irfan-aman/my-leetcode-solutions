class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int a=stoi(startTime.substr(0,2));
        int b=stoi(startTime.substr(3,2));
        int c=stoi(startTime.substr(6,2));
        int x=stoi(endTime.substr(0,2));
        int y=stoi(endTime.substr(3,2));
        int z=stoi(endTime.substr(6,2));
        return (x-a)*3600+(y-b)*60+(z-c);
    }
};