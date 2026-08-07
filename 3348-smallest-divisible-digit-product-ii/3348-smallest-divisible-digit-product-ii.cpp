class Solution {
public:
    typedef long long ll;
    string freeSlotsFiller(ll required, int length) {
        string str;
        for (int i = 9; i >= 2; i--) {
            while (required % i == 0) {
                str.push_back(i + '0');
                required /= i;
            }
        }
        while (str.size() < length) {
            str.push_back('1');
        }
        reverse(str.begin(), str.end());
        return str;
    }
    string smallestNumber(string num, long long t) {
        int n = num.size();
        ll temp = t;
        for (int primeFact : {2, 3, 5, 7}) {
            while (temp % primeFact == 0) {
                temp /= primeFact;
            }
        }
        if (temp > 1)
            return "-1";
        vector<ll> requiredFact(n + 1, t);
        for (int i = 0; i < n; i++) {
            int currDig = num[i] - '0';
            if (currDig == 0)
                break;
            requiredFact[i + 1] =
                requiredFact[i] / gcd((ll)currDig, requiredFact[i]);
        }
        if (requiredFact[n] == 1)
            return num;
        int zeroIdx = num.find('0');
        int startIdx = n - 1;
        if (zeroIdx != -1)
            startIdx = zeroIdx;

        for (int i = startIdx; i >= 0; i--) {
            ll currRequired = requiredFact[i];
            int length = n - i - 1;
            for (int dig = (num[i] - '0') + 1; dig <= 9; dig++) {
                ll newRequired = currRequired / gcd(currRequired, dig);
                string validLastNum = freeSlotsFiller(newRequired, length);
                if (validLastNum.size() == length) {
                    return num.substr(0, i) + char(dig + '0') + validLastNum;
                }
            }
        }
        return freeSlotsFiller(t, n + 1);
    }
};