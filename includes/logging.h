#ifndef FIS_ID_SCHEME_LOGGING_H
#define FIS_ID_SCHEME_LOGGING_H

#include <stdio.h>

#define LOG_ERROR(fmt, ...) fprintf(stderr, "ERROR: " fmt "\n", ##__VA_ARGS__)
#define LOG_INFO(fmt, ...)  fprintf(stdout, "INFO: " fmt "\n", ##__VA_ARGS__)
#define LOG_DEBUG(fmt, ...) \
    do { if (DEBUG) fprintf(stdout, "DEBUG: " fmt "\n", ##__VA_ARGS__); } while(0)


#endif // FIS_ID_SCHEME_LOGGING_H