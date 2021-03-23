#include "pong.hpp"
#include <cstdio>

void pong::start()
{
    //only tick, when message arrives
    tickOnMessage(rx_trigger());
}

void pong::tick()
{
    //Parse the message we received
    auto proto = rx_trigger().getProto();
    const std::string message = proto.getMessage();

    auto proto_numb = rx_numb_rx().getProto();
    const uint16_t numb_msg = proto_numb.getMessage();

    //Print the desired number of 'PONG!' to the console, defined by isaac_param in header
    const int num_beeps = get_count();

    //print the sent message
    std::printf("%s:", message.c_str());

    for(int i = 0; i < num_beeps; i++)
    {
        std::printf(" PONG!");
    }

    //creates a new line if necessary
    if(num_beeps > 0)
    {
        std::printf("\n-----------------------------------------------------------------------\n");
    }
}