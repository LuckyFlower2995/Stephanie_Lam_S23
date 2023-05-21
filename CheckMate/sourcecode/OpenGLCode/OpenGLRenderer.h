#pragma once

#include "ImplRenderer.h"
#include "Image.h"
#include "Shader.h"

namespace CheckMate {
	class OpenGLRenderer : public ImplRenderer {
	public:
		OpenGLRenderer();

		virtual void Draw(Image& image,
			TextureBox texCoords,
			Shader& shader,
			ScreenCoord coords) override;

		virtual void Clear() override;
	private:
		unsigned int mVBO{ 0 }, mVAO{ 0 }, mEBO{ 0 };
	};

}