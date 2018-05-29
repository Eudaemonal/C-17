#include <iostream>

class Node{
private:
	int key;
	Node* next;

	friend class LinkedList;

public:
	Node(int k):key(k), next(nullptr){}

};

class LinkedList{
private:
	Node *head;

public:
	LinkedList():head(nullptr){}
	void insert(int k){
		Node *n = new Node(k);
		if(head==nullptr)
			head = n;
		else{
			Node *curr = head;
			while(curr->next){
				curr = curr->next;
			}
			curr->next = n;
		}
	}


	bool find(int k){
		Node *curr = head;
		while(curr){
			if(curr->key==k)
				return true;
			curr = curr->next;
		}
		return false;
	}
	
	void print(){
		Node *curr = head;
		while(curr->next){
			std::cout << curr->key << ", ";
			curr = curr->next;
		}
		std::cout << curr->key <<"\n";
	}


};



int main(int argc, char *argv[]){
	LinkedList l;
	l.insert(2);
	l.insert(3);
	l.insert(4);
	l.insert(5);
	l.insert(6);

	std::cout << l.find(6) << "\n";
	std::cout << l.find(7) << "\n";

	
	l.print();
	
	return 0;
}
