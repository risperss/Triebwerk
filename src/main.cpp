#include <iostream>

#include "graphics/window.hpp"

int main(void) {
    using namespace triebwerk;

    graphics::Window window = graphics::Window(960, 540, "Triebwerk");
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

    std::cout << glGetString(GL_VERSION) << std::endl;

    while (!window.closed()) {
        std::cout << window.getWidth() << " " << window.getHeight()
                  << std::endl;

        window.clear();
        window.update();
    }

    return 0;
}