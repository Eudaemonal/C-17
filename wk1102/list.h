#include <iostream>
#include <memory>




class List{
public:
	/*class Node*/
	class Node{
	public:
		Node()=default;
		Node(int val): data_{val}, next_{nullptr} {}
		~Node(){}
		int get(){
			return data_;
		}
		Node* next(){
			return next_;
		}
		int data_;
		Node* next_;
	};
	/*End class Node*/

	List():num_{0}, head_{nullptr} {}
	
	void add_node(int val){
		if(num_==0){
			head_ = new Node(val);
			num_++;
		}
		else{
			Node *curr = head_;
			while(curr->next_!=nullptr){
				curr = curr->next_;
			}
			curr->next_ = new Node(val);
			num_++;
		}
	}


	friend std::ostream& operator<<(std::ostream& os, List &l);

private:
	unsigned int num_;
	Node* head_;
};

std::ostream& operator<<(std::ostream& os, List &l){
	List::Node *curr = l.head_;
	os<< curr->get();
	while(curr->next_!=nullptr){
		curr = curr->next();
		os<< ", " << curr->get();
	}
	os << "\n";
	return os;

}




