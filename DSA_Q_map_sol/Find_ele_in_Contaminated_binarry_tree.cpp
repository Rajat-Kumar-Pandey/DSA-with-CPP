#include <iostream>
#include <unordered_set>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class FindElements {
private:
    unordered_set<int> values;

    void recover(TreeNode* node,int val){
        if(!node) return;

        node->val = val;
        values.insert(val);
        recover(node->left, 2*val+1);
        recover(node->right, 2*val+2);
    }



public:
    FindElements(TreeNode* root) {
        if(root){
            recover(root,0);
        }

    }

    bool find(int target) {
        return values.find(target)!=values.end();
    }
};

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(-1);
    root->left = new TreeNode(-1);
    root->right = new TreeNode(-1);

    FindElements findElements(root);
    cout << findElements.find(1) << endl; // Output: 1 (true)
    cout << findElements.find(2) << endl; // Output: 1 (true)
    cout << findElements.find(3) << endl; // Output: 0 (false)

    return 0;
}