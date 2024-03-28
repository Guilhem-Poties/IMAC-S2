#include <vector>
#include <iostream>
#include <iterator>

int main() {
    std::vector<int> vec {};

    for (int _ = 0; _ < 99; _++) {
        vec.push_back(rand() * 100);
    }

    for (iterator i = vec.begin(); i < vec.end(); i++)
    {
        /* code */
    }
    

    return 0;
}