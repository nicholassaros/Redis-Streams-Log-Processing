#pragma once

#include "Message.h"
#include "MessageSerializer.h"

#include <iostream>
#include <atomic>
#include <chrono>
#include <hiredis/hiredis.h>

class Producer {
public:
    Producer(std::string, int);

    void run();

    void stop();

private:

    void writeMessage();

    int m_id;
    redisContext m_connection;
    std::atomic<bool> m_stop(false);
};

