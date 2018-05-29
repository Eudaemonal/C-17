#include <iostream>
#include <random>
#include <chrono>

template <typename T> class Node;
template <typename T> class Btree;


template <typename T>
class Node{
public:
	Node(T e)
		:elem(e)
	{}
	friend class Btree<T>;
private:
	T elem;
	Node<T>* left=nullptr;
	Node<T>* right=nullptr;
};

template <typename T>
class Btree{
public:
	Btree()=default;
	~Btree(){
		clean(root);
	}


	void insert(T e){
		if(root==nullptr)
			root = new Node<T>(e);
		else{
			insert(e, root);
		}
	}

	bool find(T e){
		find(e, root);
	}



	void traverse(){
		inorder(root);
	}


private:
	void insert(T e, Node<T>* n){
		if(e < n->elem){
			if(n->left==nullptr) n->left = new Node<T>(e);
			else insert(e, n->left);
		}else if(e > n->elem){
			if(n->right==nullptr) n->right = new Node<T>(e);
			else insert(e, n->right);
		}else{
			std::cerr << "Insert same element\n";
		}
	}

	bool find(T e, Node<T>* n){
		if(n==nullptr)
			return false;
		else if(e==n->elem)
			return true;
		else if(e < n->elem)
			find(e, n->left);
		else if(e > n->elem)
			find(e, n->right);
	}


	void clean(Node<T>* n){
		if(n==nullptr)
			return;
		clean(n->left);
		clean(n->right);
		delete n;
	}
	
	void inorder(Node<T>* node){
		if(node==nullptr)
			return;
		inorder(node->left);
		std::cout << node->elem << " ";
		inorder(node->right);
	}




	Node<T>* root=nullptr;
};

int main(int argc, char *argv[]){
	Btree<int> t;
	const int size = 50000;
	auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	std::mt19937 mt(seed);
	std::uniform_int_distribution<int> dist(1, std::numeric_limits<int>::max());

	for(int i=0; i < size; ++i){
		t.insert(dist(mt));
	}

	t.traverse();

	return 0;
}
