#pragma once
#include <vector>
#include <map>
#include "../IGameObject.h"
namespace Rendering {
	namespace Models {
		class Model :public IGameObject {
		public:
			Model();
			virtual ~Model();
			virtual void Draw() override;
			virtual void Draw(const glm::mat4& proj_mat, const glm::mat4& view_mat);
			virtual void Update() override;
			virtual void SetProgram(GLuint shaderName) override;
			virtual void Destroy() override;
			virtual void SetTexture(std::string textureName, GLuint texture) override;
			virtual GLuint GetVao() const override;
			virtual const GLuint GetTexture(std::string textureName) const override;
			virtual const std::vector<GLuint>& GetVbos()const override;

		protected:
			GLuint vao;
			GLuint program;
			std::vector<GLuint> vbos;
			std::map<std::string, GLuint> textures;
		};
	}
}