#include "streamlib.h"
int convertToStream(sensors T, std::array<uint8_t, 250>& buffer){
	uint8_t count=0;
	std::memcpy(buffer.begin()+count,&T.occVal,sizeof(T.occVal));
	count+=sizeof(T.occVal);
	std::memcpy(buffer.begin()+count,&T.isbubbleDetected,sizeof(T.isbubbleDetected));
	count+=sizeof(T.isbubbleDetected);
	std::memcpy(buffer.begin()+count,&T.fnum,sizeof(T.fnum));
	count+=sizeof(T.fnum);
	buffer.at(count)=0xa;
	return count+1;

}
int reverseStream(sensors & T, std::array<uint8_t, 250>& buffer){
	uint8_t count=0;
	std::memcpy(&T.occVal,buffer.begin()+count,sizeof(T.occVal));
	count+=sizeof(T.occVal);
	std::memcpy(&T.isbubbleDetected,buffer.begin()+count,sizeof(T.isbubbleDetected));
	count+=sizeof(T.isbubbleDetected);
	std::memcpy(&T.fnum,buffer.begin()+count,sizeof(T.fnum));
	count+=sizeof(T.fnum);
	return count+1;

}
int convertToStream(logDate T, std::array<uint8_t, 250>& buffer){
	uint8_t count=0;
	std::memcpy(buffer.begin()+count,&T.dd,sizeof(T.dd));
	count+=sizeof(T.dd);
	std::memcpy(buffer.begin()+count,&T.mm,sizeof(T.mm));
	count+=sizeof(T.mm);
	std::memcpy(buffer.begin()+count,&T.yyyy,sizeof(T.yyyy));
	count+=sizeof(T.yyyy);
	buffer.at(count)=0xa;
	return count+1;

}
int reverseStream(logDate & T, std::array<uint8_t, 250>& buffer){
	uint8_t count=0;
	std::memcpy(&T.dd,buffer.begin()+count,sizeof(T.dd));
	count+=sizeof(T.dd);
	std::memcpy(&T.mm,buffer.begin()+count,sizeof(T.mm));
	count+=sizeof(T.mm);
	std::memcpy(&T.yyyy,buffer.begin()+count,sizeof(T.yyyy));
	count+=sizeof(T.yyyy);
	return count+1;

}
int convertToStream(logTime T, std::array<uint8_t, 250>& buffer){
	uint8_t count=0;
	std::memcpy(buffer.begin()+count,&T.sec,sizeof(T.sec));
	count+=sizeof(T.sec);
	std::memcpy(buffer.begin()+count,&T.min,sizeof(T.min));
	count+=sizeof(T.min);
	std::memcpy(buffer.begin()+count,&T.hh,sizeof(T.hh));
	count+=sizeof(T.hh);
	buffer.at(count)=0xa;
	return count+1;

}
int reverseStream(logTime & T, std::array<uint8_t, 250>& buffer){
	uint8_t count=0;
	std::memcpy(&T.sec,buffer.begin()+count,sizeof(T.sec));
	count+=sizeof(T.sec);
	std::memcpy(&T.min,buffer.begin()+count,sizeof(T.min));
	count+=sizeof(T.min);
	std::memcpy(&T.hh,buffer.begin()+count,sizeof(T.hh));
	count+=sizeof(T.hh);
	return count+1;

}
int convertToStream(infParam T, std::array<uint8_t, 250>& buffer){
	uint8_t count=0;
	std::memcpy(buffer.begin()+count,&T.rate,sizeof(T.rate));
	count+=sizeof(T.rate);
	std::memcpy(buffer.begin()+count,&T.volume,sizeof(T.volume));
	count+=sizeof(T.volume);
	std::memcpy(buffer.begin()+count,&T.duration,sizeof(T.duration));
	count+=sizeof(T.duration);
	buffer.at(count)=0xa;
	return count+1;

}
int reverseStream(infParam & T, std::array<uint8_t, 250>& buffer){
	uint8_t count=0;
	std::memcpy(&T.rate,buffer.begin()+count,sizeof(T.rate));
	count+=sizeof(T.rate);
	std::memcpy(&T.volume,buffer.begin()+count,sizeof(T.volume));
	count+=sizeof(T.volume);
	std::memcpy(&T.duration,buffer.begin()+count,sizeof(T.duration));
	count+=sizeof(T.duration);
	return count+1;

}
