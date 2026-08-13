class Solution {
public:
    struct Node {
        int pref = 0;
        int suff = 0;
        int maxLen = 0;
        char leftChar;
        char rightChar;
    };
    int n;
    vector<Node> segTree;
    Node merge(const Node& L,const Node& R, int leftLen, int rightLen) {
        Node result;
        result.leftChar = L.leftChar;
        result.rightChar = R.rightChar;
        result.pref = L.pref;
        if (L.pref == leftLen && L.rightChar == R.leftChar) {
            result.pref = L.pref + R.pref;
        }
        result.suff = R.suff;
        if (R.suff == rightLen && L.rightChar == R.leftChar) {
            result.suff = L.suff + R.suff;
        }
        result.maxLen = max(L.maxLen, R.maxLen);
        if (L.rightChar == R.leftChar) {
            result.maxLen = max(result.maxLen, L.suff + R.pref);
        }
        return result;
    }
    void update(int i, int l, int r, int pos, char ch) {
        if (l == r) {
            segTree[i] = {1, 1, 1, ch, ch};
            return;
        }
        int mid = l + (r - l) / 2;
        if (pos <= mid) { // Updat Left
            update(2 * i + 1, l, mid, pos, ch);
        } else { // Update right
            update(2 * i + 2, mid + 1, r, pos, ch);
        }
        segTree[i] =
            merge(segTree[2 * i + 1], segTree[2 * i + 2], mid - l + 1, r - mid);
    }

    void buildSegmentTree(int i, int l, int r,const string& s) {
        if (l == r) {
            segTree[i] = {1, 1, 1, s[l], s[r]};
            return;
        }
        int mid = l + (r - l) / 2;
        buildSegmentTree(2 * i + 1, l, mid, s);
        buildSegmentTree(2 * i + 2, mid + 1, r, s);
        segTree[i] =
            merge(segTree[2 * i + 1], segTree[2 * i + 2], mid - l + 1, r - mid);
    }

    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int>& queryIndices) {
        n = s.size();
        segTree.assign(4 * n, Node());
        buildSegmentTree(0, 0, n - 1, s);
        int k = queryIndices.size();
        vector<int> result(k);
        for (int i = 0; i < k; i++) {
            int pos = queryIndices[i];
            char ch = queryCharacters[i];
            update(0, 0, n - 1, pos, ch);
            result[i] = segTree[0].maxLen;
        }
        return result;
    }
};