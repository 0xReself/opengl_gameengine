//
// Created by Lars on 23.05.2018.
//
#ifndef ENGINE_WINDOW_HPP
#define ENGINE_WINDOW_HPP
#pragma once

#include <iostream>
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>

class Window {
public:
    Window(const unsigned short int _windowWidth, const unsigned short int _windowHeight, const std::string _title) noexcept;
    ~Window() noexcept;
    inline void Terminate() noexcept;
    void SwapBuffer() noexcept;
    void PollEvents() noexcept;
    GLFWwindow* GetWindow() noexcept;
    unsigned short int GetWindowWidth() noexcept;
    unsigned short int GetWindowHeight() noexcept;
private:
    GLFWwindow* m_window;
    unsigned short int m_windowWidth;
    unsigned short int m_windowHeight;
    void Init() noexcept;
    void InitGlad() noexcept;
};

#endif //ENGINE_WINDOW_HPP
