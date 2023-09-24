#include "threadG.h"

void threadG_entry(ULONG thread_input)
{
 /* Enter into a forever loop. */
	uint16_t threadG_counter = 0;
	while(1)
	{
		/* Increment thread counter. */
		threadG_counter++;
		/* Sleep for 1 tick. */
		HAL_GPIO_TogglePin(LEDG_GPIO_Port, LEDG_Pin);
		int ticks = HAL_GetTick();
		int* timer_address = 0xE0001004;
		int* timtick_address = 0;
		int ticks_direct = *timtick_address;
		tx_thread_sleep(1 * TX_TIMER_TICKS_PER_SECOND);
	}
}
