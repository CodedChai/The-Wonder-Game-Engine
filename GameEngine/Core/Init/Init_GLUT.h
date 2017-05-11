#pragma once
#include "ContextInfo.h"
#include "FrameBufferInfo.h"
#include "WindowInfo.h"
#include <iostream>
#include "Init_GLEW.h"
#include "IListener.h"
#include "DebugOutput.h"


namespace Core {
	namespace Init {
		class Init_GLUT {
		public:
			static void init(const Core::WindowInfo& window, const Core::ContextInfo& context, const Core::FrameBufferInfo& frameBufferInfo);

		public:
			static void run();
			static void close();
			void enterFullScreen();
			void exitFullScreen();
			static void setListener(Core::IListener*& iListener);
			static void printOpenGLInfo(const Core::WindowInfo& windowInfo, const Core::ContextInfo& context);

		private:
			static void idleCallback(void);
			static void displayCallback(void);
			static void reshapeCallback(int width, int height);
			static void closeCallback();
			static Core::IListener* listener;
			static Core::WindowInfo windowInformation;
		};
	}
}