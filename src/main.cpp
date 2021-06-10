#include <iostream>

int main() try {
    std::cout << "Hello there" << std::endl;

    return 0;
} catch (const std::exception & ex) {
    std:: cout << ex.what();
}
