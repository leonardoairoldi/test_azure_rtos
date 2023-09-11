#include "threadB.h"

void threadB_entry(ULONG thread_input)
{
 /* Enter into a forever loop. */
	uint16_t threadB_counter = 0;
	while(1)
	{
		/* Increment thread counter. */
		threadB_counter++;
		/* Sleep for 1 tick. */
		HAL_GPIO_TogglePin(LEDB_GPIO_Port, LEDB_Pin);
		tx_thread_sleep(1 * TX_TIMER_TICKS_PER_SECOND);
	}
}
