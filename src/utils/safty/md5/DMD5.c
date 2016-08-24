#include "./cifs/MD5.h"
#include "DMD5.h"

unsigned char* DMD5Sum(unsigned char *dst, const unsigned char *src, const int len)
{
    return auth_md5Sum(dst, src, len);
}
