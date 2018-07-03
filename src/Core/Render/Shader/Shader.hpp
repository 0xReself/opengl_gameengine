//
// Created by Lars on 23.05.2018.
//

#ifndef ENGINE_SHADER_HPP
#define ENGINE_SHADER_HPP

#pragma once

#include "glad\glad.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Shader
{
private:
    unsigned int m_vertexShader = 0;
    unsigned int m_fragmentShader = 0;

    unsigned int m_shaderProgram = 0;

    void LinkShader();
    void DeleteShader();
    std::string ReadFile(std::string FilePath);
public:
    Shader(std::string _vertexShaderPath, std::string _fragmentShaderPath);
    Shader& operator=(Shader&& other);

    unsigned int GetShaderProgram() { return m_shaderProgram; }
};


#endif //ENGINE_SHADER_HPP
