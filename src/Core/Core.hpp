//
// Created by Lars on 05.06.2018.
//

#ifndef ENGINE_CORE_HPP
#define ENGINE_CORE_HPP

#pragma once
#include "Render/Texture/Texture.hpp"
#include "../Window/Window.hpp"
#include "Render/VAO.hpp"
#include "Render/VBO.hpp"
#include "Render/Shader/Shader.hpp"

float x = 0.00125;
float y = 0.0016666f;

void processInput(GLFWwindow *window, Camera camera, float deltaTime);

std::vector<float> vertices
{
        // first triangle
        400 * x,  400 * y, 0.0f, 1.0f, 1.0f,   // top right
        400 * x, -400 * y, 0.0f, 1.0f, 0.0f,  // bottom right
        -400 * x,  400 * y, 0.0f,  0.0f, 1.0f, // top left
        // second triangle
        400 * x, -400 * y, 0.0f,  1.0f, 0.0f, // bottom right
        -400 * x, -400 * y, 0.0f, 0.0f, 0.0f,  // bottom left
        -400 * x,  400 * y, 0.0f, 0.0f, 1.0f    // top left
};

void Core(Window _window)
{

    float deltaTime = 0.0f;	// time between current frame and last frame
    float lastFrame = 0.0f;
    Texture tex("Textures/cobblestone.jpg");
    Shader _shader("Shaders/vertexShader.vs", "Shaders/fragmentShader.fs");
    VBO _vbo;
    VAO _vao;

    _vao.Bind();
    _vbo.SetVertices(vertices);
    _vao.Setup();
    _vao.unBind();

    tex.SetUniform(_shader.GetShaderProgram());


    while(!glfwWindowShouldClose(_window.GetWindow()))
    {

        glUseProgram(_shader.GetShaderProgram());
        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)800 / (float)600, 0.1f, 100.0f);
        glUniformMatrix4fv(glGetUniformLocation(_shader.GetShaderProgram(), "projection"), 1, GL_FALSE, &projection[0][0]);

        glm::mat4 view = camera.GetViewMatrix();
        glUniformMatrix4fv(glGetUniformLocation(_shader.GetShaderProgram(), "view"), 1, GL_FALSE, &view[0][0]);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE0, tex.m_texture);

        glUseProgram(_shader.GetShaderProgram());
        _vao.Bind();
        glm::mat4 model;
        model = glm::translate(model, glm::vec3(-0.5, -0.5, 0.0f));
        model = glm::rotate(model, glm::radians(20.0f), glm::vec3(1.0f, 0.3f, 0.5f));
        glUniformMatrix4fv(glGetUniformLocation(_shader.GetShaderProgram(), "model"), 1, GL_FALSE, &model[0][0]);

        glDrawArrays(GL_TRIANGLES, 0, 6);
        _vao.unBind();

        _window.SwapBuffer();
        _window.PollEvents();
    }
}


#endif //ENGINE_CORE_HPP
