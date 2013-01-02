#include <iostream>
#include <string>
using namespace std;

struct node
{
	char data;
	node* left;
	node* right;
};

node* Construct(string preorder, string inorder)
{
	if (preorder.length() == 0)
	{
		return 0;
	}
	node* sub_root = new node();
	char r = preorder[0];
	sub_root->data = r;
	int idx = inorder.find(r);
	string left_in = inorder.substr(0, idx);
	string right_in = inorder.substr(idx+1);
	string left_pre = preorder.substr(1, left_in.length());
	string right_pre = preorder.substr(1+left_pre.length());
	sub_root->left = Construct(left_pre, left_in);
	sub_root->right = Construct(right_pre, right_in);
	return sub_root;
}

void PostOrder(node* root)
{
	if (root == 0)
	{
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	cout << root->data;
}

int main()
{
	string preorder;
	string inorder;
	while (cin >> preorder >> inorder)
	{
		node* root = Construct(preorder, inorder);
		PostOrder(root);
		cout << endl;
	}
	return 0;
}