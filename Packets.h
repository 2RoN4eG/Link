#ifndef PACKETS_H
#define PACKETS_H

struct PacketPreamble_Private
{
    unsigned char Bit0 = 0;
    unsigned char Bit1 = 127;
    unsigned char Bit2 = 0;
    unsigned char Bit3 = 255;

    unsigned char Bit4 = 0;
    unsigned char Bit5 = 0;
    unsigned char Bit6 = 0;
    unsigned char Bit7 = 255;
};

/// Пакет для всех уст-в в сети
struct __attribute__ ((packed)) BroadcastPacket
{
    /// Преамбула
    /// ...

    /// Адресс для которого назначается пакет, 8 бит
    unsigned char Address	: 8 /*= 0xFF*/;

    /// Type: - Request  (0, b00)
    ///       - Responce (1, b01)
    ///       - Message  (2, b10)
    unsigned char Type		: 2;
    /// Версия пакета, 3 бит (0/1/2/3/4/5/)
    unsigned char Version	: 3	/*= 0x0*/;
    unsigned char           : 2;
    /// Ресивер готов принимать данные, 1 бит
    unsigned char Ready     : 1;

    /// Длинна пакета, 8 бит
    unsigned char Lenght	: 8;

    /// Data [0 - 255 * 8) bits

    /// Контрольная сумма, 8 бит
    unsigned char CheckSum8 : 8;

    unsigned char			: 6;
    /// Флаг коректной Контрольной суммы
    unsigned char Correct	: 1;
    /// Флаг коректного приема пакета
    unsigned char Received	: 1;

};

/// Пакет для/от конечного уст-ва
struct __attribute__ ((packed)) UnicastPacket
{
    /// Преамбула
    /// ...

    /// Адресс для которого назначается пакет, 8 бит
    unsigned char Address	: 8 /*= 0xFF*/;

    /// Type: - Request  (0, b00)
    ///       - Responce (1, b01)
    ///       - Message  (2, b10)
    unsigned char Type		: 2;
    /// Версия пакета, 3 бит (0/1/2/3/4/5/)
    unsigned char Version	: 3	/*= 0x0*/;
    unsigned char           : 2;
    /// Ресивер готов принимать данные, 1 бит
    unsigned char Ready     : 1;

    /// Длинна пакета, 8 бит
    unsigned char Lenght	: 8;

    /// Data [0 - 255 * 8) bits

    /// Контрольная сумма
    unsigned char CheckSum8	: 8;

    /// Флаг коректной Контрольной суммы
    unsigned char Correct	: 1;
    unsigned char			: 3;
    /// Флаг коректного приема пакета
    unsigned char Received	: 1;
    unsigned char			: 3;

};

#endif // PACKETS_H
