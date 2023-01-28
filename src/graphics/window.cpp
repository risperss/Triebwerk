#include "window.hpp"

namespace triebwerk {

namespace graphics {

Window::Window(int width, int height, const char* title) {
    m_Width = width;
    m_Height = height;
    m_Title = title;
    if (!init()) {
        glfwTerminate();
    }

    for (int i = 0; i < k_NumKeys; i++) {
        m_Keys[i] = false;
    }
    for (int i = 0; i < k_NumButtons; i++) {
        m_Buttons[i] = false;
    }
}

Window::~Window() { glfwTerminate(); }

bool Window::init() {
    if (!glfwInit()) {
        std::cout << "Failed to initialize GLFW" << std::endl;
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_SCALE_TO_MONITOR, GLFW_TRUE);

    m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
    if (m_Window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        return false;
    }

    glfwMakeContextCurrent(m_Window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return false;
    }

    // Solution for high DPI displays
    glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
    glViewport(0, 0, m_Width, m_Width);

    glfwSetWindowUserPointer(m_Window, this);
    glfwSetFramebufferSizeCallback(m_Window, framebuffer_size_callback);
    glfwSetKeyCallback(m_Window, key_callback);
    glfwSetCursorPosCallback(m_Window, cursor_position_callback);
    glfwSetMouseButtonCallback(m_Window, mouse_button_callback);

    return true;
}

void Window::clear() const {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::update() {
    glfwSwapBuffers(m_Window);
    glfwPollEvents();
}

bool Window::closed() const { return glfwWindowShouldClose(m_Window) == 1; }

bool Window::isKeyPressed(unsigned int keycode) const {
    // TODO: some kind of logging system
    if (keycode >= k_NumKeys) {
        return false;
    }
    return m_Keys[keycode];
}

bool Window::isMousePressed(unsigned int button) const {
    if (button >= k_NumButtons) {
        return false;
    }
    return m_Buttons[button];
}

void Window::getMousePosition(int& x, int& y) const {
    x = m_X;
    y = m_Y;
}

// Private
void Window::framebuffer_size_callback(GLFWwindow* window, int width,
                                       int height) {
    Window* win = (Window*)glfwGetWindowUserPointer(window);
    win->setWidth(width);
    win->setHeight(height);
    glViewport(0, 0, width, height);
}

void Window::key_callback(GLFWwindow* window, int key, int scancode, int action,
                          int mods) {
    Window* win = (Window*)glfwGetWindowUserPointer(window);
    if (action == GLFW_PRESS) {
        win->setKey(key);
    } else if (action == GLFW_RELEASE) {
        win->resetKey(key);
    }
}

void Window::cursor_position_callback(GLFWwindow* window, double xpos,
                                      double ypos) {
    Window* win = (Window*)glfwGetWindowUserPointer(window);
    win->setCursorPosition(xpos, ypos);
}

void Window::mouse_button_callback(GLFWwindow* window, int button, int action,
                                   int mods) {
    Window* win = (Window*)glfwGetWindowUserPointer(window);
    if (action == GLFW_PRESS) {
        win->setButton(button);
    } else {
        win->resetButton(button);
    }
}

}  // namespace graphics
}  // namespace triebwerk