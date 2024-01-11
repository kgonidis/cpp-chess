#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "shader.hpp"
#include "texture.hpp"
#include <glm/glm.hpp>
#include <vector>
#include <memory>

namespace ui
{
    struct Layout
    {
        int count;
        unsigned int type;
        unsigned char normalized;
    };

    class Renderable
    {
    public:
        Renderable();
        Renderable(const Renderable &renderable) = delete;
        Renderable(Renderable &&renderable) = delete;
        virtual ~Renderable();
        virtual void SetShader(const std::shared_ptr<Shader> &shader);
        virtual void SetShader(const std::string &fileName);
        virtual std::shared_ptr<Shader> GetShader() const;
        virtual void AddTexture(const std::shared_ptr<Texture> &texture);
        virtual void AddLayout(const Layout &layout);
        virtual void SetIndices(const std::vector<unsigned int> &indices);
        virtual void AddIndices(const std::vector<unsigned int> &indices);
        virtual void Initialize();
        template <unsigned int StrideWidth>
        void SetVertexBuffer(const std::vector<std::array<float, StrideWidth>> &buffer)
        {
            bufferChanged = true;
            if (StrideWidth != strideWidth)
                layoutChanged = true;
            strideWidth = StrideWidth;
            this->buffer.clear();
            for (auto &position : buffer)
            {
                for (auto &value : position)
                {
                    this->buffer.push_back(value);
                }
            }
        }

        template <unsigned int StrideWidth>
        void AddVertices(const std::vector<std::array<float, StrideWidth>> &buffer)
        {
            if (strideWidth == 0)
            {
                SetVertexBuffer(buffer);
                return;
            }
            assert(StrideWidth == strideWidth);
            bufferChanged = true;
            for (auto &position : buffer)
            {
                for (auto &value : position)
                {
                    this->buffer.push_back(value);
                }
            }
        }

        virtual void Render();

    protected:
        std::shared_ptr<Shader> shader;
        std::vector<std::shared_ptr<Texture>> textures;
        std::vector<float> buffer;
        std::vector<unsigned int> indices;
        std::vector<Layout> layouts;
        unsigned int strideWidth;
        unsigned int vao;
        unsigned int vbo;
        unsigned int ibo;
        bool bufferChanged;
        bool indicesChanged;
        bool layoutChanged;
    };

    class Renderer
    {
    public:
        Renderer();
        ~Renderer() = default;
        void Initialize();
        void ClearRenderables();
        void ClearScreen();
        void ClearScreen(const glm::vec4 &color);
        void Push(Renderable *renderable);
        void Push(std::shared_ptr<Renderable> renderable);
        void Render();

    private:
        std::vector<std::shared_ptr<Renderable>> renderables;
    };

}

#endif