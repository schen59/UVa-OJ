#include <iostream>
#include <string>
using namespace std;

struct Node
{
	char data;
	Node* first;
	Node* second;
	Node* third;
	Node* fourth;
	Node()
	{
		data   = 'e';
		first  = 0;
		second = 0;
		third  = 0;
		fourth = 0;
	}
};

Node* CreateTree(string& s)
{
	if (s.compare("") == 0)
	{
		return 0;
	}
	Node* node = new Node();
	node->data = s[0];
	//cout << s << endl;
	s = s.substr(1);
	if (node->data == 'p')
	{
		node->first  = CreateTree(s);
		node->second = CreateTree(s);
		node->third  = CreateTree(s);
		node->fourth = CreateTree(s);
	}
	else 
	{
		node->first  = 0;
		node->second = 0;
		node->third  = 0;
		node->fourth = 0;
	}
    return node;
}

Node* Combine(Node* root_1, Node* root_2)
{
	Node* root = new Node();
	if (root_1->data=='f' || root_2->data=='f')
	{
		root->data   = 'f';
		root->first  = 0;
		root->second = 0;
		root->third  = 0;
		root->fourth = 0;
	}
	else if (root_1->data == 'e')
	{
		root->data   = root_2->data;
		root->first  = root_2->first;
		root->second = root_2->second;
		root->third  = root_2->third;
		root->fourth = root_2->fourth;
	}
	else if (root_2->data == 'e')
	{
		root->data   = root_1->data;
		root->first  = root_1->first;
		root->second = root_1->second;
		root->third  = root_1->third;
		root->fourth = root_1->fourth;
	}
	else
	{
		root->data   = 'p';
		root->first  = Combine(root_1->first, root_2->first);
		root->second = Combine(root_1->second, root_2->second);
		root->third  = Combine(root_1->third, root_2->third);
		root->fourth = Combine(root_1->fourth, root_2->fourth);
	}
	return root;
}

void PreOrder(const Node* root)
{
	if (root == 0)
	{
		return;
	}
	cout << root->data;
	PreOrder(root->first);
	PreOrder(root->second);
	PreOrder(root->third);
	PreOrder(root->fourth);
}

int Calculate(Node* root, int size)
{
	if (root==0 || root->data=='e')
	{
		return 0;
	}
	if (root->data == 'f')
	{
		return size;
	}
    return Calculate(root->first, size/4) + Calculate(root->second, size/4) + \
		Calculate(root->third, size/4) + Calculate(root->fourth, size/4);
}

int main()
{
    string s_1, s_2;
	int case_num = 0;
	cin >> case_num;
	for (int i=0; i<case_num; i++)
	{
		cin >> s_1 >> s_2;
		Node* root_1 = CreateTree(s_1);
		Node* root_2 = CreateTree(s_2);
		Node* root   = Combine(root_1, root_2);
		cout << "There are " << Calculate(root, 1024) << " black pixels." << endl;
	}
	return 0;
}