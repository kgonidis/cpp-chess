#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>

typedef struct GLFWwindow GLFWwindow;
namespace ui
{
    class Window
    {
    protected:
        unsigned int height;
        unsigned int width;
        std::string title;
        double lastFrameTime;

    public:
        Window(unsigned int width, unsigned int height, const std::string &title);
        virtual ~Window() = default;
        virtual void Show();
        virtual bool OnInit();
        virtual bool OnPostInit();
        virtual void OnUpdate(double deltaTime);
        virtual void OnLateUpdate(double deltaTime);
        virtual void OnRender();
        virtual void OnDestroy();
        virtual bool ShouldClose() = 0;
        virtual double GetTime() = 0;

    protected:
        virtual bool Init() = 0;
        virtual void Update(double deltaTime) = 0;
        virtual void Render() = 0;
        virtual void Destroy() = 0;
    };

    class GLWindow : public Window
    {
    public:
        GLWindow(unsigned int height, unsigned int width, const std::string &title);
        bool ShouldClose() override;
        double GetTime() override;

    protected:
        virtual bool Init() override;
        virtual void Update(double deltaTime) override;
        virtual void Render() override;
        virtual void Destroy() override;

    protected:
        GLFWwindow *hwnd;
    };

    class ImGuiGLWindow : public GLWindow
    {
    public:
        ImGuiGLWindow(unsigned int height, unsigned int width, const std::string &title);

    protected:
        virtual bool Init() override;
        virtual void Update(double deltaTime) override;
        virtual void Render() override;
        virtual void Destroy() override;
    };
}

#endif