#ifndef VertexFormat_H_
#define VertexFormat_H_
#include "glm/glm.hpp"
//#include "../math_lib/math_funcs.h"

//using namespace math_lib;
namespace Rendering {

	struct VertexFormat {
		glm::vec3 position;
		glm::vec4 color;
		glm::vec2 texture;

		VertexFormat(const glm::vec3 &iPos, const glm::vec4 &iColor) {
			position = iPos;
			color = iColor;
		}

		VertexFormat(const glm::vec3 &iPos, const glm::vec2 &iTexture) {
			position = iPos;
			texture = iTexture;
			color.r = 0;
			color.g = 0;
			color.b = 0;
			color.a = 0;
		}
	};
}
/*struct VertexFormat {
	math_lib::Vector3<double> position;

	VertexFormat(const math_lib::Vector3<double> &pos) {
		position = pos;
	}
};*/

#endif
