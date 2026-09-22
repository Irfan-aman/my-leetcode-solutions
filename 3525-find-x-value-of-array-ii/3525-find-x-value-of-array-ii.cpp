struct Node {
    int count[5] = {0};
    int prod = 0;
};
class SegmentTree {
public:
    int n;
    int k;
    vector<Node> segTree;
    SegmentTree(vector<int>& nums, int k) {
        n = nums.size();
        this->k = k;
        segTree.resize(4 * n, Node());
        build(nums, 0, 0, n - 1);
    }
    void build(vector<int>& nums, int i, int l, int r) {
        if (l == r) {
            for (int x = 0; x < k; x++) {
                segTree[i].count[x] = 0;
            }
            segTree[i].count[nums[l] % k] = 1;
            segTree[i].prod = nums[l] % k;
            return;
        }
        int mid = l + (r - l) / 2;
        build(nums, 2 * i + 1, l, mid);
        build(nums, 2 * i + 2, mid + 1, r);
        segTree[i] = mergeNodes(segTree[2 * i + 1], segTree[2 * i + 2]);
    }
    Node mergeNodes(Node& L, Node& R) {
        Node result;
        result.prod = (L.prod * R.prod) % k;
        for (int x = 0; x < k; x++) {
            result.count[x] = L.count[x];
        }
        for (int x = 0; x < k; x++) {
            int newRem = (L.prod * x) % k;
            result.count[newRem] += R.count[x];
        }
        return result;
    }
    void segTreeUpdate(int i, int l, int r, int idx, int val) {
        if (l == r) {
            for (int x = 0; x < k; x++) {
                segTree[i].count[x] = 0;
            }
            segTree[i].count[val % k] = 1;
            segTree[i].prod = val % k;
            return;
        }
        int mid = l + (r - l) / 2;
        if (idx <= mid) {
            segTreeUpdate(2 * i + 1, l, mid, idx, val);
        } else
            segTreeUpdate(2 * i + 2, mid + 1, r, idx, val);
        segTree[i] = mergeNodes(segTree[2 * i + 1], segTree[2 * i + 2]);
    }
    void update(int idx, int val) { segTreeUpdate(0, 0, n - 1, idx, val); }
    Node segTreeQuery(int start, int end, int i, int l, int r) {
        if (start <= l && end >= r) {
            return segTree[i];
        }
        int mid = l + (r - l) / 2;
        if (end <= mid)
            return segTreeQuery(start, end, 2 * i + 1, l, mid);
        if (start > mid)
            return segTreeQuery(start, end, 2 * i + 2, mid + 1, r);
        Node left = segTreeQuery(start, end, 2 * i + 1, l, mid);
        Node right = segTreeQuery(start, end, 2 * i + 2, mid + 1, r);
        return mergeNodes(left, right);
    }
    Node query(int start, int end) {
        return segTreeQuery(start, end, 0, 0, n - 1);
    }
};
class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k,
                            vector<vector<int>>& queries) {
        int n = nums.size();
        SegmentTree segTree(nums, k);
        vector<int> res;
        for (auto& q : queries) {
            int idx = q[0];
            int val = q[1];
            int start = q[2];
            int x = q[3];
            segTree.update(idx, val);
            Node resultNode = segTree.query(start, n - 1);
            res.push_back(resultNode.count[x]);
        }
        return res;
    }
};