//
// Created by Lars on 23.05.2018.
//

#include "Window.hpp"

Window::Window(const unsigned short int _windowWidth, const unsigned short int _windowHeight, const std::string _title) noexcept
{
    Init();
    m_window = glfwCreateWindow(_windowWidth, _windowHeight, _title.c_str(), NULL, NULL);
    if(m_window == nullptr)
    {
        std::cout << "[ENGINE] Failed to create a Window!" << std::endl;
        Terminate();
    }

    m_windowWidth = _windowWidth;
    m_windowHeight = _windowHeight;

    glfwMakeContextCurrent(m_window);

    //TODO: Call Events like glfwSetFramebufferSizeCallback ...

    InitGlad();
}

Window::~Window() noexcept
{
    Terminate();
}

void Window::Init() noexcept
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void Window::InitGlad() noexcept
{
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "[ENGINE] Failed to initialize GLAD!" << std::endl;
        Terminate();
    }
}

inline void Window::Terminate() noexcept
{
    glfwTerminate();
}

void Window::SwapBuffer() noexcept
{
    glfwSwapBuffers(m_window);
}

void Window::PollEvents() noexcept
{
    glfwPollEvents();
}

GLFWwindow* Window::GetWindow() noexcept
{
    return m_window;
}

unsigned short int Window::GetWindowWidth() noexcept
{
    return m_windowWidth;
}

unsigned short int Window::GetWindowHeight() noexcept
{
    return m_windowHeight;
}
