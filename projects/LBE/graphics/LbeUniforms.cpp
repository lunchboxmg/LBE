#include "LbeUniforms.hpp"

int LBE::Uniform::NOT_FOUND = -1;

LBE::Uniform::Uniform(char* aName, int aProgramId)
{
    mName = aName;
    mLocation = glGetUniformLocation(aProgramId, aName);
    if (mLocation == NOT_FOUND)
    {
        std::cout << "WARNING: No uniform variable [" << aName << "] not found" << std::endl;
    }
}

LBE::Uniform::~Uniform()
{

}

// VIRTUAL
void LBE::UniformFloat::Load(float aValue)
{
    if (!mUsed || mValue != aValue)
    {
        glUniform1f(mLocation, aValue);
        mValue = aValue;
        mUsed = true;
    }
}

// VIRTUAL / OVERRIDE
void LBE::UniformBool::Load(float aValue)
{
    UniformFloat::Load(aValue > 0.0 ? 1.0 : 0.0);
}

void LBE::UniformVec3::Load(glm::vec3 aValue)
{
    Load(aValue.x, aValue.y, aValue.z);
}

void LBE::UniformVec3::Load(float aX, float aY, float aZ)
{
    if (!mUsed || mX == aX || mY != aY || mZ != aZ)
    {
        glUniform3f(mLocation, aX, aY, aZ);
        mX = aX;
        mY = aY;
        mZ = aZ;
        mUsed = true;
    }
}

void LBE::UniformVec4::Load(glm::vec3 aValue)
{
    Load(aValue.x, aValue.y, aValue.z);
}

void LBE::UniformVec4::Load(glm::vec4 aValue)
{
    Load(aValue.x, aValue.y, aValue.z, aValue.w);
}

void LBE::UniformVec4::Load(float aX, float aY, float aZ, float aW)
{
    if (!mUsed || mX == aX || mY != aY || mZ != aZ)
    {
        glUniform4f(mLocation, aX, aY, aZ, aW);
        mX = aX;
        mY = aY;
        mZ = aZ;
        mUsed = true;
    }
}

void LBE::UniformMat4::Load(glm::mat4 aMatrix)
{
    glUniformMatrix4fv(mLocation, 1, GL_FALSE, glm::value_ptr(aMatrix));
}

