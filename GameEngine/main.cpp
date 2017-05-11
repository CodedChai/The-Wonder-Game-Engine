// Based off of the game engine from www.in2gpu.com/opengl 
#pragma once
#include "Core\Init\Init_GLUT.h"
#include "Managers\Scene_Manager.h"
#include "Dependencies\irrklang\irrKlang.h"

using namespace irrklang;
using namespace Core;
using namespace Init;

int main(int argc, char **argv) {
	ISoundEngine *SoundEngine = createIrrKlangDevice();
	WindowInfo window(std::string("Wonder Engine"), 100, 100, 1280, 720, true);
	ContextInfo context(4, 5, true);
	FrameBufferInfo frameBufferInfo(true, true, true, true);
	Init::Init_GLUT::init(window, context, frameBufferInfo);
	SoundEngine->play2D("Audio/Wonderwall.mp3", GL_TRUE);

	IListener* scene = new Managers::Scene_Manager();
	Init::Init_GLUT::setListener(scene);

	Init_GLUT::run();
	delete scene;
	return 0;
}
