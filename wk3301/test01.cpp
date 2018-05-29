#include <iostream>
#include <string>

class RC{
private:
	int count;
public:
	void AddRef(){
		count++;
	}

	int Release(){
		return --count;
	}
};




template <typename T>
class SP{
private:
	T* pData;
	RC* reference;
public:
	SP():pData(0), reference(0){
		reference = new RC();
		reference->AddRef();
	}

	SP(T* pValue) : pData(pValue), reference(0){
		reference = new RC();
		reference->AddRef();
	}
	~SP(){
		std::cout << "SP destruct\n";
		if(reference->Release()==0){
			delete pData;
			delete reference;
		}
	}


	T& operator* (){
		return *pData;
	}

	T* operator->(){
		return pData;
	}

	SP<T>& operator=(const SP<T>& sp){
		if(this!=&sp){
			if(reference->Release()==0){
				delete pData;
				delete reference;
			}
			pData = sp.pData;
			reference = sp.reference;
			reference->AddRef();
		}
		return *this;
	}

};



class Person
{
    int age;
    std::string pName;

    public:
        Person(): pName(0),age(0)
        {
        }
        Person(std::string pName, int age): pName(pName), age(age)
        {
        }
        ~Person()
        {
        }

        void Display()
        {
		std::cout << "Name = " << pName << " Age = " << age << "\n";
        }
};


int main(int argc, char *argv[]){
	SP<Person> p(new Person("Scott", 25));
	p->Display();
	SP<Person> q = p;
	q->Display();
	
	p->Display();
	return 0;
}
