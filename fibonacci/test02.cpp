#include <iostream>
#include <array>
#include <utility>

template <int I>
struct Fib{
	static const int val = Fib<I-1>::val + Fib<I-2>::val;
};

template <>
struct Fib<0>{
	static const int val = 0;
};

template <>
struct Fib<1>{
	static const int val = 1;
};

template<size_t ... I>
const int fib_impl(std::index_sequence<I...>, const int i){
	constexpr std::array<int, sizeof...(I)> a = {Fib<I>::val... };
	return a[i];
}

const int fib(const int i){
	return fib_impl(std::make_index_sequence<47>(), i);
}

int main(int argc, const char* argv[]){
	std::cout << Fib<45>::val << "\n"; 
}
