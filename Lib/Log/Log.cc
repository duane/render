#include <Log/Log.h>

static sem_t *__logLock;
static FILE *__logOutput;

void Log(char *msg) {
    sem_wait(__logLock);
    // first, calculate the time.
    char preamble[13] = ""; // "[HH:MM:SS]: \0"
    time_t theTime;
    time_t tstatus = time(&theTime);
    if (tstatus != (time_t)-1) {
        struct tm *tStruct = localtime(&theTime);
        if (tStruct) {
            snprintf(preamble, sizeof(preamble),"[%0d:%0d:%0d]: ", tStruct->tm_hour, tStruct->tm_min, tStruct->tm_sec);
            fputs(preamble, __logOutput);
        }
    }
    fputs(msg, __logOutput);
    fputs("\n", __logOutput);
    sem_post(__logLock);
}

void LogError(const char *error) {
    char msg[4096] = "Error: ";
    strncat(msg, error, LOG_LINE_SIZE);
    Log(msg);
} 

void LoggerInit(FILE *logStream) {
    __logOutput = logStream;
    __logLock = sem_open(LOG_SEMAPHORE_NAME, O_CREAT, 0644, 1);
    if (!__logLock) {
        fprintf(__logOutput, "%d\n", errno);
        fputs("Unable to initialize logger semaphore.\n", __logOutput);
        exit(1);
    }
}