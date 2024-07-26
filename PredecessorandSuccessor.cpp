class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    { 
        Node* prev;
        while(root){
            if(root->key==key){
                if (root->left) {
                    Node* temp = root->left;
                    while (temp->right)
                        temp = temp->right;
                    pre = temp;
                }

                if (root->right) {
                    Node* temp = root->right;
                    while (temp->left)
                        temp = temp->left;
                    suc = temp;
                }
                return;
            }
            else if(root->key<key){
                pre = root;
                root=root->right;
            } 
            else{
                suc = root;
                root=root->left;
            } 
        }
    }
};