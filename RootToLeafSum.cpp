#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 100000000007
#define gcd(a,b) __gcd(a,b)
#define maxv INT_MAX
#define minv INT_MIN

struct TreeNode
{	
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution{
public:
	int dfs(TreeNode* root, int currentSum){
		if(root == nullptr)return 0;
		currentSum = currentSum *10 + root->val;

		if(!root->left  && !root->right){
			return currentSum;
		}

		int leftSum = dfs(root->left, currentSum);
		int 

	}
	int sumNumbers(TreeNode* root){
		return dfs(root, 0);
	}
}

TreeNode* buildTree() {
    int val;
    cin >> val;

    if (val == -1) return nullptr;

    TreeNode* root = new TreeNode(val);
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        int leftVal, rightVal;
        cin >> leftVal >> rightVal;

        if (leftVal != -1) {
            current->left = new TreeNode(leftVal);
            q.push(current->left);
        }

        if (rightVal != -1) {
            current->right = new TreeNode(rightVal);
            q.push(current->right);
        }
    }

    return root;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Insert your code here...
    TreeNode* root = buildTree();

    Solution solution;
    int result = solution.sumNumbers(root);
    cout << "Sum of root-to-leaf numbers: " << result << endl;

    return 0;
}
