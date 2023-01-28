#include <iostream>

#include "graphics/window.hpp"

int main(void) {
    using namespace triebwerk;

    graphics::Window window = graphics::Window(960, 540, "Triebwerk");
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

    std::cout << glGetString(GL_VERSION) << std::endl;

    int x, y;

    while (!window.closed()) {
        std::cout << window.getWidth() << " " << window.getHeight()
                  << std::endl;

        if (window.isKeyPressed(GLFW_KEY_A)) {
            std::cout << "PRESSED" << std::endl;
        }

        window.getMousePosition(x, y);
        std::cout << x << ", " << y << std::endl;

        if (window.isMousePressed(GLFW_MOUSE_BUTTON_RIGHT)) {
            std::cout << "RIGHT CLICK" << std::endl;
        }

        window.clear();
        window.update();
    }

    return 0;
}