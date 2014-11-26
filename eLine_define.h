#ifndef __ELINE_DEFINE_H__
#define __ELINE_DEFINE_H__

#include <stdio.h>

#define eLineErr(fmt, args...)\
    do {\
        printf("\n[eLine ERROR:%s,%d,%s]-> ",__FILE__,__LINE__,__FUNCTION__);\
        printf(fmt, ##args);\
        printf("\n");\
    } while(0)

#define eLineOut(fmt, args...)\
        do {\
            printf(fmt, ##args);\
        } while(0)

#endif /* #ifndef __ELINE_DEFINE_H__ */
