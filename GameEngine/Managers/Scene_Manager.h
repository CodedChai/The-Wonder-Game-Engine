#pragma once
#include "Shader_Manager.h"
#include "Models_Manager.h"
#include "../Core/Init/IListener.h"
#include <glm\glm.hpp>
#include "..\Core\Camera.h"

namespace Managers {
	class Scene_Manager : public Core::IListener {
	public:
		Scene_Manager();
		~Scene_Manager();

		virtual void notifyBeginFrame();
		virtual void notifyDisplayFrame();
		virtual void notifyEndFrame();
		virtual void notifyReshape(int width, int height, int previous_width, int previous_height);
		virtual void Move();

	private:
		Managers::Shader_Manager* shader_manager;
		Managers::Models_Manager* models_manager;
		Camera* cam;
		char keyPressed;
		glm::mat4 proj_mat;
		glm::mat4 view_mat;
		glm::vec3 eye_pos;
	};
}