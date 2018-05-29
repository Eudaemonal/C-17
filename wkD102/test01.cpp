#include <iostream>
#include <string>
#include <vector>

template <typename T> class Node;
template <typename T> class BTree;


template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T> &v){
	for(size_t i=0; i < v.size(); ++i){
			os << v[i] << " ";
	}
	os << "\n";
	return os;
}


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


	void buildTree(std::vector<T> inorder, std::vector<T> preorder){
		root = buildTree(inorder, preorder, 0, inorder.size()-1);
	}

private:

	Node<T>* buildTree(std::vector<T> inorder, std::vector<T> preorder, int start, int end){
		static int preIndex = 0;
		if(start > end)
			return nullptr;
		Node<T> *tnode = new Node<T>(preorder[preIndex++]);

		if(start==end)
			return tnode;

		int inIndex;
		for(int i=0; i <= end; ++i){
			if(inorder[i]==tnode->val){
				inIndex = i;
				break;
			}
		}
		tnode->left = buildTree(inorder, preorder, start, inIndex-1);
		tnode->right = buildTree(inorder, preorder, inIndex+1, end);

		return tnode;
	}


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
	int n;
	std::cin >> n;
	std::vector<char> inorder(n);
	std::vector<char> preorder(n);
	for(int i=0; i < n; ++i){
		std::cin >> inorder[i];	
	}
	for(int i=0; i < n; ++i){
		std::cin >> preorder[i];
	}

	std::cout << inorder;
	std::cout << preorder;
	
	BTree<char> t;
	t.buildTree(inorder, preorder);

	t.traversal("inorder");
	t.traversal("preorder");
	
	return 0;
}

