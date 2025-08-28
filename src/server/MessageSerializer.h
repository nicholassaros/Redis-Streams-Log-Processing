#pragma once

#include "Message.h"

#include <iostream>
#include <nlohmann/json.hpp>

class MessageSerializer {
public:

    static std::string serializeWithJson(Message);

    static Message deserializeFromJson(std::string);

private:
}