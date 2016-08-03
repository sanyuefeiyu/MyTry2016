/*
 * @author Double
 * @since 2016/04/17
 */

#ifndef D_LOG_H
#define D_LOG_H

#include "DExport.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum DLogLevel
{
	DLOG_DEBUG = 0,
	DLOG_WARN,
	DLOG_ERROR
} DLogLevel;

DEXPORT void DLog(DLogLevel level, const char* tag, const char* format, ...);

#ifdef __cplusplus
}
#endif

#endif /* D_LOG_H */
