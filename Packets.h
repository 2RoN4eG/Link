#ifndef PACKETS_H
#define PACKETS_H

struct PacketPreamble_Private
{
	///          |                 |
	///          |           |     |
	///    |     |           |     |
	/// .  |  .  |  .  |  .  |  .  |
	/// 0 127 0 255 0  63 0 191 0 255

	unsigned char Bit0 = 0;
	unsigned char Bit1 = 127;
	unsigned char Bit2 = 0;
	unsigned char Bit3 = 255;

	unsigned char Bit4 = 0;
	unsigned char Bit5 = 63;
	unsigned char Bit6 = 0;
	unsigned char Bit7 = 191;

	unsigned char Bit8 = 0;
	unsigned char Bit9 = 255;
};

/// Пакет для всех уст-в в сети
template <unsigned int DataLength, unsigned char BroadcastAddress = 0xFF>
struct __attribute__ ((packed)) BroadcastPacket
{
	/// Преамбула
	/// ...

	/// Адресс для которого назначается пакет, 8 бит
	unsigned char Address = BroadcastAddress;

	/// Type: - Request/Responce (0, b00)
	/// 	  - Request 		 (1, b01)
	///	   	  - Responce 		 (2, b10)
	///	      - Message/Error	 (3, b11)
	unsigned char Type		: 2;
	/// Версия пакета, 3 бит (0/1/2/3/4/5/)
	unsigned char Version	: 3;
	unsigned char			: 1;
	/// Устройство готово принимать/отправлять данные, 1 бит
	unsigned char Ready		: 1;
	unsigned char			: 1;
	
	/// Длинна пакета, 8 бит
	unsigned char Lenght = DataLength;

	/// Data [0 - 255 * 8) bits
	unsigned char Data [DataLength];

	/// Контрольная сумма, 8 бит
	unsigned char CheckSum8;

	unsigned char			: 2;
	/// Флаг коректной Контрольной суммы
	unsigned char Correct	: 1;
	unsigned char			: 2;
	/// Флаг коректного приема пакета
	unsigned char Received	: 1;
	unsigned char			: 2;
};

/// Пакет для/от конечного уст-ва
template <unsigned int DataLength>
struct __attribute__ ((packed)) UnicastPacket
{
	/// Преамбула
	/// ...

	/// Адресс для которого назначается пакет, 8 бит
	unsigned char Address;

	/// Type: - Request/Responce (0, b00)
	/// 	  - Request 		 (1, b01)
	///	   	  - Responce 		 (2, b10)
	///	      - Message/Error	 (3, b11)
	unsigned char Type		: 2;
	/// Версия пакета, 3 бит (0/1/2/3/4/5/)
	unsigned char Version	: 3;
	unsigned char			: 1;
	/// Устройство готово принимать/отправлять данные, 1 бит
	unsigned char Ready		: 1;
	unsigned char			: 1;

	/// Длинна пакета, 8 бит
	unsigned char Lenght = DataLength;

	/// Data [0 - 255 * 8) bits
	unsigned char Data [DataLength];

	/// Контрольная сумма
	unsigned char CheckSum8;

	unsigned char			: 2;
	/// Флаг коректной Контрольной суммы
	unsigned char Correct	: 1;
	unsigned char			: 2;
	/// Флаг коректного приема пакета
	unsigned char Received	: 1;
	unsigned char			: 2;
};

/// Описание Type 0 (b00) - Request/Responce

/// Устройство с адрессом 0x10 выставляет на шину следующие данные:
/// 0xF1		- unsigned char Address;
/// 0x0			- unsigned char Type		: 2;
/// 0x0			- unsigned char Version		: 3;
/// 0x0			- unsigned char				: 1;

/// Если в сети присутствует устройство с адрессом 0xF1 и оно готово, то
/// устройство выставляет на шину следующие данные:
/// 0x1			- unsigned char Ready		: 1;
/// 0x0  		- unsigned char				: 1;
/// 0x00 - 0xFF	- unsigned char Lenght;
/// ...  - .... - unsigned char Data [Length];

/// Устройство с адрессом 0x10 выставляет на шину следующие данные:
/// 0x0			- unsigned char				: 2;
/// Если контрольная сумма корректна
/// 0x1			- unsigned char Correct		: 1;
/// Иначе (контрольная сумма не корректна)
/// 0x0			- unsigned char Correct		: 1;
/// 0x0			- unsigned char				: 2;
/// Если пакет принят устройством с адрессом 0x10
/// 0x1			- unsigned char Received	: 1;
/// Иначе (пакет не принят устройством с адрессом 0x10)
/// 0x0			- unsigned char Received	: 1;
/// 0x0			- unsigned char				: 2;

#endif // PACKETS_H
