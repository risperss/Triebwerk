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

    // Prevents scaling issues with high DPI displays
    int width;
    int height;
    glfwGetFramebufferSize(m_Window, &width, &height);
    glViewport(0, 0, width, height);
    glfwSetFramebufferSizeCallback(m_Window, framebuffer_size_callback);

    return true;
}

bool Window::closed() const { return glfwWindowShouldClose(m_Window); }

void Window::update() const {
    glfwSwapBuffers(m_Window);
    glfwPollEvents();
}

}  // namespace graphics
}  // namespace triebwerk