#include <stdio.h>
#include <string.h>
#include "DLog.h"
#include "DTime.h"
#include "DFile.h"

#define TAG "Main"

void TestLog()
{
    DLogFlush();

    DLogOutputMode(DLogMode(DLOG_FILE | DLOG_CONSOLE));

    DLog(DLOG_D, TAG, "TestLog begin, tick=%lld", DTimeGetTick());

    DLog(DLOG_D, TAG, "This is a debug message.");
    DLog(DLOG_I, TAG, "This is an info message.");
    DLog(DLOG_W, TAG, "This is a warning message.");
    DLog(DLOG_E, TAG, "This is an error message.");

    DLog((DLogLevel)-1, TAG, "This is min message.");
    DLog((DLogLevel)10, TAG, "This is max message.");

    DLog(DLOG_D, TAG, "TestLog end, tick=%lld", DTimeGetTick());
}

void TestTime()
{
    DLog(DLOG_D, TAG, "TestTime begin");
    DLog(DLOG_D, TAG, "TestTime end");
}

void TestFile()
{
    DLog(DLOG_D, TAG, "TestFile begin");

    const char *filePath = "d:\\testfile.xxx";
    DFileFlush(filePath);

    const char *buf = "hello world";
    char outputBuf[2048];
    snprintf(outputBuf, 2048, "%lld %s\r\n", DTimeGetTick(), buf);
    DFileWrite2Dest(filePath, outputBuf, strlen(outputBuf));

    DLog(DLOG_D, TAG, "TestFile end");
}

extern "C" void myTest()
{
    DLog(DLOG_D, TAG, "myTest begin");

    TestLog();
    TestTime();
    TestFile();

    DLog(DLOG_D, TAG, "myTest end");
}
