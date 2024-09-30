# message if INCLUDE_UI is not set

set(IMGUI_DIR ${CHESSENGINE_ROOT_DIR}/vendor/imgui)
set(GLM_DIR ${CHESSENGINE_ROOT_DIR}/vendor/glm)
set(STB_DIR ${CHESSENGINE_ROOT_DIR}/vendor/stb)

# imgui sources, glfw opengl3 backend
file(GLOB UI_SOURCES src/*.cpp)


add_library(mui STATIC
    ${UI_SOURCES}
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/imgui_demo.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
    ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
    ${STB_DIR}/stb_image.cpp
)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

if(APPLE)
    add_definitions(-DGL_SILENCE_DEPRECATION)
    find_library(COCOA_LIBRARY Cocoa)
    find_library(OpenGL_LIBRARY OpenGL)
    find_library(IOKIT_LIBRARY IOKit)
    find_library(COREVIDEO_LIBRARY CoreVideo)
    set(EXTRA_LIBS ${OpenGL_LIBRARY} ${IOKIT_LIBRARY} ${COREVIDEO_LIBRARY})
endif(APPLE)

target_link_libraries(mui glfw ${OPENGL_LIBRARIES} GLEW::glew ${EXTRA_LIBS})

target_include_directories(mui PUBLIC
    inc
    ${GLM_DIR}
    ${IMGUI_DIR}
    ${IMGUI_DIR}/backends
    ${STB_DIR}
    ${OPENGL_INCLUDE_DIR}
    ${GLFW_INCLUDE_DIRS}
    ${IMGUI_DIR}
    ${IMGUI_DIR}/backends
    ${GLEW_INCLUDE_DIRS}
)
