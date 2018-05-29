#include <vector>
#include <iostream>

template<typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
    out << "[";
    size_t last = v.size() - 1;
    for (size_t i = 0; i < v.size(); ++i) {
        out << v[i];
        if (i != last)
            out << ", ";
    }
    out << "]";
    return out;
}

int main() {
    std::vector<std::vector<int> > x { { 1, 2, 3 }, { 4, 5, 6 } };

    std::cout << x;
}
