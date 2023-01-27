#include "mouse.hpp"

namespace triebwerk {
namespace input {

Mouse::Mouse(GLFWwindow* window) {
    m_Window = window;
    for (int i = 0; i < k_NumButtons; i++) {
        m_Buttons[i] = false;
    }
    glfwSetCursorPosCallback(m_Window, cursor_position_callback);
    glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
}

static void Mouse::cursor_position_callback(GLFWwindow* window, double xpos,
                                            double ypos) {
    Window* win = (Window*)glfwGetWindowUserPointer(window);
    win->m_Mouse.
}

static void Mouse::mouse_button_callback(GLFWwindow* window, int button,
                                         int action, int mods);

}  // namespace input
}  // namespace triebwerk