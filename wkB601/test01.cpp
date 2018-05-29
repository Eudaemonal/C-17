#include <iostream>

template <class T> class Node;
template <class T> class List;

template <class T>
class Node{
public:
	Node(T v)
		:val(v), next(nullptr)
	{}

	friend class List<T>;
	template <class U>
	friend std::ostream& operator<<(std::ostream& os, const List<U>& l);

	template <class U>
	friend void reverse(List<U>& l);

private:
	T val;
	Node<T> *next;
};

template <class T>
class List{
public:
	List()
		:head(nullptr)
	{}

	void insert(T v){
		if(head == nullptr){
			Node<T> *n = new Node<T>(v);
			head = n;
		}else{
			Node<T> *curr = head;
			while(curr->next)
				curr = curr->next;
			curr->next = new Node<T>(v);
		}
	}


	template <class U>
	friend std::ostream& operator<<(std::ostream& os, const List<U>& l);
	
	template <class U>
	friend void reverse(List<U>& l);

private:
	Node<T> *head;
};

template <class T>
std::ostream& operator<<(std::ostream& os, const List<T>& l){
	Node<T> *curr = l.head;
	while(curr){
		os << curr->val << " ";
		curr = curr->next;
	}
	os << "\n";
	return os;
}

template <class T>
void reverse(List<T>& l){
	Node<T> *curr = l.head;
	Node<T> *prev = nullptr;
	Node<T> *next = nullptr;
	while(curr!=nullptr){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	l.head = prev;
}



int main(int argc, char *argv[]){
	List<int> l;

	int n, e;
	std::cin >> n;
	for(int i = 0; i < n; ++i){
		std::cin >> e;
		l.insert(e);
	}

	std::cout << l;
	reverse(l);
	std::cout << l;


	return 0;
}


