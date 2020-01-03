#pragma once

#include <string>

#include <glad/glad.h>

namespace LBE
{
    enum ShaderType
    {
        VERTEX, FRAGMENT, GEOMETRY
    };

    class Shader
    {
    private:

        std::string mName;

        GLint mProgram;

        GLint mVertexId;
        GLint mFragmentId;
        GLint mGeometryId;
        
    public:

        Shader();
        ~Shader();

        // LOAD THE SHADER SOURCE FILE INTO 
        void Load(std::string aFileName, ShaderType aType);
    };
}