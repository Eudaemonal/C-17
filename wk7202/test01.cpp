#include <iostream>
#include <vector>

struct Node{
	int key;
	struct Node *left, *right;

	Node(int k): key(k), left(nullptr), right(nullptr) {};
};

bool findPath(Node* root, std::vector<int> &path, int k){
	if(root ==nullptr)
		return false;
	path.push_back(root->key);
	if(root->key == k)
		return true;

	if((root->left && findPath(root->left, path, k))||
		(root->right && findPath(root->right, path, k)))
	return true;

	path.pop_back();
	return false;
}

int findLCA1(Node *root, int n1, int n2){
	std::vector<int> path1, path2;

	if(!findPath(root, path1, n1)||!findPath(root, path2, n2))
		return -1;
	int i;
	for(i=0; i<path1.size() && 1 < path2.size(); ++i)
		if(path1[i] != path2[i])
			break;
	return path1[i-1];
}


Node* findLCA2(Node* root, int n1, int n2){
	if(root==nullptr)
		return NULL;
	if(root->key == n1||root->key == n2)
		return root;
	Node* left_lca = findLCA2(root->left, n1, n2);
	Node* right_lca = findLCA2(root->right, n1, n2);

	if(left_lca && right_lca)
		return root;
	return (left_lca!=nullptr)?left_lca : right_lca;
}

int main(int argc, char *argv[]){
	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

	std::cout << findLCA1(root, 4, 5) << "\n";

	Node* curr = findLCA2(root, 4, 5);
	std::cout << curr->key << "\n";

	return 0;
}
