#pragma once

// clang-format off
#include <glad/glad.h>
#include <GLFW/glfw3.h>
// clang-format on

#include <iostream>

namespace triebwerk {

namespace graphics {

class Window {
   private:
    // graphics
    int m_Width, m_Height;
    const char* m_Title;
    GLFWwindow* m_Window;

    // input
    static const int k_NumKeys = 1024;
    static const int k_NumButtons = 32;
    bool m_Keys[k_NumKeys];
    bool m_Buttons[k_NumButtons];
    double m_X, m_Y;

   public:
    Window(int width, int height, const char* title);
    ~Window();

    inline int getWidth() const { return m_Width; }
    inline int getHeight() const { return m_Height; }
    inline void setWidth(int width) { m_Width = width; };
    inline void setHeight(int height) { m_Height = height; };
    inline GLFWwindow* getGFLWwindowPointer() const { return m_Window; }

    void clear() const;
    void update();
    bool closed() const;

    inline void setKey(int keycode) { m_Keys[keycode] = true; };
    inline void resetKey(int keycode) { m_Keys[keycode] = false; };
    inline void setCursorPosition(double xpos, double ypos) {
        m_X = xpos;
        m_Y = ypos;
    };
    inline void setButton(int button) { m_Buttons[button] = true; };
    inline void resetButton(int button) { m_Buttons[button] = false; }

    bool isKeyPressed(unsigned int keycode) const;
    bool isMousePressed(unsigned int button) const;
    void getMousePosition(int& x, int& y);

   private:
    bool init();
    static void framebuffer_size_callback(GLFWwindow* window, int width,
                                          int height);
    static void key_callback(GLFWwindow* window, int key, int scancode,
                             int action, int mods);
    static void cursor_position_callback(GLFWwindow* window, double xpos,
                                         double ypos);
    static void mouse_button_callback(GLFWwindow* window, int button,
                                      int action, int mods);
};

}  // namespace graphics
}  // namespace triebwerk