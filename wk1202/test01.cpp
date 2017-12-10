#include <stdexcept>
#include <sstream>
#include <iostream>
#include <vector>
#include <list>
#include <utility>

template <typename Cont>
void push_many_back(const Cont&) {
}

template <typename Cont, typename T, typename... Ts>
void push_many_back(Cont& cont, T&& head, Ts&&... tail) {
    cont.push_back(std::forward<T>(head));
    push_many_back(cont, std::forward<Ts>(tail)...);
};



int main() {
    std::vector<int> v;
    v.reserve(10);
    push_many_back(v);
    if (!v.empty())
        throw std::logic_error{"v should be empty"};
    v.push_back(10);
    push_many_back(v, 1, 1.5, 2U);
    if (v != std::vector<int>{10, 1, 1, 2})
        throw std::logic_error{"wrong value for v"};

    std::list<std::string> strings;
    push_many_back(strings, "hello", std::string{"world"});
    if (strings != std::list<std::string>{"hello", "world"})
        throw std::logic_error{"wrong value for strings"};

    std::cout << "test passed\n";
}
