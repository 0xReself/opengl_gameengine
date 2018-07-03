//
// Created by Lars on 05.06.2018.
//

#ifndef ENGINE_TEXTURE_HPP
#define ENGINE_TEXTURE_HPP

#include "glad/glad.h"
#include <iostream>

class Texture {
public:
    Texture(std::string _path);
    void SetUniform(int _program);
    unsigned int m_texture;
private:
    void Bind();
    void unBind();
    void LoadTexture(std::string _path);
};


#endif //ENGINE_TEXTURE_HPP
