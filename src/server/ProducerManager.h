#pragma once

#include "Producer.h"

#include <iostream>
#include <thread>

class ProducerManager {
public:
    ProducerManager(int);

    void start();

private:
    int                         m_producerCount;
    std::vector<Producer>       m_producers;
    std::vector<std::jthread>   m_producerThreads;
};