class Solution {
public:
    int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days(string date) {
        int monthDate = stoi(date.substr(0, 2));
        int dayDate = stoi(date.substr(3));
        int totalDays = dayDate;
        for (int i = 0; i < monthDate - 1; i++) {
            totalDays += month[i];
        }
        return totalDays;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        return max(0,min(days(leaveAlice), days(leaveBob)) -
               max(days(arriveAlice), days(arriveBob)) + 1);
    }
};