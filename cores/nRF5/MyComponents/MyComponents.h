

#ifndef MY_COMPONENTS__
#define MY_COMPONENTS__

#ifdef __cplusplus
extern "C" {
#endif



#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include "app_timer.h"
#include "bsp_thread.h"

#include <openthread/openthread.h>
#include <openthread/cli.h>
#include <openthread/platform/platform.h>


typedef struct
{
    otInstance * p_ot_instance;
} application_t;


void state_changed_callback(uint32_t flags, void * p_context);


void thread_init(void);


void timer_init(void);


void leds_init(void);


void thread_bsp_init(void);



#ifdef __cplusplus
}
#endif

#endif	/* MY_COMPONENTS__ */


