#include "Models_Manager.h"
#include <iostream>
#include <string>

using namespace std;
using namespace Managers;
using namespace Rendering;

Models_Manager::Models_Manager() {

	Models::TexturedCube* cube = new Models::TexturedCube();
	cube->SetProgram(Shader_Manager::GetShader("tcubeShader"));
	cube->Create();
	m_texture_loader = new Rendering::TextureLoader();
	cout << "Cube Created" << endl;
	unsigned int texture = m_texture_loader->LoadTexture("Textures\\tiles.bmp", 256, 256);
	cout << texture << endl;
	cube->SetTexture("Create", texture);
	gameModelList["tcube"] = cube;

}

Models_Manager::~Models_Manager() {
	for (auto model : gameModelList) {
		delete model.second;
	}
	gameModelList.clear();
}

void Models_Manager::DeleteModel(const std::string& gameModelName) {
	IGameObject* model = gameModelList[gameModelName];
	model->Destroy();
	gameModelList.erase(gameModelName);

}

const IGameObject& Models_Manager::GetModel(const std::string& gameModelName) const {
	return (*gameModelList.at(gameModelName));
}

void Models_Manager::Update() {
	for (auto model : gameModelList) {
		model.second->Update();
	}
}
void Models_Manager::Draw() {
	for (auto model : gameModelList) {
		model.second->Draw();
	}
}

void Models_Manager::Draw(const glm::mat4& proj_mat, const glm::mat4& view_mat) {
	for (auto model : gameModelList) {
		model.second->Draw(proj_mat, view_mat);
	}
}