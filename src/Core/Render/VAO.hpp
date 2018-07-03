//
// Created by Lars on 23.05.2018.
//

#ifndef ENGINE_VAO_HPP
#define ENGINE_VAO_HPP

#pragma once

#include "glad/glad.h"

class VAO {
public:
    VAO();
    void Bind();
    void unBind();
    //TODO: hardcoded
    void Setup();
private:
    unsigned int m_VAO;
};


#endif //ENGINE_VAO_HPP
