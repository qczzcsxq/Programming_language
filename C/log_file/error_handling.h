#pragma once
#include "types.h"
#include "logger.h"

void log_error(const char* format, ...);

void log_warnning(const char* format, ...);

void log_fatal(const char* format, ...);
