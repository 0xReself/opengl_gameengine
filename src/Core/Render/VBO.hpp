//
// Created by Lars on 23.05.2018.
//

#ifndef ENGINE_VBO_HPP
#define ENGINE_VBO_HPP
#pragma once

#include "glad/glad.h"
#include <vector>

class VBO {
public:
    VBO();
    void SetVertices(std::vector<float> vertices);
private:
    unsigned int m_VBO;
    void Bind();
    void unBind();
};


#endif //ENGINE_VBO_HPP
