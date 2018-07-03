//
// Created by Lars on 23.05.2018.
//

#include "VBO.hpp"

VBO::VBO()
{
    glGenBuffers(1, &m_VBO);
}

//TODO: only function with float
void VBO::SetVertices(std::vector<float> vertices)
{
    Bind();
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), static_cast<void*>(vertices.data()), GL_STATIC_DRAW);
    //unBind();
}

void VBO::unBind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::Bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
}
