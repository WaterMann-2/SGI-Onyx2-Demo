//
// Created by robsc on 2/5/26.
//

#include "SpUtils.h"

void SpUtils::PrintConsole(const SP_GL_SEVERITY severity, const String& Message) {
	String ConsoleMessage;
	switch (severity) {
		case SP_GL_SEVERITY::SP_INFO:
			ConsoleMessage = "[INFO] ";
			ConsoleMessage.append(Message);
			ConsoleMessage = ConsoleMessage + "\n";
			std::printf(ConsoleMessage.c_str());
			break;

		case SP_GL_SEVERITY::SP_WARNING:
			ConsoleMessage = "[WARNING] ";
			ConsoleMessage.append(Message);
			ConsoleMessage = ConsoleMessage + "\n";
			std::printf(ConsoleMessage.c_str());
			break;

		case SP_GL_SEVERITY::SP_ERROR:
			ConsoleMessage = "[ERROR] ";
			ConsoleMessage.append(Message);
			ConsoleMessage = ConsoleMessage + "\n";
			std::printf(ConsoleMessage.c_str());
			break;

		case SP_GL_SEVERITY::SP_FATAL:
			ConsoleMessage = "[FATAL] ";
			ConsoleMessage.append(Message);
			ConsoleMessage = ConsoleMessage + "\n";
			std::printf(ConsoleMessage.c_str());
			break;
	}
}

void SpUtils::ResultCheck(int result, std::string Error, std::string Success) {

}

void SpUtils::ResultCheck(int result, std::string Error) {

}

void SpUtils::ExitCheck(const int result, const String& Error, const SP_GL_RESULT ExitError, const String* pSuccess) {
	if (result) {
		PrintConsole(SP_FATAL, Error);
		std::exit(ExitError);
	}
	if (pSuccess != nullptr) {
		PrintConsole(SP_INFO, *pSuccess);
	}
}
