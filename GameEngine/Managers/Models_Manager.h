#pragma once
#include <map>
#include "Shader_Manager.h"
#include "../Rendering/TextureLoader.h"
#include "../Rendering/IGameObject.h"
#include "../Rendering/Models/Triangle.h"
#include "../Rendering/Models/Quad.h"
#include "../Rendering/Models/Cube.h"
#include "../Rendering/Models/TexturedCube.h"

using namespace Rendering;
namespace Managers {
	class Models_Manager {
	public:
		Models_Manager();
		~Models_Manager();

		void Draw();
		void Draw(const glm::mat4& proj_mat, const glm::mat4& view_mat);
		void Update();
		void DeleteModel(const std::string& gameModelName);
		const IGameObject& GetModel(const std::string& gameModelName) const;
		
	private:
		std::map<std::string, IGameObject*> gameModelList;
		Rendering::TextureLoader* m_texture_loader;
	};
}