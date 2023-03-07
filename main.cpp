#include <stdio.h>
#include "hdlc.h"
#include "crc16.h"
#include <iostream>

uint8_t HDLCBuffer[1024];
HDLC hdlc(HDLCBuffer, 1024);

int main (void)
{
    uint8_t dat[5] = {'H',0x7E,'l','l','o'};
    HDLC::HDLCData data {
        .ADD = 'A',
        .CTR = 'B',
        .DAT = dat,
        .DATlen = 5
    };
    hdlc.setData(&data);
    hdlc.frame();
    std::cout << "CRC16 valid? " << hdlc.unframe() << std::endl;
    return 0;
}