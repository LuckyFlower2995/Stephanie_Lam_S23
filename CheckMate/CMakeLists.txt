set(HEADER_FILES
	sourcecode/CheckMateUtil.h
	sourcecode/CheckMateApp.h
	sourcecode/GameWindow.h
	sourcecode/WindowImplementation.h
	sourcecode/GLFWcode/GLFWimplementation.h
	sourcecode/Renderer.h
	sourcecode/ImplRenderer.h
	sourcecode/OpenGLCode/OpenGLRenderer.h
	sourcecode/RendererTypes.h

	sourcecode/Shader.h
	sourcecode/ImplShader.h
	sourcecode/OpenGLCode/OpenGLShader.h

	sourcecode/Image.h
	sourcecode/ImplImage.h
	sourcecode/OpenGLCode/OpenGLImage.h

	sourcecode/Unit.h
	sourcecode/RendererTypes.h
	sourcecode/CheckMateEvents.h
	sourcecode/CheckMateKeys.h
)

set(SOURCE_FILES
	sourcecode/CheckMateApp.cpp
	sourcecode/GameWindow.cpp
	sourcecode/GLFWcode/GLFWimplementation.cpp
	sourcecode/Renderer.cpp
	sourcecode/OpenGLCode/OpenGLRenderer.cpp

	sourcecode/Shader.cpp
	sourcecode/OpenGLCode/OpenGLShader.cpp

	sourcecode/Image.cpp
	sourcecode/OpenGLCode/OpenGLImage.cpp	

	sourcecode/Unit.cpp
	sourcecode/CheckMateEvents.cpp
)

add_library(CheckMate SHARED ${HEADER_FILES} ${SOURCE_FILES})

include_directories(sourcecode)
include_directories(../glad/include)
include_directories(../stbi)
include_directories(../glfw/include)

target_precompile_headers(CheckMate PRIVATE sourcecode/pch.h)

target_link_libraries(CheckMate glfw glad stbi)

add_definitions(-DCHECKMATE_LIB)
add_definitions(-DCHECKMATE_GLFW)
add_definitions(-DCHECKMATE_OPENGL)
add_definitions(-DCHECKMATE_WINDOWS)
add_definitions(-DCHECKMATE_DEBUG=2)