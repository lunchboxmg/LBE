#pragma once

#include <iostream>

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "LbeExports.hpp"

namespace LBE
{
    class LBE_API Uniform
    {
    public:

        static int NOT_FOUND;

    protected:

        char* mName;
        int   mLocation;
        bool  mUsed = false;

    public:

        Uniform(char* aName, int aProgramId);
        ~Uniform();

        char* GetName() { return mName; }
        int GetLocation() { return mLocation; }
    };

    class LBE_API UniformFloat : public Uniform
    {
    protected:

        float mValue = 0.0;

    public:

        UniformFloat(char* aName, int aProgramId) :
            Uniform(aName, aProgramId) {}

        virtual void Load(float aValue);

    };

    class LBE_API UniformBool : public UniformFloat
    {
    public:
        
        virtual void Load(float aValue) override;
    };

    class LBE_API UniformVec3 : public Uniform
    {
    protected:

        float mX = 0.0f;
        float mY = 0.0f;
        float mZ = 0.0f;

    public:

        void Load(glm::vec3 aValue);
        void Load(float aX, float aY, float aZ);

    };

    class LBE_API UniformVec4 : public Uniform
    {
    protected:

        float mX = 0.0f;
        float mY = 0.0f;
        float mZ = 0.0f;
        float mW = 0.0f;

    public:

        void Load(glm::vec3 aValue);
        void Load(glm::vec4 aValue);
        void Load(float aX, float aY, float aZ, float aW = 1.0f);

    };

    // WE CHEAT WITH THIS UNIFORM AND JUST LOAD WHATEVER MATRIX THE USER INPUTS
    class LBE_API UniformMat4 : public Uniform
    {
    public:

        void Load(glm::mat4 aMatrix);
    };
}
