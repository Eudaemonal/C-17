#include <iostream>
#include <string>

template <typename T>
inline int max(T x, T y){ return (x>y)?x:y; }

template <typename T>
class AVLTree{
public:
	struct Node{
		Node(T e): 
			elem{e}, left{nullptr}, right{nullptr}, height{0}
		{}

		Node* left;
		Node* right;
		T elem;
		int height;
	};


	AVLTree()=default;

	
	Node* search(const T e){
		return search(e, root);	
	}

	void insert(T e){
		root = insert(e, root);	
	}
	// Print tree in modes
	void print(int mode){
		switch(mode){
			case 0: 
				pre_order(root);
				break;
			case 1:
				in_order(root);
				break;
			case 2:
				post_order(root);
				break;
			default:
				std::cout <<
					"Print BTree options: \n" <<
					"0 - preorder\n" << 
					"1 - inorder\n" << 
					"2 - postorder\n";
				break;
		}
		std::cout << "\n";
	}


private:
	Node* search(const T e, Node* n) const{
		if(n!=nullptr){
			if(e == n->elem){
				return n;
			}
			else if(e< n->elem){
				return search(e, n->left);
			}
			else{
				return search(e, n->right);
			}
		}
		else{
			return nullptr;
		}
	}

	Node* insert(const T e, Node* n){
		if(n == nullptr){
			n = new Node(e);
		}
		else if(e < n->elem){
			n->left = insert(e, n->left);
			if(height(n->left) - height(n->right) == 2){
				if(e < n->left->elem){
					n = rotateRight(n);
				} else{
					n->left = rotateLeft(n->left);
					n = rotateRight(n);
				}
			}
		}
		else if(e > n->elem){
			n->right = insert(e, n->right);
			if(height(n->right) - height(n->left) == 2){
				if(e > n->right->elem){
					n = rotateLeft(n);
				}else{
					n->right = rotateRight(n->right);
					n = rotateLeft(n);
				}
			}
		}
		n->height = max(height(n->left), height(n->right))+1;
		return n;
	}


	Node* rotateLeft(Node* &t){
		Node* u = t->right;
		t->right = u->left;
		u->left = t;
		t->height = max(height(t->left), height(t->right))+1;
		u->height = max(height(t->right), t->height)+1 ;
		return u;
	}

	Node* rotateRight(Node* &t){
		Node* u = t->left;
		t->left = u->right;
		u->right = t;
		t->height = max(height(t->left), height(t->right))+1;
		u->height = max(height(u->left), t->height)+1;
		return u;
	}

	int height(Node* t){
		return (t==nullptr? -1: t->height);
	}

	
	bool isNode(const Node *n) const {
		if(n==nullptr)
			return false;
		return true;
	}

	void pre_order(const Node* n) const {
		if(isNode(n)){
			std::cout << n->elem << " ";
			pre_order(n->left);
			pre_order(n->right);
		}
	}

	void in_order(const Node* n) const {
		if(isNode(n)){
			pre_order(n->left);
			std::cout << n->elem << " ";
			pre_order(n->right);
		}
	}

	void post_order(const Node* n) const {
		if(isNode(n)){
			pre_order(n->left);
			pre_order(n->right);
			std::cout << n->elem << " ";
		}
	}


	Node* root=nullptr;
	
};


int main(){
	AVLTree<int> t;
	t.insert(5);
	t.insert(2);
	t.insert(7);
	t.insert(1);
	t.insert(3);
	
	
	t.print(1);
	
	int key = 3;
	if(t.search(key)!=nullptr){
		std::cout << key << " exist!\n";
	}
	else{
		std::cout << key << " not exist!\n";
	}
}

