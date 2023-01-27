#pragma once

// clang-format off
#include <glad/glad.h>
#include <GLFW/glfw3.h>
// clang-format on

namespace triebwerk {
namespace input {

class Mouse {
   private:
    static const int k_NumButtons = 32;
    static double m_X, m_Y;
    static bool m_Buttons[k_NumButtons];

   public:
    Mouse(GLFWwindow* window);

    inline void setCursorPosition(double xpos, double ypos) {
        m_X = xpos;
        m_Y = ypos;
    }
    inline void setButton(...);
    inline void resetButton(...);

   private:
    static void cursor_position_callback(GLFWwindow* window, double xpos,
                                         double ypos);
    static void mouse_button_callback(GLFWwindow* window, int button,
                                      int action, int mods);
};

}  // namespace input
}  // namespace triebwerk