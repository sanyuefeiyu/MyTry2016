#include <stdio.h>
#include <stdarg.h>
#include "windows.h"
#include "../DLog.h"

#define LOG_BUF_SIZE	2048

static const char *levelStr[3] = { "Debug", "Warn", "Error" };

static void Output(DLogLevel level, const char *tag, const char *buf)
{
	char outputBuf[LOG_BUF_SIZE];

	//get date time
	SYSTEMTIME	lt;
	GetLocalTime(&lt);

	//date time pid threadid level tag	msg
	sprintf_s(outputBuf, LOG_BUF_SIZE, "[%04d/%02d/%02d|%02d:%02d:%02d:%03d|%d|%d|%s] %s %s \r\n",
				lt.wYear, lt.wMonth, lt.wDay, lt.wHour, lt.wMinute, lt.wSecond, lt.wMilliseconds,
                GetCurrentProcessId(),
				GetCurrentThreadId(),
				levelStr[level],
				tag,
				buf);

	OutputDebugString(outputBuf);
}

void DLog(DLogLevel level, const char* tag, const char* format, ...)
{
	char buf[LOG_BUF_SIZE];

	va_list ap;
	va_start(ap, format);
	vsnprintf_s(buf, LOG_BUF_SIZE, format, ap);
	va_end(ap);

	Output(level, tag, buf);
}
