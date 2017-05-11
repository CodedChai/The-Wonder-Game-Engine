#include "Init_GLUT.h"

using namespace Core::Init;
Core::IListener* Init_GLUT::listener = NULL;
Core::WindowInfo Init_GLUT::windowInformation;


void Init_GLUT::init(const Core::WindowInfo& windowInfo, const Core::ContextInfo& contextInfo, const Core::FrameBufferInfo& frameBufferInfo)
{
	windowInformation = windowInfo;
	int fakeargc = 1;
	char *fakeargv[] = { "fake", NULL };
	glutInit(&fakeargc, fakeargv);

	if (contextInfo.core) {
		glutInitContextVersion(contextInfo.major_version, contextInfo.minor_version);
		glutInitContextProfile(GLUT_CORE_PROFILE);
	}
	else {
		glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
	}

	glutInitDisplayMode(frameBufferInfo.flags);
	glutInitWindowPosition(windowInfo.x_pos, windowInfo.y_pos);
	glutInitWindowSize(windowInfo.width, windowInfo.height);
	glutCreateWindow(windowInfo.name.c_str());

	std::cout << "GLUT:initialized" << std::endl;
	glEnable(GL_DEBUG_OUTPUT);
	Core::Init::Init_GLEW::Init();
	glDebugMessageCallback(DebugOutput::callB, NULL);
	glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, NULL, GL_TRUE);
	glEnable(GL_DEBUG_OUTPUT);
	glutIdleFunc(idleCallback);
	glutCloseFunc(closeCallback);
	glutDisplayFunc(displayCallback);
	glutReshapeFunc(reshapeCallback);

	

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	printOpenGLInfo(windowInfo, contextInfo);

}
/*
void processNormalKeys(unsigned char key, int x, int y) {

	if(key == 'w')
		std::cout << "New Frame";

	if (key == 27)
		exit(0);
}*/
void Init_GLUT::run() {
	std::cout << "GLUT:\t Start Running " << std::endl;
	//glutKeyboardFunc(processNormalKeys);
	glutMainLoop();
}

void Init_GLUT::close() {
	std::cout << "GLUT:\t Finished" << std::endl;
	glutLeaveMainLoop();
}

void Init_GLUT::idleCallback(void) {
	glutPostRedisplay();
}

void Init_GLUT::displayCallback() {
	if (listener) {
		listener->notifyBeginFrame();
		listener->notifyDisplayFrame();
		glutSwapBuffers();
		listener->notifyEndFrame();
	}
	/*glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1);
	glutSwapBuffers();*/
}

void Init_GLUT::reshapeCallback(int width, int height) {
	if (windowInformation.isReshapable) {
		if (listener) {
			listener->notifyReshape(width, height, windowInformation.width, windowInformation.height);
		}
		windowInformation.width = width;
		windowInformation.height = height;
	}
}

void Init_GLUT::setListener(Core::IListener*& iListener) {
	listener = iListener;
}

void Init_GLUT::closeCallback() {
	close();
}

void Init_GLUT::enterFullScreen() {
	glutFullScreen();
}

void Init_GLUT::exitFullScreen() {
	glutLeaveFullScreen();
}

void Init_GLUT::printOpenGLInfo(const Core::WindowInfo& windowInfo, const Core::ContextInfo& contextInfo) {
	const unsigned char* renderer = glGetString(GL_RENDERER);
	const unsigned char* vendor = glGetString(GL_VENDOR);
	const unsigned char* version = glGetString(GL_VERSION);

	std::cout << "~~~~~~~~~~~~~~";
	std::cout << "GLUT:Initialize" << std::endl;
	std::cout << "GLUT:\tVendor : " << vendor << std::endl;
	std::cout << "GLUT:\tRenderer : " << renderer << std::endl;
	std::cout << "GLUT:\tOpenGL ver: " << version << std::endl;
}