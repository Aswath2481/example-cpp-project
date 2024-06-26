#ifndef _STREAM_LIB_H
#define _STREAM_LIB_H

#include <stdint.h>
#include <cstring>
#include <array>



struct sensors {
	int32_t occVal;
	bool isbubbleDetected;
	float fnum;
};
int convertToStream(sensors T, std::array<uint8_t, 250>& buffer);
int reverseStream(sensors & T, std::array<uint8_t, 250>& buffer);


struct logDate {
	uint8_t dd;
	uint8_t mm;
	uint16_t yyyy;
};
int convertToStream(logDate T, std::array<uint8_t, 250>& buffer);
int reverseStream(logDate & T, std::array<uint8_t, 250>& buffer);


struct logTime {
	uint8_t sec;
	uint8_t min;
	uint8_t hh;
};
int convertToStream(logTime T, std::array<uint8_t, 250>& buffer);
int reverseStream(logTime & T, std::array<uint8_t, 250>& buffer);


struct infParam {
	uint32_t rate;
	uint32_t volume;
	logTime duration;
};
int convertToStream(infParam T, std::array<uint8_t, 250>& buffer);
int reverseStream(infParam & T, std::array<uint8_t, 250>& buffer);


#endif