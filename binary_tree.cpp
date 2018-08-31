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

void pre_order2(TreeNode* root) {
    stack<TreeNode*> sta;
    TreeNode* cur = root;
    while (cur != nullptr && !sta.empty()) {
        if (cur != nullptr) {
            sta.push(cur);
            cout << cur -> val << endl;
            cur = cur -> left;
        } else {
            TreeNode* top = sta.top();
            cur = top -> right; 
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

void in_order2(TreeNode* root) {
    stack<TreeNode*> sta;
    TreeNode* cur = root;
    while (cur != nullptr && !sta.empty()) {
        if (cur != nullptr) {
            sta.push(cur);
            cur = cur -> left;
        } else {
            TreeNode* top = sta.top();
            cout << cur -> val << endl;
            cur = top -> right; 
        }
    }
}

void post_order(TreeNode* root) {
    stack<TreeNode*> sta;
    TreeNode* cur = root;
    TreeNode* pre = nullptr;
    while (cur != nullptr && !sta.empty()) {
        if (cur != nullptr) {
            sta.push(cur);
            cur = cur -> left;
        } else {
            TreeNode* top = sta.top();
            if (top -> right != nullptr && pre != top -> right) {
                cur = top -> right;
            } else {
                cout << top -> val << endl;
                pre = cur;
                sta.pop();
            }
        }
    }
}

int main() {

    return 0;
}

