// Flatten BST to sorted list

/* Node of the binary search tree
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    Node* flattenBST(Node *root) {
        if(!root) return NULL;
        
        Node* Lhead = flattenBST(root->left);
        Node* Rhead = flattenBST(root->right);
        
        // left subtree's head link to root
        if(!Lhead){
            Lhead = root;
        }
        else{
            Node* temp = Lhead;
            while(temp && temp->right){
                temp = temp->right;
            }
            temp->right = root;
        }
        root->left = NULL;
        root->right = Rhead;
        
        return Lhead;
    }
};