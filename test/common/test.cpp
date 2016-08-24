#include <stdio.h>
#include <string.h>
#include "DLog.h"
#include "DTime.h"
#include "DFile.h"
#include "DMD5.h"

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

void TestMD5()
{
    unsigned char dst[17];
    unsigned char src[128] = "hello world";
    unsigned int len = strlen((char*)src);

    for (size_t i = 0; i < len; i++)
    {
        dst[16] = '\0';
        DMD5Sum(dst, src, i+1);
        DLog(DLOG_D, TAG, "i=%02d, enc=%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%2x%02x%02x",
            i, dst[0], dst[1], dst[2], dst[3], dst[4], dst[5], dst[6], dst[7], 
            dst[8], dst[9], dst[10], dst[11], dst[12], dst[13], dst[14], dst[15]);
    }
}

extern "C" void myTest()
{
    DLog(DLOG_D, TAG, "myTest begin");

    TestLog();
    TestTime();
    TestFile();
    TestMD5();

    DLog(DLOG_D, TAG, "myTest end");
}
