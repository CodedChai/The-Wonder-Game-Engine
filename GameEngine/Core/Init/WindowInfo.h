#pragma once
#include <string>

namespace Core {
	struct WindowInfo {
		std::string name;
		int width, height;
		int x_pos, y_pos;
		bool isReshapable;

		WindowInfo() {
			name = "William's Game Engine";
			width = 800;
			height = 600;
			x_pos = 300;
			y_pos = 300;
			isReshapable = true;
		}

		WindowInfo(std::string name, int start_pos_x, int start_pos_y, int width, int height, bool is_reshapable) {
			this->name = name;
			this->x_pos = start_pos_x;
			this->y_pos = start_pos_y;
			this->width = width;
			this->height = height;
			this->isReshapable = is_reshapable;
		}

		WindowInfo(const WindowInfo& wI) {
			name = wI.name;
			x_pos = wI.x_pos;
			y_pos = wI.y_pos;
			width = wI.width;
			height = wI.height;
			isReshapable = wI.isReshapable;
		}

		void operator=(const WindowInfo& wI) {
			name = wI.name;
			x_pos = wI.x_pos;
			y_pos = wI.y_pos;
			width = wI.width;
			height = wI.height;
			isReshapable = wI.isReshapable;
		}
	};

}