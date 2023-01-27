#include "graphics/window.hpp"

int main(void) {
    using namespace triebwerk;

    graphics::Window window = graphics::Window(800, 600, "Triebwerk");

    while (!window.closed()) {
        window.update();
    }

    return 0;
}