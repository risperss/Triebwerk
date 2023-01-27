#include "keyboard.hpp"

#include <iostream>

#include "graphics/window.hpp"

namespace triebwerk {
namespace input {

Keyboard::Keyboard(GLFWwindow* window) {
    m_Window = window;
    for (int i = 0; i < k_NumKeys; i++) {
        m_Keys = false;
    }
    glfwSetKeyCallback(window, key_callback);
}

static void Keyboard::key_callback(GLFWwindow* window, int key, int scancode,
                                   int action, int mods) {
    Window* win = (Window*)glfwGetWindowUserPointer(window);
    win->m_Keyboard.setKey(scancode);

    if (action == GLFW_RELEASE) {
        resetKey(scancode);
    } else {
        setKey(scancode);
    }
}

}  // namespace input
}  // namespace triebwerk