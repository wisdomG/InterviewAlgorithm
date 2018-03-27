#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

void pre_order(TreeNode *root) {
    stack<TreeNode*> sta;
    TreeNode* cur = root;
    while (cur != nullptr || !sta.empty()) {
        cout << cur -> val << endl;
        sta.push(cur);
        cur = cur->left;
        while (cur == nullptr && !sta.empty()) {
            cur = sta.top();
            sta.pop();
            cur = cur -> right;
        }
    }
}

void in_order(TreeNode* root) {
    stack<TreeNode*> sta;
    TreeNode* cur = root;
    while (cur != nullptr || !sta.empty()) {
        sta.push(cur);
        cur = cur -> left;
        while (cur == nullptr && !sta.empty()) {
            cur = sta.top();
            cout << cur -> val << endl;
            sta.pop();
            cur = cur -> right;
        }
    }
}

int main() {

}

