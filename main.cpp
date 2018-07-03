#include <iostream>
#include "src/Core/Core.hpp"


int main() {
    std::cout << "Hello, World!" << std::endl;

    Window window(800, 600, "Engine_Test");

    Core(window);

    system("Pause");

    return 0;
}