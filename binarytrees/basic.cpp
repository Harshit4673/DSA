#include <iostream>
#include <queue>
using namespace std;

class tree
{
public:
    int data;
    tree *left;
    tree *right;

    tree(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

tree *buildtree(tree *root)
{
    cout << "enter data: ";
    int data;
    cin >> data;
    root = new tree(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "enter the value for left of " << data << endl;
    root->left = buildtree(root->left);
    cout << "enter the value for right of " << data << endl;
    root->right = buildtree(root->right);
    return root;
}

void breadthfirsttraverse(tree *root)
{   
    queue<tree*> track;
    track.push(root);
    while(!track.empty()){
        cout<< track.front()->data<< " ";
        if(track.front()->left != NULL){
            track.push(track.front()->left);
        }
        if(track.front()->right != NULL){
            track.push(track.front()->right);
        }
        track.pop();
    }
}

void depthfirsttraverse(tree *root)
{
    if (root == NULL)
        return;
    cout << root->data << " , ";
    depthfirsttraverse(root->left);
    depthfirsttraverse(root->right);
}

int main()
{
// root = buildtree(root);
// dfs_traverse(root);

//         10
//        /  \
//      20    30
//     /     /  \
//   40     50  60

    tree* root = new tree(10);
    root->left = new tree(20);
    root->right = new tree(30);
    root->left->left = new tree(40);
    root->right->left = new tree(50);
    root->right->right = new tree(60);

    breadthfirsttraverse(root);
}