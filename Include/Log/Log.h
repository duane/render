#ifndef INCLUDE_LOG_LOG_H
#define INCLUDE_LOG_LOG_H

#include <errno.h>
#include <semaphore.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LOG_LINE_SIZE 4096
#define LOG_SEMAPHORE_NAME "__RENDER_LOG_LOCK__"
    
void Log(char *msg);
void LogError(const char *error);
void LoggerInit(FILE *logStream);

#endif
