#pragma once

#include "engine/alice/alice_codelet.hpp"
//#include "messages/ping.capnp.h"
//#include "messages/element_type.hpp"
#include "messages/messages.hpp"

class ping : public isaac::alice::Codelet {
 public:
  //start is always called at first
  void start() override;

  //tick can be configured periodically
  void tick() override;

  //close the application -> don't use constructor and destructor
  void stop() override;

  //ISAAC_Param(type, name of param, default value) -> can be used in tick function
  ISAAC_PARAM(std::string, message, "Hello World!");

  //send message (type of message, name of channel)
  ISAAC_PROTO_TX(PingProto, ping_str);
  ISAAC_PROTO_TX(ElementType, numb_tx);
};
//is the type under nodes in ping.app.json
ISAAC_ALICE_REGISTER_CODELET(ping);
