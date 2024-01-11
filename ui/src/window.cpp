#include "window.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

namespace ui
{

    static void glfw_error_callback(int error, const char *description)
    {
        fprintf(stderr, "GLFW Error %d: %s\n", error, description);
    }

    Window::Window(unsigned int width, unsigned int height, const std::string &title)
        : height(height), width(width), title(title), lastFrameTime(0.0f)
    {
    }

    void Window::Show()
    {
        if (!OnInit() || !Init() || !OnPostInit())
        {
            throw std::runtime_error("Failed to initialize window");
        }

        lastFrameTime = GetTime();

        while (!ShouldClose())
        {
            double currentTime, deltaTime;
            auto get_time = [&]()
            {
                currentTime = GetTime();
                deltaTime = currentTime - lastFrameTime;
                lastFrameTime = currentTime;
            };

            get_time();
            OnUpdate(deltaTime);
            get_time();
            Update(deltaTime);
            get_time();
            OnLateUpdate(deltaTime);
            Render();
            OnRender();
        }

        OnDestroy();
        Destroy();
    }

    bool Window::OnInit()
    {
        return true;
    }

    bool Window::OnPostInit()
    {
        return true;
    }

    void Window::OnUpdate(double deltaTime)
    {
    }

    void Window::OnLateUpdate(double deltaTime)
    {
    }

    void Window::OnRender()
    {
    }

    void Window::OnDestroy()
    {
    }

    GLWindow::GLWindow(unsigned int height, unsigned int width, const std::string &title)
        : Window(height, width, title), hwnd(nullptr)
    {
    }

    bool GLWindow::Init()
    {
        glfwSetErrorCallback(glfw_error_callback);
        if (!glfwInit())
        {
            std::cout << "Failed to initialize GLFW" << std::endl;
            return false;
        }

#if defined(IMGUI_IMPL_OPENGL_ES2)
        // GL ES 2.0 + GLSL 100
        const char *glsl_version = "#version 100";
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
        glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
#elif defined(__APPLE__)
        // GL 3.2 + GLSL 150
        const char *glsl_version = "#version 410";
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // 3.2+ only
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);           // Required on Mac
#else
        // GL 3.0 + GLSL 130
        const char *glsl_version = "#version 130";
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
        // glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
        // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only
#endif
        hwnd = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
        if (hwnd == nullptr)
        {
            std::cout << "Failed to create GLFW window" << std::endl;
            Destroy();
            return false;
        }
        glfwMakeContextCurrent(hwnd);

        if (glewInit() != GLEW_OK)
        {
            std::cout << "Failed to initialize GLEW" << std::endl;
            Destroy();
            return false;
        }

        return true;
    }

    void GLWindow::Update(double deltaTime)
    {
        glfwPollEvents();
    }

    void GLWindow::Render()
    {
        glfwSwapBuffers(hwnd);
    }

    void GLWindow::Destroy()
    {
        if (hwnd != nullptr)
        {
            glfwDestroyWindow(hwnd);
            hwnd = nullptr;
        }
        glfwTerminate();
    }

    bool GLWindow::ShouldClose()
    {
        return glfwWindowShouldClose(hwnd);
    }

    double GLWindow::GetTime()
    {
        return glfwGetTime();
    }

    ImGuiGLWindow::ImGuiGLWindow(unsigned int height, unsigned int width, const std::string &title)
        : GLWindow(height, width, title)
    {
    }

    bool ImGuiGLWindow::Init()
    {
        if (!GLWindow::Init())
            return false;

        // Setup Dear ImGui context
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO &io = ImGui::GetIO();
        (void)io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;  // Enable Gamepad Controls

        // Setup Dear ImGui style
        ImGui::StyleColorsDark();
        // ImGui::StyleColorsLight();

        // Setup Platform/Renderer backends
        ImGui_ImplGlfw_InitForOpenGL(hwnd, true);
        ImGui_ImplOpenGL3_Init("#version 410");
        return true;
    }

    void ImGuiGLWindow::Update(double deltaTime)
    {
        GLWindow::Update(deltaTime);
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
    }

    void ImGuiGLWindow::Render()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        GLWindow::Render();
    }

    void ImGuiGLWindow::Destroy()
    {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
        GLWindow::Destroy();
    }
}
