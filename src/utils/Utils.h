//
// Created by robsc on 2/5/26.
//

#ifndef SILICONGRAPHICS_UTILS_H
#define SILICONGRAPHICS_UTILS_H

#include <cstdint>
#include <cstdio>
#include <stdio.h>
#include <string>


typedef std::int8_t int8;
typedef std::uint8_t uint8;
typedef std::int16_t int16;
typedef std::uint16_t uint16;
typedef std::int32_t int32;
typedef std::uint32_t uint32;

typedef std::string String;

enum SP_GL_RESULT {
	GL_SUCCESS = 0,
	GL_FAIL = 1,
	GL_SDL_ERROR = 2
};

class utils {
};


#endif //SILICONGRAPHICS_UTILS_H