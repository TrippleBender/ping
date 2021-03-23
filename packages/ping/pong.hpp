#pragma once

#include "engine/alice/alice.hpp"
#include "messages/ping.capnp.h"
#include "messages/messages.hpp"

class pong : public isaac::alice::Codelet {
 public:
  void start() override;
  void tick() override;

  // An incoming message channel on which we receive pings.
  //(message, )
  ISAAC_PROTO_RX(PingProto, trigger);
  ISAAC_PROTO_RX(ElementType, numb_rx);

  // Specifies how many times we print 'PONG' when we are triggered
  ISAAC_PARAM(int, count, 3);
};
//is the type under nodes in ping.app.json
ISAAC_ALICE_REGISTER_CODELET(pong);