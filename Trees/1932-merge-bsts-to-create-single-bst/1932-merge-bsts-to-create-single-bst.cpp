/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     //Time Complexity = O(n) => cause visiting n nodes
    //Space Complexity = O(n) => cause storing n nodes in the unordered map 
    struct LeafInfo {
        long long minVal, maxVal; // valid BST range for this leaf
        TreeNode* parent;
        int side; // 0 = left child, 1 = right child
    };

    TreeNode* canMerge(vector<TreeNode*>& trees) {
        unordered_set<int> leaves;
        unordered_map<int, TreeNode*> rootMap;

        // Store all roots and collect all leaf values
        for (TreeNode* tree : trees) {
            rootMap[tree->val] = tree;

            if (tree->left)
                leaves.insert(tree->left->val);

            if (tree->right)
                leaves.insert(tree->right->val);
        }

        // Find the only root that never appears as a leaf
        TreeNode* root = NULL;
        for (TreeNode* tree : trees) {
            if (!leaves.count(tree->val)) {
                root = tree;
                break;
            }
        }

        if (!root)
            return NULL;

        unordered_map<int, LeafInfo> leafMap;

        // Initialize current leaves of the overall root
        if (root->left)
            leafMap[root->left->val] = {LLONG_MIN, root->val, root, 0};

        if (root->right)
            leafMap[root->right->val] = {root->val, LLONG_MAX, root, 1};

        rootMap.erase(root->val);

        // Keep merging until all trees are used
        while (!rootMap.empty()) {
            bool merged = false;

            vector<int> currentLeaves;
            for (auto& [leafVal, _] : leafMap)
                currentLeaves.push_back(leafVal);

            for (int leafVal : currentLeaves) {
                if (!rootMap.count(leafVal))
                    continue;

                LeafInfo info = leafMap[leafVal];
                leafMap.erase(leafVal);

                long long minVal = info.minVal;
                long long maxVal = info.maxVal;
                TreeNode* parent = info.parent;
                int side = info.side;

                TreeNode* subtree = rootMap[leafVal];

                // Add left child if it satisfies BST constraints
                if (subtree->left) {
                    int val = subtree->left->val;

                    if (minVal < val && val < maxVal &&
                        !leafMap.count(val)) {
                        leafMap[val] = {minVal, subtree->val, subtree, 0};
                    } else {
                        return NULL;
                    }
                }

                // Add right child if it satisfies BST constraints
                if (subtree->right) {
                    int val = subtree->right->val;

                    if (minVal < val && val < maxVal &&
                        !leafMap.count(val)) {
                        leafMap[val] = {subtree->val, maxVal, subtree, 1};
                    } else {
                        return NULL;
                    }
                }

                // Attach the subtree to its parent
                if (side == 0)
                    parent->left = subtree;
                else
                    parent->right = subtree;

                rootMap.erase(subtree->val);
                merged = true;
                break;
            }

            // No valid merge found
            if (!merged)
                return NULL;
        }

        return root; //very important to return 
    }
};