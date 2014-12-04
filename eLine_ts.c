#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/fcntl.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/time.h>

#include "tslib.h"


int main()
{
	struct tsdev *ts;
	char *tsdevice=NULL;

        if( (tsdevice = getenv("TSLIB_TSDEVICE")) != NULL ) {
                ts = ts_open(tsdevice,0);
        } else {
#ifdef USE_INPUT_API
                ts = ts_open("/dev/input/event0", 0);
#else
                ts = ts_open("/dev/touchscreen/ucb1x00", 0);
#endif /* USE_INPUT_API */
        }

	if (!ts) {
		perror("ts_open");
		exit(1);
	}

	if (ts_config(ts)) {
		perror("ts_config");
		exit(1);
	}

	while (1) {
		struct ts_sample samp;
		int ret;

		ret = ts_read(ts, &samp, 1);

		if (ret < 0) {
			perror("ts_read");
			exit(1);
		}

		if (ret != 1)
			continue;

		printf("%ld.%06ld: %6d %6d %6d\n", samp.tv.tv_sec, samp.tv.tv_usec, samp.x, samp.y, samp.pressure);

	}
}
