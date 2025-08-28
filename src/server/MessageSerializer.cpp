#include "MessageSerializer.h"
#include "Message.h"

using json = nlohmann::json;

static std::string MessageSerializer::serializeWithJson(Message message){
    json j;
    j["id"] = message.m_id;
    k["data"] = message.m_data;
    return j.dump();
}

static Message MessageSerializer::deserializeFromJson(std::string stringMessage){
    json j = json::parse(stringMessage);

    Message message;
    message.m_id = j["id"];
    message.m_data = j["data"];
    
    return message;
}