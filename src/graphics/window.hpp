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
    int m_Width, m_Height;
    const char* m_Title;
    GLFWwindow* m_Window;

   public:
    Window(int width, int height, const char* title);
    ~Window();

    inline int getWidth() const { return m_Width; }
    inline int getHeight() const { return m_Height; }

    void clear() const;
    void update();
    bool closed() const;

   private:
    bool init();
};

}  // namespace graphics
}  // namespace triebwerk