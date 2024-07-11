/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    void BTtoStr(TreeNode* root, string &ser){
        if(!root){
            ser += "N "; //for NULL
            return;
        }

        //build preorder string
        ser += to_string(root->val) + ' ';
        BTtoStr(root->left, ser);
        BTtoStr(root->right, ser);

    }
    string serialize(TreeNode* root) {
        string ser = "";
        BTtoStr(root, ser);
        return ser;
    }

    // Decodes your encoded data to tree.

    TreeNode* StrToBT(string &data, int &i){
        if(data[i] == 'N'){
            i+=2; // skip space character 
            return nullptr;
        }

        string tmp = ""; // to store the number
        while(data[i] != ' ') tmp += data[i++]; // get number
        TreeNode* node = new TreeNode(stoi(tmp));
        i++; //skip the space character
        node->left = StrToBT(data, i); //recurse to build tree
        node->right = StrToBT(data, i);

        return node;

    }
    TreeNode* deserialize(string data) {
        int i = 0;
        return StrToBT(data, i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));