#include "Producer.h"

Producer::Producer(int id, int port, std::string address)
    : m_id(id), m_connection(redisConnect(address, port)) {
}

void Producer::run() {
    while(!m_stop.load()) {
        std::string message_data = "Message from Producer: " + std::to_string(m_id);
        Message message = Message(m_id, message_data);

        std::string serialized_message = MessageSerializer.serializeWithJson(message);

        writeMessage(serialized_message);
        
        std::this_thread::sleep_for(std::chrono::milliseconds(10000)); 
    }
}

void Producer::stop() {
    flag.store(true);
}

void Producer::writeMessage(std::string message) {
    redisReply *reply = (redisReply*)redisCommand(m_connection, "SET mykey %s", message.c_str());
}


