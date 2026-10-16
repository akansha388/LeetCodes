
class Solution {
public:
    static const int MOD = 1e9 + 7;

    struct Node {
        long long sum = 0;
        long long sq = 0;
        long long lazy = 0;
    };

    vector<Node> tree;
    int n;

    void push(int node, int l, int r) {
        if (tree[node].lazy == 0) return;

        long long val = tree[node].lazy;
        long long len = r - l + 1;

        tree[node].sq = (tree[node].sq
            + 2 * val % MOD * tree[node].sum % MOD
            + val * val % MOD * len % MOD) % MOD;

        tree[node].sum = (tree[node].sum + val * len) % MOD;

        if (l != r) {
            tree[node * 2].lazy =
                (tree[node * 2].lazy + val) % MOD;
            tree[node * 2 + 1].lazy =
                (tree[node * 2 + 1].lazy + val) % MOD;
        }

        tree[node].lazy = 0;
    }

    void update(int node, int l, int r, int ql, int qr) {
        push(node, l, r);

        if (r < ql || l > qr) return;

        if (ql <= l && r <= qr) {
            tree[node].lazy++;
            push(node, l, r);
            return;
        }

        int mid = (l + r) / 2;
        update(node * 2, l, mid, ql, qr);
        update(node * 2 + 1, mid + 1, r, ql, qr);

        tree[node].sum =
            (tree[node * 2].sum + tree[node * 2 + 1].sum) % MOD;

        tree[node].sq =
            (tree[node * 2].sq + tree[node * 2 + 1].sq) % MOD;
    }

    int sumCounts(vector<int>& nums) {
        n = nums.size();
        tree.assign(4 * n, Node());

        vector<int> last(100001, -1);
        long long res = 0;

        for (int i = 0; i < n; i++) {
            int prev = last[nums[i]];

            update(1, 0, n - 1, prev + 1, i);
            last[nums[i]] = i;

            res = (res + tree[1].sq) % MOD;
        }

        return res;
    }
};
