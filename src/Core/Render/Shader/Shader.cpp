//
// Created by Lars on 23.05.2018.
//
#include "Shader.hpp"

Shader::Shader(std::string _vertexShaderPath, std::string _fragmentShaderPath)
{
    m_vertexShader = glCreateShader(GL_VERTEX_SHADER);
    m_fragmentShader = glad_glCreateShader(GL_FRAGMENT_SHADER);

    std::string vertexshaderSource = ReadFile(_vertexShaderPath);
    std::string fragmentshaderSource = ReadFile(_fragmentShaderPath);
    const char *cvertexshaderSource = vertexshaderSource.c_str();
    const char *cfragmentshaderSource = fragmentshaderSource.c_str();
    std::cout << cfragmentshaderSource << std::endl;
    std::cout << cvertexshaderSource << std::endl;

    int Result = GL_FALSE;
    int logLength;

    glShaderSource(m_vertexShader, 1, &cvertexshaderSource, NULL);
    glCompileShader(m_vertexShader);

    // Check vertex shader
    glGetShaderiv(m_vertexShader, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(m_vertexShader, GL_INFO_LOG_LENGTH, &logLength);
    std::vector<char> vertShaderError((logLength > 1) ? logLength : 1);
    glGetShaderInfoLog(m_vertexShader, logLength, NULL, &vertShaderError[0]);
    std::cout << &vertShaderError[0] << std::endl;

    glShaderSource(m_fragmentShader, 1, &cfragmentshaderSource, NULL);
    glCompileShader(m_fragmentShader);

    // Check fragment shader
    glGetShaderiv(m_fragmentShader, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(m_fragmentShader, GL_INFO_LOG_LENGTH, &logLength);
    std::vector<char> fragShaderError((logLength > 1) ? logLength : 1);
    glGetShaderInfoLog(m_fragmentShader, logLength, NULL, &fragShaderError[0]);
    std::cout << &fragShaderError[0] << std::endl;

    LinkShader();
}

Shader& Shader::operator=(Shader&& other)
{
    m_fragmentShader = other.m_fragmentShader;
    other.m_fragmentShader = 0;
    m_vertexShader = other.m_vertexShader;
    other.m_fragmentShader = 0;
    m_shaderProgram = other.m_shaderProgram;
    other.m_fragmentShader = 0;

    return *this;
}

void Shader::LinkShader()
{
    int Result;
    int logLength;

    m_shaderProgram = glCreateProgram();
    glAttachShader(m_shaderProgram, m_vertexShader);
    glAttachShader(m_shaderProgram, m_fragmentShader);
    glLinkProgram(m_shaderProgram);

    glGetProgramiv(m_shaderProgram, GL_LINK_STATUS, &Result);
    glGetProgramiv(m_shaderProgram, GL_INFO_LOG_LENGTH, &logLength);
    std::vector<char> programError((logLength > 1) ? logLength : 1);
    glGetProgramInfoLog(m_shaderProgram, logLength, NULL, &programError[0]);
    std::cout << &programError[0] << std::endl;

    DeleteShader();
}

void Shader::DeleteShader()
{
    glDeleteShader(m_vertexShader);
    glDeleteShader(m_fragmentShader);
}

std::string Shader::ReadFile(std::string FilePath)
{
    std::string content;
    std::ifstream fileStream(FilePath, std::ios::in);

    if (!fileStream.is_open()) {
        std::cerr << "Could not read file " << FilePath << ". File does not exist." << std::endl;
        return "";
    }

    std::string line = "";
    while (!fileStream.eof()) {
        std::getline(fileStream, line);
        content.append(line + "\n");
    }

    fileStream.close();
    return content;
}
