#include "TextureLoader.h"
#include <string>
using namespace Rendering;
using namespace std;

TextureLoader::TextureLoader() {

}

TextureLoader::~TextureLoader() {

}

unsigned int TextureLoader::LoadTexture(const std::string& filename, unsigned int width, unsigned int height) {
	unsigned char* data;
	LoadBMP(filename, width, height, data);

	unsigned int gl_texture_obj;
	glGenTextures(1, &gl_texture_obj);
	glBindTexture(GL_TEXTURE_2D, gl_texture_obj);


	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

	std::cout << "Here?" << endl;

	std::cout << "THere?" << endl;

	
	float maxAnisotropy;
	glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &maxAnisotropy);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, maxAnisotropy);


	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

	delete data;

	glGenerateMipmap(GL_TEXTURE_2D);

	std::cout << "Texture Loaded" << gl_texture_obj << endl;

	return gl_texture_obj;
}

void TextureLoader::LoadBMP(const std::string& filename, unsigned int& width, unsigned int& height, unsigned char*& data) {
	std::ifstream file(filename.c_str(), std::ios::in | std::ios::binary);
	if (!file.good()) {
		std::cout << "Cannot open texture file." << endl;
		width = 0;
		height = 0;
		return;
	}
	else {
		std::cout << "Texture file located" << endl;
	}

	Texture::BMP_Header h; Texture::BMP_Header_Info h_info;
	file.read((char*)&(h.type[0]), sizeof(char));
	file.read((char*)&(h.type[1]), sizeof(char));
	file.read((char*)&(h.f_lenght), sizeof(int));
	file.read((char*)&(h.rezerved1), sizeof(short));
	file.read((char*)&(h.rezerved2), sizeof(short));
	file.read((char*)&(h.offBits), sizeof(int));
	file.read((char*)&(h_info), sizeof(Texture::BMP_Header_Info));

	data = new unsigned char[h_info.width*h_info.height * 3];

	long padd = 0;
	if ((h_info.width * 3) % 4 != 0) {
		padd = 4 - (h_info.width * 3) % 4;
	}
	width = h_info.width;
	height = h_info.height;

	long pointer;
	unsigned char r, g, b;

	for (unsigned int i = 0; i < height; i++) {
		for (unsigned int j = 0; j < width; j++) {
			file.read((char*)&b, 1);
			file.read((char*)&g, 1);
			file.read((char*)&r, 1);

			pointer = (i * width + j) * 3;
			data[pointer] = r;
			data[pointer + 1] = g;
			data[pointer + 2] = b;
		}
		file.seekg(padd, std::ios_base::cur);
	}
	file.close();
	std::cout << "BMP loaded" << endl;
}