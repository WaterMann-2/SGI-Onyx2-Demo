//
// Created by robsc on 2/5/26.
//

#ifndef SILICONGRAPHICS_UTILS_H
#define SILICONGRAPHICS_UTILS_H

#define GLFW_INCLUDE_NONE
#include "../glad/glad.h"
#include <GLFW/glfw3.h>

#include <cstdint>
#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <string>
#include <chrono>


typedef std::int8_t int8;
typedef std::uint8_t uint8;
typedef std::int16_t int16;
typedef std::uint16_t uint16;
typedef std::int32_t int32;
typedef std::uint32_t uint32;

typedef std::string String;

enum SP_GL_RESULT {
	SP_SUCCESS,
	SP_FAIL,
	SP_GL_FAIL,
	SP_GLFW_FAIL
};

enum SP_GL_SEVERITY {
	SP_INFO,
	SP_WARNING,
	SP_ERROR,
	SP_FATAL
};

class SpUtils {
public:
	static void PrintConsole(SP_GL_SEVERITY severity, const String& Message);

	static void ResultCheck(int result, std::string Error, std::string Success);
	static void ResultCheck(int result, std::string Error);
	static void ExitCheck(bool result, const String& Error, SP_GL_RESULT ExitError, const String& Success = "");
	static void Exit(const String& Error, SP_GL_RESULT ExitError);

	static void GLFWErrorCallback(int error, const char* description);

};


#endif //SILICONGRAPHICS_UTILS_H