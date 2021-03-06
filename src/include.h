/*
Copyright (c) 2012-2014 The SSDB Authors. All rights reserved.
Use of this source code is governed by a BSD-style license that can be
found in the LICENSE file.
*/
#ifndef SSDB_INCLUDE_H_
#define SSDB_INCLUDE_H_

#include <inttypes.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <string.h>
#include <math.h>
#include <fcntl.h>
#include <assert.h>
#include <signal.h>
#include <time.h>
#if SSDB_PLATFORM_WINDOWS
#include "util/platform_win.h"
#define sleep(x)	_sleep( (x)*1000 )
#define usleep(x)	_sleep( (x)/1000 );

#else
#include <sys/time.h>
#endif
#include <sys/types.h>
#include <sys/stat.h>

#include "version.h"

#ifndef UINT64_MAX
	#define UINT64_MAX		18446744073709551615ULL
#endif
#ifndef INT64_MAX
	#define INT64_MAX		0x7fffffffffffffffLL
#endif


static inline double millitime(){
	struct timeval now;
	gettimeofday(&now, NULL);
	double ret = now.tv_sec + now.tv_usec/1000.0/1000.0;
	return ret;
}

static inline int64_t time_ms(){
	struct timeval now;
	gettimeofday(&now, NULL);
	return int64_t(now.tv_sec) * 1000 + int64_t(now.tv_usec)/1000;
}


#endif

