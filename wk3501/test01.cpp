#include <iostream>
#include <string>

template <typename T>
class BTree{
public:
	struct Node{
		Node(T e): 
			elem{e}, left{nullptr}, right{nullptr}
		{}

		Node* left;
		Node* right;
		T elem;
	};


	BTree()=default;

	
	Node* search(T e){
		return search(e, root);	
	}


	void insert(T e){
		if(root == nullptr){
			root = new Node(e);
		}
		else{
			add(e, root);
		}
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
	}


private:
	Node* search(T e, Node* n){
		if(e < n->elem){
			if(isNode(n->left)){
				return search(e, n->left);
			}
			else{
				return nullptr;
			}
		}
		else if(e > n->elem){
			if(isNode(n->right)){
				return search(e, n->right);
			}
			else{
				return nullptr;
			}
		}
		else if(e == n->elem){
			return n;
		}
	}

	void insert(T e, Node* n){
		Node* curr = n;
		if(e < curr->elem){
			if(isNode(curr->left)){
				curr = curr->left;
				insert(e, curr);
			}
			else{
				curr->left = new Node(e);
			}
		}
		else if(e > curr->elem){
			if(isNode(curr->right)){
				curr = curr->right;
				insert(e, curr);
			}
			else{
				curr->right = new Node(e);
			}
		}
	}
	
	bool isNode(Node *n){
		if(n==nullptr)
			return false;
		return true;
	}

	void pre_order(Node* n){
		if(isNode(n)){
			std::cout << n->elem << " ";
			pre_order(n->left);
			pre_order(n->right);
		}
	}

	void in_order(Node* n){
		if(isNode(n)){
			pre_order(n->left);
			std::cout << n->elem << " ";
			pre_order(n->right);
		}
	}

	void post_order(Node* n){
		if(isNode(n)){
			pre_order(n->left);
			pre_order(n->right);
			std::cout << n->elem << " ";
		}
	}

	

	

	Node* root=nullptr;
	
};


int main(){
	BTree<int> t;
	t.insert(5);
	t.insert(2);
	t.insert(7);
	t.insert(1);
	t.insert(3);
	
	
	t.print(2);
}
