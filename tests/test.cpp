// 010-TestCase.cpp
// And write tests in the same file:
#include <catch2/catch_test_macros.hpp>
#include "streamlib.h"
#include <tuple>

// ...

bool operator==(const logTime& lParams, const logTime& rParams)
{
    return std::tie(lParams.hh, lParams.min, lParams.sec) == std::tie(rParams.hh, rParams.min, rParams.sec);
}

bool operator==(const logDate& lParams, const logDate& rParams)
{
    return std::tie(lParams.mm, lParams.dd, lParams.yyyy) == std::tie(rParams.mm, rParams.dd, rParams.yyyy);
}

bool operator==(const infParam& lParams, const infParam& rParams)
{
    return std::tie(lParams.rate, lParams.volume, lParams.duration) == std::tie(rParams.rate, rParams.volume, rParams.duration);
}


TEST_CASE( "checking logTime stream", "[logtest]" ) {
    //WARN( "CHECK continues after failure:" );
    logTime forward,backward={0};
    forward.hh=10;
    forward.min=22;
    forward.sec=5;
    std::array<uint8_t,250> buffer;
    buffer.fill('\0');
    int count=convertToStream(forward,buffer);
    reverseStream(backward,buffer);
    CHECK(forward==backward);
}
TEST_CASE( "checking logDate stream", "[logtest]" ) {
    //WARN( "CHECK continues after failure:" );
    logDate forward,backward={0};
    forward.dd=10;
    forward.mm=22;
    forward.yyyy=5;
    std::array<uint8_t,250> buffer;
    buffer.fill('\0');
    int count=convertToStream(forward,buffer);
    reverseStream(backward,buffer);
    // forward={0}; 
    CHECK(forward==backward);
}

TEST_CASE( "checking infParams stream", "[logtest]" ) {
    //WARN( "CHECK continues after failure:" );
    infParam forward,backward={0};
    forward.rate=10;
    forward.volume={22};
    forward.duration={5};
    // forward.duration.hh=15;
    // forward.duration.hh=25;
    std::array<uint8_t,250> buffer;
    buffer.fill('\0');
    int count=convertToStream(forward,buffer);
    reverseStream(backward,buffer);
    // forward={0}; 
    CHECK(forward==backward);
}