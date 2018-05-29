#include <iostream>
#include <sstream>
#include <memory>

class StreamingException : public std::runtime_error{
public:
	StreamingException():
		std::runtime_error(""),
		s_(std::auto_ptr<std::stringstream>(new std::stringstream()))
	{}
	~StreamingException() throw(){}

	template <typename T>
	StreamingException & operator << (const T & t){
		(*s_) << t;
		return *this;
	}

	virtual const char * what() const throw(){
		return s_->str().c_str();
	}
private:
	mutable std::auto_ptr<std::stringstream> s_;
};

int main(int argc, char *argv[]){
	int x = 5;
	int y = 3;
	try{
		if(5 != 3)
			throw StreamingException() << x << " is not equal to " << y;
	}
	catch (const StreamingException & e){
		std::cout << e.what() << "\n";
	}
	return 0;
}
