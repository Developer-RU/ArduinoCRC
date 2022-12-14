#include <ArduinoCRC.h>


//namespace TLV_Protocol
//{

	/**
	 * @brief 
	 * 
	 */
	void Crc::start() 
	{
		crc = 0xFF;
	}

	/**
	 * @brief 
	 * 
	 * @param b 
	 */
	void Crc::add(uint8_t b) 
	{
		crc += b;
	}

	/**
	 * @brief 
	 * 
	 * @param data 
	 * @param dataLen 
	 */
	void Crc::add(uint8_t data[], uint16_t dataLen) 
	{
		for(uint16_t i = 0; i < dataLen; i++) 
		{
			add(data[i]);
		}
	}

	/**
	 * @brief 
	 * 
	 * @return uint8_t 
	 */
	uint8_t Crc::get() 
	{
		return crc;
	}

//}