#ifndef SHADER_HPP
#define SHADER_HPP

#include <string>
#include <unordered_map>

#include "glm/glm.hpp"

namespace ui
{
    struct ShaderProgramSource
    {
        std::string VertexSource;
        std::string FragmentSource;
    };

    class Shader
    {
    private:
        unsigned int m_RendererID;
        std::string m_FilePath;
        std::unordered_map<std::string, int> m_UniformLocationCache;
        ShaderProgramSource m_ShaderProgramSource;

    public:
        Shader(const std::string &filepath);
        ~Shader();

        unsigned int Initialize();
        void Bind() const;
        void Unbind() const;

        // Set uniforms
        void SetUniform1i(const std::string &name, int value);
        void SetUniform1f(const std::string &name, float value);
        void SetUniform4f(const std::string &name, float f0, float f1, float f2, float f3);
        void SetUniformMat4f(const std::string &name, const glm::mat4 &matrix);

    private:
        int GetUniformLocation(const std::string &name);
        struct ShaderProgramSource ParseShader(const std::string &filepath);
        unsigned int CompileShader(unsigned int type, const std::string &source);
    };
}

#endif