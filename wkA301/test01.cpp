#include <iostream>
#include <string>

template <typename T> class Node;
template <typename T> class BTree;


template <typename T>
class Node{
public:
	Node(T v)
		:val(v), left(nullptr), right(nullptr)
	{}
	
	friend class BTree<T>;
private:
	T val;
	Node<T> *left, *right;
};

template <typename T>
class BTree{
public:
	BTree()
		:root(nullptr)
	{}

	void insert(const T val){
		root = insert(root, val);		
	}

	Node<T>* find(const T val){
		return find(root, val);
	}
	
	void remove();

	void traversal(const std::string mode){
		if(mode=="preorder"){
			preorder(root);
		}else if(mode == "inorder"){
			inorder(root);
		}else if(mode == "postorder"){
			postorder(root);
		}else{
			std::cerr << "Mode not available\n";
			exit(0);
		}
		std::cout << "\n";
	}

private:

	Node<T>* insert(Node<T>* n, const T val){
		if(n==nullptr){
			return new Node<T>(val);
		}else if(val < n->val){
			n->left = insert(n->left, val);
			return n;
		}else if(val > n->val){
			n->right = insert(n->right, val);
			return n;
		}else{
			std::cerr << "Insert same value\n";
			exit(0);
		}
	}

	Node<T>* find(const Node<T>* n, const T val){
		if(n==nullptr||val == n->val){
			return n;
		}else if(val < n->val){
			return find(n->left, val);
		}else if(val > n->val){
			return find(n->right, val);
		}
	}
	
	void preorder(const Node<T>* n) const{
		if(n==nullptr)
			return;
		std::cout << n->val << " ";
		inorder(n->left);
		inorder(n->right);
	}

	void inorder(const Node<T>* n) const{
		if(n==nullptr)
			return;
		inorder(n->left);
		std::cout << n->val << " ";
		inorder(n->right);
	}

	void postorder(const Node<T>* n) const{
		if(n==nullptr)
			return;
		inorder(n->left);
		inorder(n->right);
		std::cout << n->val << " ";	
	}

private:
	Node<T> *root;
};



int main(int argc, char *argv[]){
	int n, val;
	BTree<int> t;

	std::cin >> n;
	for(int i=0; i < n; ++i){
		std::cin >> val;
		t.insert(val);
	}

	t.traversal("inorder");

	return 0;
}
