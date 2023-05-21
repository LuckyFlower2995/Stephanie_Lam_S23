#include "pch.h"
#include "OpenGLImage.h"
#include "glad/glad.h"
#include "stb_image.h"

namespace CheckMate {

	OpenGLImage::OpenGLImage(const std::string& imageFile) {
		unsigned int texture1;
		mImage = imageFile;
		

		glGenTextures(1, &texture1);

		glBindTexture(GL_TEXTURE_2D, texture1);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		int width, height, nrChannels;
		stbi_set_flip_vertically_on_load(true);
		
		unsigned char* data = stbi_load(imageFile.c_str(), &width, &height, &nrChannels, 0);
		

		if (data == nullptr) {
			std::cout << "ERROR: Image reading has failed" << std::endl;
		}
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		stbi_image_free(data);
		
	}

	OpenGLImage::OpenGLImage(std::string&& imageFile) {
		unsigned int texture1;
		mImage = imageFile;
		

		glGenTextures(1, &texture1);

		glBindTexture(GL_TEXTURE_2D, texture1);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		int width, height, nrChannels;
		stbi_set_flip_vertically_on_load(true);

		unsigned char* data = stbi_load(imageFile.c_str(), &width, &height, &nrChannels, 0);

		if (data == nullptr) {
			std::cout << "ERROR: Image reading has failed" << std::endl;
		}
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		stbi_image_free(data);
		
	}

	OpenGLImage::~OpenGLImage() {
		
	}

	void OpenGLImage::Activate() {
		
		int width, height, nrChannels;

		unsigned char* data = stbi_load(mImage.c_str(), &width, &height, &nrChannels, 0);
		if (data == nullptr) {
			std::cout << "ERROR: Image reading has failed" << std::endl;
		}
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	
		stbi_image_free(data);

	}

	int OpenGLImage::GetWidth() const {
		int width{ 0 }, height{ 0 }, n{ 0 }, info{ 0 };
		info = stbi_info(mImage.c_str(), &width, &height, &n);
		return width;
	}

	int OpenGLImage::GetHeight() const {
		int height{ 0 }, width{ 0 }, n{ 0 }, info{ 0 };
		info = stbi_info(mImage.c_str(), &width, &height, &n);
		return height;
	}
}