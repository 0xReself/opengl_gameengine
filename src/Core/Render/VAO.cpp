//
// Created by Lars on 23.05.2018.
//

#include "VAO.hpp"

VAO::VAO()
{
    glGenVertexArrays(1, &m_VAO);
}

void VAO::Setup()
{
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
}

void VAO::Bind()
{
    glBindVertexArray(m_VAO);
}
void VAO::unBind()
{
    glBindVertexArray(0);
}