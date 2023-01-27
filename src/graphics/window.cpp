#include "window.hpp"

namespace triebwerk {

namespace {

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

}  // namespace

namespace graphics {

Window::Window(int width, int height, const char* title) {
    m_Width = width;
    m_Height = height;
    m_Title = title;

    if (!init()) {
        glfwTerminate();
    }

    m_Keyboard = input::Keyboard(m_Window);
    m_Mouse = input::Mouse(m_Window);
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

    glfwSetFramebufferSizeCallback(m_Window, framebuffer_size_callback);

    glfwSetWindowUserPointer(m_Window, this);

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

}  // namespace graphics
}  // namespace triebwerk