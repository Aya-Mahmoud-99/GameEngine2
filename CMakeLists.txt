cmake_minimum_required(VERSION 3.0.0)   # Selects the minimum version of CMake required to run this file
project(GFX-LAB VERSION 0.1.0)          # Here we select the project name and version

# Here we select C++17 with all the standards required and all compiler-specific extensions disabled
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# These are the options we select for building GLFW as a library
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)        # Don't build Documentation
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)       # Don't build Tests
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)    # Don't build Examples
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)           # Don't build Installation Information
set(GLFW_USE_HYBRID_HPG ON CACHE BOOL "" FORCE)     # Add variables to use High Performance Graphics Card if available
add_subdirectory(vendor/glfw)                       # Build the GLFW project to use later as a library

# A variable with all the source files of GLAD
set(GLAD_SOURCE vendor/glad/src/gl.c)
# A variables with all the source files of Dear ImGui
set(IMGUI_SOURCES
        vendor/imgui/imgui.cpp
        vendor/imgui/imgui_demo.cpp
        vendor/imgui/imgui_draw.cpp
        vendor/imgui/imgui_widgets.cpp
        vendor/imgui/imgui_impl/imgui_impl_glfw.cpp
        vendor/imgui/imgui_impl/imgui_impl_opengl3.cpp
        )

# Combine all vendor source files together into a single variable
set(VENDOR_SOURCES ${GLAD_SOURCE} ${IMGUI_SOURCES})

# A variable with all our source files that are common between executable targets (examples)
set(COMMON_SOURCES
        source/common/application.cpp
        source/common/shader.cpp
        source/common/mesh/mesh-utils.cpp
        source/common/texture/texture-utils.cpp
        source/common/texture/screenshot.cpp source/common/ECS/Component.cpp source/common/ECS/Component.h source/common/ECS/Entity.cpp source/common/ECS/Entity.h source/common/ECS/World.cpp source/common/ECS/World.h source/common/ECS/System.cpp source/common/ECS/System.h source/common/ECS/Components/Transform.cpp source/common/ECS/Components/Transform.h source/common/ECS/Components/MeshRenderer.cpp source/common/ECS/Components/MeshRenderer.h source/common/ECS/Components/Camera.cpp source/common/ECS/Components/Camera.h source/common/ECS/GameState.cpp source/common/ECS/GameState.h source/common/ECS/Components/CameraComponent.cpp source/common/ECS/Components/CameraComponent.h source/common/ECS/GameStateManager.h source/common/ECS/GameStateManager.cpp)

# Define the directories in which to search for the included headers
include_directories(
        source/common
        vendor/glfw/include
        vendor/glad/include
        vendor/glm
        vendor/imgui
        vendor/utils
)

# For each example, we add an executable target
# Each target compiles one example source file and the common & vendor source files
# Then we link GLFW with each target
add_executable(EMPTY_WINDOW source/examples/main.cpp ${COMMON_SOURCES} ${VENDOR_SOURCES})
target_link_libraries(EMPTY_WINDOW glfw)

add_executable(phase2 source/examples/phase2_main.cpp ${COMMON_SOURCES} ${VENDOR_SOURCES})
target_link_libraries(phase2 glfw)

