cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)

project(Aureliette)

# Add all Source Files
file(GLOB_RECURSE SOURCE_FILES
		${CMAKE_SOURCE_DIR}/src/*.cpp
		${CMAKE_SOURCE_DIR}/src/core/*.cpp
		${CMAKE_SOURCE_DIR}/src/math/*.cpp
		${CMAKE_SOURCE_DIR}/src/window/*.cpp
)

# Add all Header Files
file(GLOB_RECURSE HEADER_FILES
		${CMAKE_SOURCE_DIR}/src/*.h
		${CMAKE_SOURCE_DIR}/src/*.hpp
)

add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES}
		src/Engine/Utils.h
		src/Engine/Utils.cpp
		src/impl/Ogl/GLVertexArrayBuffer.cpp
		src/impl/Ogl/GLVertexArrayBuffer.h
		src/impl/Ogl/GLBuffer.cpp
		src/impl/Ogl/GLBuffer.h
		src/Engine/geometry/Vertex.h
		src/Engine/core/Globals.h
		src/impl/Ogl/GLIndexBuffer.cpp
		src/impl/Ogl/GLIndexBuffer.h
		src/impl/iBuffer.h
		src/Engine/core/Window.cpp
		src/Engine/core/InputManager.cpp
		src/Engine/core/InputManager.h
		src/Engine/geometry/Triangle.h
		src/Engine/geometry/Mesh.cpp
		src/Engine/geometry/Mesh.h
		src/Engine/core/Camera.cpp
		src/Engine/core/Camera.h
		src/programs/DoubleTriangle.cpp
		src/Engine/geometry/Pyramid.h
		src/Engine/core/ObjectLoader.cpp
		src/Engine/core/ObjectLoader.h
		src/Engine/geometry/Model.cpp
		src/Engine/geometry/Model.h
)

# Find OpenGL
find_package(OpenGL REQUIRED)

# External library roots
set(GLFW_ROOT_DIR external/glfw)
set(GLAD_ROOT_DIR external/glad)
set(GLM_ROOT_DIR external/glm-1.0.1)
set(STB_ROOT_DIR external/stbi_image)

# --- Assimp (precompiled) ---
set(ASSIMP_ROOT_DIR ${CMAKE_SOURCE_DIR}/external/assimp)
set(ASSIMP_INCLUDE_DIR ${ASSIMP_ROOT_DIR}/include)
set(ASSIMP_LIB_DIR ${ASSIMP_ROOT_DIR}/build/lib)

# Add external libs that are built with project
add_subdirectory(${GLFW_ROOT_DIR})
add_subdirectory(${GLAD_ROOT_DIR})
add_subdirectory(${GLM_ROOT_DIR})
add_subdirectory(${STB_ROOT_DIR})

# Include directories
target_include_directories(${PROJECT_NAME}
		PUBLIC ${GLFW_ROOT_DIR}/include
		PUBLIC ${GLAD_ROOT_DIR}/include/glad
		PUBLIC ${GLM_ROOT_DIR}/
		PUBLIC ${STB_ROOT_DIR}/include
		PUBLIC ${ASSIMP_INCLUDE_DIR}

		src/Engine
		src/
		src/impl
)

# Link directories (for static/dynamic libs)
target_link_directories(${PROJECT_NAME}
		PRIVATE ${ASSIMP_LIB_DIR}
)

# Link libraries
if (WIN32)
	target_link_libraries(${PROJECT_NAME} glfw opengl32 glad assimp)
elseif (UNIX)
	target_link_libraries(${PROJECT_NAME} glfw GL glad assimp)
endif ()

# --- Post-build step: copy DLL (Windows only) ---
if (WIN32)
	file(GLOB ASSIMP_DLL "${ASSIMP_ROOT_DIR}/build/bin/*.dll")
	add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
			COMMAND ${CMAKE_COMMAND} -E copy_if_different
			${ASSIMP_DLL}
			$<TARGET_FILE_DIR:${PROJECT_NAME}>)
endif()