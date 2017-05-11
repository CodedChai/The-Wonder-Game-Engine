#pragma once
#include <iostream>
#include "../../Dependencies/glew/glew.h"
#include "../../Dependencies/freeglut/freeglut.h"
#include "../../Dependencies/irrklang/irrKlang.h"
namespace Core {
	namespace Init {
		class Init_GLEW {
		public:
			static void Init();
		};
	}
}