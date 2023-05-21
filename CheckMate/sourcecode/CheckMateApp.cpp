#include "pch.h"
#include "CheckMateApp.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "stb_image.h"

#include "Renderer.h"
#include "Shader.h"
#include "Image.h"
#include "GameWindow.h"

namespace CheckMate {

	CheckMateApp::CheckMateApp() {
		GameWindow::Init();
		GameWindow::CreateWindow(620, 650, "Trapped Sheep");

		SetWindowCloseCallback([this]() {DefaultWindowCloseHandler(); });
	}

	void CheckMateApp::Run() {
		mNextFrameTime = std::chrono::steady_clock::now();

		while (!mGameWindowShouldClose) {
			OnUpdate();

			std::this_thread::sleep_until(mNextFrameTime);

			CheckMate::GameWindow::SwapBuffers();
			CheckMate::GameWindow::PollEvents();

			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;
		}
	}

	void CheckMateApp::SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc) {
		GameWindow::GetWindow()->SetKeyPressedCallback(callbackFunc);
	}

	void CheckMateApp::SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc) {
		GameWindow::GetWindow()->SetKeyReleasedCallback(callbackFunc);
	}

	void CheckMateApp::SetWindowCloseCallback(std::function<void()> callbackFunc) {
		GameWindow::GetWindow()->SetWindowCloseCallback(callbackFunc);
	}

	void CheckMateApp::DefaultWindowCloseHandler() {
		mGameWindowShouldClose = true;
	}

}