#include "renderer.hpp"
#include "util.hpp"
#include <GL/glew.h>

namespace ui
{
    Renderable::Renderable()
        : shader(nullptr), strideWidth(0),
          vao(0),
          vbo(0),
          ibo(0),
          bufferChanged(false),
          indicesChanged(false),
          layoutChanged(false)
    {
    }

    // Renderable::Renderable(const Renderable &renderable)
    //     : shader(renderable.shader),
    //       strideWidth(renderable.strideWidth),
    //       vao(renderable.vao),
    //       vbo(renderable.vbo),
    //       ibo(renderable.ibo),
    //       bufferChanged(renderable.bufferChanged),
    //       indicesChanged(renderable.indicesChanged),
    //       layoutChanged(renderable.layoutChanged)
    // {
    //     for (auto &texture : renderable.textures)
    //     {
    //         textures.push_back(texture);
    //     }

    //     for (auto &layout : renderable.layouts)
    //     {
    //         layouts.push_back(layout);
    //     }

    //     for (auto &index : renderable.indices)
    //     {
    //         indices.push_back(index);
    //     }

    //     for (auto &value : renderable.buffer)
    //     {
    //         buffer.push_back(value);
    //     }
    // }

    Renderable::~Renderable()
    {
        if (vao != 0)
            GLCall(glDeleteVertexArrays(1, &vao));
        if (vbo != 0)
            GLCall(glDeleteBuffers(1, &vbo));
        if (ibo != 0)
            GLCall(glDeleteBuffers(1, &ibo));
    }

    void Renderable::SetShader(const std::shared_ptr<Shader> &shader)
    {
        this->shader = shader;
    }

    void Renderable::SetShader(const std::string &fileName)
    {
        shader = std::make_shared<Shader>(fileName);
    }

    std::shared_ptr<Shader> Renderable::GetShader() const
    {
        return shader;
    }

    void Renderable::AddTexture(const std::shared_ptr<Texture> &texture)
    {
        textures.push_back(texture);
    }

    void Renderable::AddLayout(const Layout &layout)
    {
        layouts.push_back(layout);
    }

    void Renderable::SetIndices(const std::vector<unsigned int> &indices)
    {
        this->indices.clear();
        AddIndices(indices);
    }

    void Renderable::AddIndices(const std::vector<unsigned int> &indices)
    {
        indicesChanged = true;
        for (auto &index : indices)
        {
            this->indices.push_back(index);
        }
    }

    void Renderable::Render()
    {
        GLCall(glBindVertexArray(vao));
        if (bufferChanged)
        {
            GLCall(glBindBuffer(GL_ARRAY_BUFFER, vbo));
            GLCall(glBufferData(GL_ARRAY_BUFFER, buffer.size() * sizeof(float), buffer.data(), GL_STATIC_DRAW));
            bufferChanged = false;
        }

        if (indicesChanged)
        {
            GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo));
            GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW));
            indicesChanged = false;
        }

        if (layoutChanged)
        {
            unsigned int offset = 0;
            for (auto &layout : layouts)
            {
                GLCall(glEnableVertexAttribArray(offset));
                GLCall(glVertexAttribPointer(offset, layout.count, layout.type, layout.normalized, strideWidth * sizeof(float), (void *)(offset * sizeof(float))));
                offset += layout.count;
            }
            layoutChanged = false;
        }

        if (shader == nullptr)
            return;
        shader->Bind();
        for (unsigned int i = 0; i < textures.size(); i++)
        {
            textures[i]->Bind(i);
            shader->SetUniform1i("u_Texture" + std::to_string(i), i);
        }
        // index buffer object
        GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo));
        GLCall(glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, nullptr));
    }

    void Renderable::Initialize()
    {
        shader->Initialize();
        if (vao == 0)
            GLCall(glGenVertexArrays(1, &vao));
            GLCall(glBindVertexArray(vao));
        if (vbo == 0)
            GLCall(glGenBuffers(1, &vbo));
        GLCall(glBindBuffer(GL_ARRAY_BUFFER, vbo));
        GLCall(glBufferData(GL_ARRAY_BUFFER, buffer.size() * sizeof(float), buffer.data(), GL_STATIC_DRAW));
        if (ibo == 0)
            GLCall(glGenBuffers(1, &ibo));
        GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo));
        GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW));
        unsigned int offset = 0;
        for (size_t i = 0; i < layouts.size(); i++)
        {
            auto &layout = layouts[i];
            GLCall(glEnableVertexAttribArray(i));
            GLCall(glVertexAttribPointer(i, layout.count, layout.type, layout.normalized, strideWidth * sizeof(float), (void *)(offset * sizeof(float))));
            offset += layout.count;
        }
    }

    Renderer::Renderer()
    {
    }

    void Renderer::Initialize()
    {
        GLCall(glEnable(GL_BLEND));
        GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
        for (auto &renderable : renderables)
        {
            renderable->Initialize();
        }
    }

    void Renderer::ClearScreen()
    {
        ClearScreen(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    }

    void Renderer::ClearScreen(const glm::vec4 &color)
    {
        GLCall(glClearColor(color.r, color.g, color.b, color.a));
        GLCall(glClear(GL_COLOR_BUFFER_BIT));
    }

    void Renderer::Push(Renderable *renderable)
    {
    }

    void Renderer::Push(std::shared_ptr<Renderable> renderable)
    {
        renderables.push_back(renderable);
    }

    void Renderer::Render()
    {
        for (auto &renderable : renderables)
        {
            renderable->Render();
        }
    }
} // namespace ui