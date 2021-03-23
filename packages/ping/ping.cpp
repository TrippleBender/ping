#include "ping.hpp"

void ping::start()
{
  //define periodic ticking
  tickPeriodically();
}

void ping::tick()
{
  static uint16_t counter = 0;

  //print something every tick
  LOG_INFO("ping: %u", counter);
  //LOG_INFO(get_message().c_str());

  counter++;

  //create and publish a ping message
  auto proto_str = tx_ping_str().initProto();
  proto_str.setMessage(get_message());
  tx_ping_str().publish();

  auto proto_numb = tx_numb_tx().initProto();
  proto_numb.setMessage(counter);
  tx_numb_tx().publish();
}

void ping::stop() {}
