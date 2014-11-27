#ifndef __ELINE_DEBUG_H__
#define __ELINE_DEBUG_H__

#include <stdio.h>

/**
 * Define the level of debug information. 
 * 
 * 0: Disable debug
 * n: Enable debug with level n (n>0 && n<=5). The bigger, the more information output. 
 */
#define ELINE_DEBUG_LEVEL   (3)

#define eLineDbg1(fmt, args...)\
    do {\
        if (ELINE_DEBUG_LEVEL >= 1)\
        {\
    		printf("\n[eLine DEBUG1:%s,%d,%s]-> ",__FILE__,__LINE__,__FUNCTION__);\
    		printf(fmt, ##args);\
    		printf("\n");\
        }\
    } while(0)

#define eLineDbg(fmt, args...) eLineDbg1(fmt, ##args)

#define eLineDbg2(fmt, args...)\
    do {\
        if (ELINE_DEBUG_LEVEL >= 2)\
        {\
    		printf("\n[eLine DEBUG2:%s,%d,%s]-> ",__FILE__,__LINE__,__FUNCTION__);\
    		printf(fmt, ##args);\
    		printf("\n");\
        }\
    } while(0)

        
#define eLineDbg3(fmt, args...)\
    do {\
        if (ELINE_DEBUG_LEVEL >= 3)\
        {\
            printf("\n[eLine DEBUG3:%s,%d,%s]-> ",__FILE__,__LINE__,__FUNCTION__);\
            printf(fmt, ##args);\
            printf("\n");\
        }\
    } while(0)

        
#define eLineDbg4(fmt, args...)\
    do {\
        if (ELINE_DEBUG_LEVEL >= 4)\
        {\
            printf("\n[eLine DEBUG4:%s,%d,%s]-> ",__FILE__,__LINE__,__FUNCTION__);\
            printf(fmt, ##args);\
            printf("\n");\
        }\
    } while(0)

                
#define eLineDbg5(fmt, args...)\
    do {\
        if (ELINE_DEBUG_LEVEL >= 5)\
        {\
            printf("\n[eLine DEBUG5:%s,%d,%s]-> ",__FILE__,__LINE__,__FUNCTION__);\
            printf(fmt, ##args);\
            printf("\n");\
        }\
    } while(0)

#endif /* #ifndef __ELINE_DEBUG_H__ */
