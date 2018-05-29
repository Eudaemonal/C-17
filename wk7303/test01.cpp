#include <iostream>


struct Node{
	int key;
	Node* next;

	Node(int k) : key(k), next(nullptr) {}
};


class List{
public:
	List() : head(nullptr) {}
	
	void insert(int k){
		if(head==nullptr)
			head = new Node(k);
		else{
			Node* curr = head;
			while(curr->next){
				curr= curr->next;
			}
			curr->next = new Node(k);
		}
	}

	void pairSwap(){
		Node* curr = head;
		int tmp;
		while(curr!=nullptr && curr->next!=nullptr){
			tmp = curr->key;
			curr->key = curr->next->key;
			curr->next->key = tmp;
			curr = curr->next->next;
		}
	}

	
	void print(){
		Node* curr = head;
		while(curr){
			std::cout << curr->key << " ";
			curr=  curr->next;
		}
		std::cout << "\n";
	}

private:
	Node* head;
};

int main(int argc, char *argv[]){
	List l;
	l.insert(1);
	l.insert(2);
	l.insert(3);
	l.insert(4);
	l.insert(5);
	l.insert(6);
	
	l.pairSwap();

	l.print();
	
	return 0;
}

