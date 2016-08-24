/*
 * @author Double
 * @since 2016/08/25
 */

#ifndef D_MD5_H
#define D_MD5_H

#include "DExport.h"

#ifdef __cplusplus
extern "C" {
#endif

DEXPORT unsigned char* DMD5Sum(unsigned char *dst, const unsigned char *src, const int len);

#ifdef __cplusplus
}
#endif

#endif /* D_MD5_H */
