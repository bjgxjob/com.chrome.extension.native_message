/*
 * FILE_LOG.h
 *
 *  Created on: 2012-7-26
 *      Author: Administrator
 */

#ifndef FILE_LOG_H_
#define FILE_LOG_H_

#include "common.h"

#define FILE_LOG_TO_FILE 1

#if defined(_WINDOWS) || defined(WIN32)

#define file_log_name "D:\\LOG.TXT"
#define file_path "D:/"

#else

#ifdef ANDROID
#define file_log_name "/sdcard/LOG.TXT"
#define file_path "/sdcard/"
#else
#define file_log_name "/home/LOG.TXT"
#define file_path "/home/"
#endif

#endif

#ifdef __cplusplus
extern "C" {
#endif
    COMMON_API void FILE_LOG_STRING(const char * fileName,const char * cstring);
    COMMON_API void FILE_LOG_HEX(const char * fileName, const unsigned char * byte, unsigned long length);
    COMMON_API void FILE_LOG_NUMBER(const char * fileName,long number);
	COMMON_API void FILE_LOG_BYTE(const char * fileName, const unsigned char * byte, unsigned long length);
	COMMON_API void FILE_LOG_FMT(const char * fileName,const char *format,...);
	COMMON_API void FILE_READ(const char * dir, const char * fileName, unsigned char * byte, unsigned long * length);
	COMMON_API void FILE_WRITE(const char * dir, const char * fileName, const unsigned char * byte, unsigned long length);
#ifdef __cplusplus
}
#endif

#endif /* FILE_LOG_H_ */
