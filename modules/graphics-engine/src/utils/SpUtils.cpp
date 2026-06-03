//
// Created by robsc on 2/5/26.
//

#include "SpUtils.h"

void SpUtils::PrintConsole(const SP_GL_SEVERITY severity, const String& Message) {
	String ConsoleMessage;
	switch (severity) {
		case SP_GL_SEVERITY::SP_INFO:
			ConsoleMessage = "[INFO] ";
			ConsoleMessage.append(Message + "\n");
			std::printf("%s", ConsoleMessage.c_str());
			break;

		case SP_GL_SEVERITY::SP_WARNING:
			ConsoleMessage = "[WARNING] ";
			ConsoleMessage.append(Message + "\n");
			std::printf("%s", ConsoleMessage.c_str());
			break;

		case SP_GL_SEVERITY::SP_ERROR:
			ConsoleMessage = "[ERROR] ";
			ConsoleMessage.append(Message + "\n");
			std::printf("%s", ConsoleMessage.c_str());
			break;

		case SP_GL_SEVERITY::SP_FATAL:
			ConsoleMessage = "[FATAL] ";
			ConsoleMessage.append(Message + "\n");
			std::printf("%s", ConsoleMessage.c_str());
			break;
	}
}

void SpUtils::ResultCheck(int result, std::string Error, std::string Success) {

}

void SpUtils::ResultCheck(int result, std::string Error) {

}

void SpUtils::ExitCheck(bool result, const String& Error, SP_GL_RESULT ExitError, const String& Success) {
	if (result) {
		String ConsoleMessage = "[FATAL] ";
		ConsoleMessage.append(Error + "\n");

		std::printf("%s", ConsoleMessage.c_str());
		std::exit(ExitError);
	}
	if (Success.length() > 0) {
		PrintConsole(SP_INFO, Success);
	}
}

void SpUtils::Exit(const String& Error, SP_GL_RESULT ExitError) {
	String ConsoleMessage = "[FATAL] ";
	ConsoleMessage.append(Error + "\n");

	std::printf("%s", ConsoleMessage.c_str());
	std::exit(ExitError);
}

void SpUtils::GLFWErrorCallback(int error, const char* description) {
	String ConsoleMessage = "[FATAL] [GLFW] ";
	ConsoleMessage.append(description);

	std::printf("%s", ConsoleMessage.c_str());
	std::exit(error);
}
