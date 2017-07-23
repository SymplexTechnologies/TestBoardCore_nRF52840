

#include "MyComponents.h"


#ifdef __cplusplus
extern "C" {
#endif



application_t m_app =
{
    .p_ot_instance = NULL,
};



void state_changed_callback(uint32_t flags, void * p_context)
{
    //NRF_LOG_INFO("State changed! Flags: 0x%08x Current role: %d\r\n",
    //             flags, otThreadGetDeviceRole((otInstance *)p_context));
}



void thread_init(void)
{
    otInstance *p_instance;

    PlatformInit(0, NULL);

    p_instance = otInstanceInit();
    assert(p_instance);

    otCliUartInit(p_instance);

    //NRF_LOG_INFO("Thread version: %s\r\n", (uint32_t)otGetVersionString());
    //NRF_LOG_INFO("Network name:   %s\r\n", (uint32_t)otThreadGetNetworkName(p_instance));

    assert(otSetStateChangedCallback(p_instance, &state_changed_callback, p_instance) == OT_ERROR_NONE);

    m_app.p_ot_instance = p_instance;
}


void timer_init(void)
{
    uint32_t err_code = app_timer_init();
    APP_ERROR_CHECK(err_code);
}


void leds_init(void)
{
    NRF_P0->PIN_CNF[13] = (GPIO_PIN_CNF_SENSE_Disabled << GPIO_PIN_CNF_SENSE_Pos)
                                            | (GPIO_PIN_CNF_DRIVE_S0S1 << GPIO_PIN_CNF_DRIVE_Pos)
                                            | (GPIO_PIN_CNF_PULL_Disabled << GPIO_PIN_CNF_PULL_Pos)
                                            | (GPIO_PIN_CNF_INPUT_Connect << GPIO_PIN_CNF_INPUT_Pos)
                                            | (GPIO_PIN_CNF_DIR_Output << GPIO_PIN_CNF_DIR_Pos);
	NRF_P0->OUTSET = (1UL << 13);
}


void thread_bsp_init(void)
{
    uint32_t err_code;
    err_code = bsp_init(BSP_INIT_LED, NULL);
    APP_ERROR_CHECK(err_code);

    err_code = bsp_thread_init(m_app.p_ot_instance);
    APP_ERROR_CHECK(err_code);
}


#ifdef __cplusplus
}
#endif

