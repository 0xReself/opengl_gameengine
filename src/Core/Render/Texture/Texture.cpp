//
// Created by Lars on 05.06.2018.
//

#include "Texture.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "../../../stb_image.h"

Texture::Texture(std::string _path)
{
    glGenTextures(1, &m_texture);
    Bind();
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    int width, height, nrChannels;
    unsigned char *data = stbi_load("Textures/cobblestone.png", &width, &height, &nrChannels, 0);
    if(data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
        std::cout << "Load texture" << std::endl;
    } else {
        std::cout << "Failed to load Texture" << std::endl;
    }
    stbi_image_free(data);
    //LoadTexture(_path);
}

void Texture::LoadTexture(std::string _path)
{

}

void Texture::SetUniform(int _program)
{
    glUseProgram(_program);
    glUniform1i(glGetUniformLocation(_program, "m_texture"), 0);
}

void Texture::Bind()
{
    glBindTexture(GL_TEXTURE_2D, m_texture);
}

void Texture::unBind()
{
    glBindTexture(GL_TEXTURE_2D, 0);
}