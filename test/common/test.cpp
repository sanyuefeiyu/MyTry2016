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

    DLog(DLOG_D, TAG, "TestMD5 1");
    for (size_t i = 0; i < len; i++)
    {
        dst[16] = '\0';
        DMD5Sum(dst, src, i+1);
        DLog(DLOG_D, TAG, "i=%02d, enc=%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%2x%02x%02x",
            i, dst[0], dst[1], dst[2], dst[3], dst[4], dst[5], dst[6], dst[7], 
            dst[8], dst[9], dst[10], dst[11], dst[12], dst[13], dst[14], dst[15]);
    }

    DLog(DLOG_D, TAG, "TestMD5 2");
    unsigned char dst2[17];
    DMD5Ctx* ctx = DMD5InitCtx();
    DMD5SumCtx(ctx, src, len);
    DMD5CloseCtx(ctx, dst2);
    DMD5ReleaseCtx(&ctx);
    DLog(DLOG_D, TAG, "enc=%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%2x%02x%02x",
        dst2[0], dst2[1], dst2[2], dst2[3], dst2[4], dst2[5], dst2[6], dst2[7], 
        dst2[8], dst2[9], dst2[10], dst2[11], dst2[12], dst2[13], dst2[14], dst2[15]);

    DLog(DLOG_D, TAG, "TestMD5 3");
    unsigned char dst3[17];
    DMD5SumFile(dst3, "d:\\qyz16.mp4");
    DLog(DLOG_D, TAG, "enc=%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%2x%02x%02x",
        dst3[0], dst3[1], dst3[2], dst3[3], dst3[4], dst3[5], dst3[6], dst3[7], 
        dst3[8], dst3[9], dst3[10], dst3[11], dst3[12], dst3[13], dst3[14], dst3[15]);
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
