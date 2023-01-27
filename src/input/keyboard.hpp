#pragma once

// clang-format off
#include <glad/glad.h>
#include <GLFW/glfw3.h>
// clang-format on

namespace triebwerk {
namespace input {

class Keyboard {
   private:
    static const int k_NumKeys = 1024;
    GLFWwindow* m_Window;
    static bool m_Keys[1024];

   public:
    Keyboard(GLFWwindow* window);
    ~Keyboard();

    inline void setKey(int scancode) { m_Keys[scancode] = true; };
    inline void resetKey(int scancode) { m_Keys[scancode] = false; };

   private:
    static void key_callback(GLFWwindow* window, int key, int scancode,
                             int action, int mods);
};

}  // namespace input
}  // namespace triebwerk