/* u8g2_d_setup.c */
/* generated code, codebuild, u8g2 project */

#include "u8g2.h"
#include "tim.h"
#include "i2c.h"
extern uint8_t u8g2_stm32_delay(U8X8_UNUSED u8x8_t *u8x8, U8X8_UNUSED uint8_t msg, U8X8_UNUSED uint8_t arg_int, U8X8_UNUSED void *arg_ptr);
/* ssd1306 f */
void u8g2_Setup_ssd1306_i2c_128x64_noname_f(u8g2_t *u8g2, const u8g2_cb_t *rotation, u8x8_msg_cb byte_cb, u8x8_msg_cb gpio_and_delay_cb)
{
  uint8_t tile_buf_height;
  uint8_t *buf;
  u8g2_SetupDisplay(u8g2, u8x8_d_ssd1306_128x64_noname, u8x8_cad_ssd13xx_fast_i2c, byte_cb, gpio_and_delay_cb);
  buf = u8g2_m_16_8_f(&tile_buf_height);
  u8g2_SetupBuffer(u8g2, buf, tile_buf_height, u8g2_ll_hvline_vertical_top_lsb, rotation);
}
uint8_t u8g2_stm32_delay(U8X8_UNUSED u8x8_t *u8x8, U8X8_UNUSED uint8_t msg, U8X8_UNUSED uint8_t arg_int, U8X8_UNUSED void *arg_ptr)
{
	switch(msg){
		
	case U8X8_MSG_GPIO_AND_DELAY_INIT:
	    break;
		
	case U8X8_MSG_DELAY_MILLI:
		HAL_Delay(arg_int);//change it!
	    break;
		
	default:	
		return 0;
	}
	return 1; // command processed successfully.
}
//uint8_t u8x8_byte_hw_i2c(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr)
//{
//  static uint8_t buffer[32];		/* u8g2/u8x8 will never send more than 32 bytes between START_TRANSFER and END_TRANSFER */
//  static uint8_t buf_idx;
//  uint8_t *data;
// 
//  switch(msg)
//  {
//    case U8X8_MSG_BYTE_SEND:
//      data = (uint8_t *)arg_ptr;      
//      while( arg_int > 0 )
//      {
//	        buffer[buf_idx++] = *data;
//	        data++;
//	        arg_int--;
//      }      
//      break;
//    case U8X8_MSG_BYTE_INIT:
//      /* add your custom code to init i2c subsystem */
//      break;
//    case U8X8_MSG_BYTE_SET_DC:
//      /* ignored for i2c */
//      break;
//    case U8X8_MSG_BYTE_START_TRANSFER:
//      buf_idx = 0;
//      break;
//    case U8X8_MSG_BYTE_END_TRANSFER:
//      HAL_I2C_Master_Transmit(&hi2c1,u8x8_GetI2CAddress(u8x8), buffer, buf_idx,0x100);//change it
//      break;
//    default:
//      return 0;
//  }
//  return 1;
//}
/* end of generated code */
  