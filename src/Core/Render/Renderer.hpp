//
// Created by Lars on 23.05.2018.
//

#ifndef ENGINE_RENDERER_HPP
#define ENGINE_RENDERER_HPP

#include "VAO.hpp"
#include "VBO.hpp"

#pragma once

class Renderer {
public:
    Renderer();
    void Render();

    VAO m_vao;
private:

};


#endif //ENGINE_RENDERER_HPP
