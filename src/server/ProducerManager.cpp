#include "ProducerManager.h"


ProducerManager::ProducerManager(int producer_count)
    : m_producerCount(producer_count) {

    for(int i = 0; i < producer_count; i++) {
        m_producers.emplace_back(Producer(i));
    }
}

ProducerManager::start() {
    for(auto producer : m_producers) {
        m_producerThreads.emplace_back(
            std::move(std::jthread(&Producer::run, &producer))
        );
    }
}