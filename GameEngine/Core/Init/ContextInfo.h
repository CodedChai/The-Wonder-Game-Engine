#pragma once
namespace Core {
	struct ContextInfo {
		int major_version, minor_version;
		bool core;

		ContextInfo() {
			major_version = 3;
			minor_version = 3;
			core = true;
		}

		ContextInfo(int maj, int min, bool core) {
			this->major_version = maj;
			this->minor_version = min;
			this->core = core;
		}
	};
}