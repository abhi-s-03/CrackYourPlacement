/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
class Solution{
  public:
    bool checkDeadEnd(Node *node, int min_val, int max_val) {
        if (!node) {
            return false;
        }

        if (min_val == max_val) {
            return true;
        }

        return checkDeadEnd(node->left, min_val, node->data - 1) ||
               checkDeadEnd(node->right, node->data + 1, max_val);
    }
    bool isDeadEnd(Node *root) {
        return checkDeadEnd(root, 1, 10001);
    }
};