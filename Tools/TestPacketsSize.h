#ifndef TESTPACKETSSIZE_H
#define TESTPACKETSSIZE_H

#include "Packets.h"

#include <iostream>
#include <string>

std::string CheckPackets ()
{
    std::string message = "";

    // std::cout << "UnicastPacket   size is " << sizeof (UnicastPacket)   << std::endl;
    // std::cout << "BroadcastPacket size is " << sizeof (BroadcastPacket) << std::endl;

    message += std::string ("Check Unicast Packet size") + std::to_string (sizeof (UnicastPacket))   + std::string ("\n");
    message += std::string ("BroadcastPacket size is ")  + std::to_string (sizeof (BroadcastPacket)) + std::string ("\n");

    std::cout << message << std::endl;

    return message;
}

// CheckPacketSize <UnicastPacket,   8> ("UnicastPacket");
// CheckPacketSize <BroadcastPacket, 8> ("BroadcastPacket");

template <typename TPacket, unsigned char TPacketSize = 5>
std::string CheckPacketSize (std::string name)
{
    std::string message ("Проверка размера пакета ");

    message += name;

    if (TPacketSize == sizeof (TPacket))
    {
        message += std::string (" - (Success) Проверка пройдена успешно.");
    }
    else
    {
        message += std::string (" - (Error) Ошибка") +
        std::string (": Не правильный размер пакета, Пакет должен быть ") +
        std::to_string (TPacketSize) +
        std::string (" байт, текущий размер ") +
        std::to_string (sizeof (TPacket)) +
        std::string (" байт.");
    }

    std::cout << message << std::endl;

    return message;
}

// typedef CheckPacketSize <BroadcastPacket, 5> CheckBroadcastPacketSize;
// typedef CheckPacketSize <UnicastPacket, 5>   CheckUnicastPacketSize;

// #define CheckBroadcastPacketSize CheckPacketSize <BroadcastPacket, 5>
// #define CheckUnicastPacketSize   CheckPacketSize <UnicastPacket, 5>

std::string CheckBroadcastPacketSize (std::string name = std::string ("BroadcastPacket"))
{
    return CheckPacketSize <BroadcastPacket, 5> (name);
}

std::string CheckUnicastPacketSize (std::string name = std::string ("UnicastPacket"))
{
    return CheckPacketSize <UnicastPacket, 5> (name);
}


#endif // TESTPACKETSSIZE_H
