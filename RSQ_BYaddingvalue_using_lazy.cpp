
#include <bits/stdc++.h>
using namespace std;
#define MAX 100010
int tree[MAX], lazy[MAX];
vector<int> ar;
void showSegTree(int n)
{
    int i, j, h = ceil(log2(n));
    cout << "Segment Tree:" << endl;
    for (i = 0; i <= h; ++i)
    {
        for (j = 0; j < pow(2, i); ++j)
            cout << tree[int(pow(2, i) - 1 + j)] << ' ';
        cout << endl;
    }
    cout << "Lazy Tree:" << endl;
    for (i = 0; i <= h; ++i)
    {
        for (j = 0; j < pow(2, i); ++j)
            cout << lazy[int(pow(2, i) - 1 + j)] << ' ';
        cout << endl;
    }
}
int constSegTree(int strt, int end, int idx) // build
{
    // Initialize all lazy tree nodes with 0
    lazy[idx] = 0;

    // Saves tree[idx] = ar[strt] and then returns tree[idx]
    if (strt == end)
        return tree[idx] = ar[strt];

    int mid = (strt + end) / 2;
    return tree[idx] = constSegTree(strt, mid, 2 * idx + 1) +
                       constSegTree(mid + 1, end, 2 * idx + 2);
}
int getSum(int strt, int end, int l, int r, int idx) // query
{
    // If there's pending update, update the node first
    if (lazy[idx] != 0)
    {
        // Add the pending update to the current node
        // [l..r] contains l-r+1 nodes
        tree[idx] += (r - l + 1) * lazy[idx];

        // If the node has children, postpone the updates
        // to the children by adding to the their lazy nodes
        if (l != r)
        {
            lazy[2 * idx + 1] += lazy[idx];
            lazy[2 * idx + 2] += lazy[idx];
        }

        // Reset the lazy node of current node
        lazy[idx] = 0;
    }

    // If completly outside the range, don't care
    if (end < l || r < strt || l > r)
        return 0;

    // If node is entirely within the range, return the node value
    if (strt <= l && r <= end)
        return tree[idx];

    // Enter its children and process further
    int mid = (l + r) / 2;
    return getSum(strt, end, l, mid, 2 * idx + 1) +
           getSum(strt, end, mid + 1, r, 2 * idx + 2);
}
int getSum(int n, int strt, int end)
{
    return getSum(strt, end, 0, n - 1, 0);
}

void updtSegTree(int strt, int end, int val, int l, int r, int idx) // idx=node// (2,4,2,0,n-1,0)
{

    if (lazy[idx] != 0)
    {
        tree[idx] += (r - l + 1) * lazy[idx];
        if (l != r)
        {
            lazy[2 * idx + 1] += lazy[idx];
            lazy[2 * idx + 2] += lazy[idx];
        }
        lazy[idx] = 0;
    }
    if (end < l || r < strt || l > r)
        return;
    if (strt <= l && r <= end)
    {
        tree[idx] += (r - l + 1) * val;
        if (l != r)
        {
            lazy[2 * idx + 1] += val;
            lazy[2 * idx + 2] += val;
        }
    }
    else
    {
        int mid = (l + r) / 2;
        updtSegTree(strt, end, val, l, mid, 2 * idx + 1);
        updtSegTree(strt, end, val, mid + 1, r, 2 * idx + 2);
        tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
    }
}
void updtSegTree(int n, int strt, int end, int val)
{
    updtSegTree(strt, end, val, 0, n - 1, 0);
}

int main()
{
    int n = 7;
    ar = {18, 17, 1, 19, 15, 11, 20};

    constSegTree(0, n - 1, 0);

    cout << "n = 7, ar = {18, 17, 1, 19, 15, 11, 20}" << endl;
    showSegTree(n);

    updtSegTree(n, 0, 4, 2); // update(0,4,2,0,n-1)(st,ed,val,l,r,node)
    cout << "after update" << endl;
    cout << "\nupdtSegTree(n, 0, 4, 2):" << endl;
    showSegTree(n);

    cout << "\nSum of ar[1..4] = " << getSum(n, 1, 4) << endl; // query(1,4,0,n-1,0)
    showSegTree(n);

    return 0;
}