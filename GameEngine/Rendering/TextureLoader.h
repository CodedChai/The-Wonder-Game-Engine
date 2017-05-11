#pragma once
#include "../Dependencies/glew/glew.h"
#include "../Dependencies/freeglut/freeglut.h"
#include <fstream>
#include <iostream>
#include <string>
#include "BMPHeaders.h"

namespace Rendering {
	class TextureLoader {
	public:
		TextureLoader();
		~TextureLoader();

		unsigned int LoadTexture(const std::string& filename, unsigned int width, unsigned int height);
	
	private:
		void LoadBMP(const std::string& filename, unsigned int& width, unsigned int& height, unsigned char*& data);

	};
}