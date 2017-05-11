#pragma once
#include "Model.h"
#include <time.h>
#include <stdarg.h>
namespace Rendering {
	namespace Models {
		class TexturedCube : public Model {
		public:
			TexturedCube();
			~TexturedCube();

			void Create();
			virtual void Draw(const glm::mat4& proj_mat, const glm::mat4& view_mat) override final;
			virtual void Update() override final;

		private:
			glm::vec3 rotation, rotation_speed, rotation_sin;
			time_t timer;
		};
	}
}