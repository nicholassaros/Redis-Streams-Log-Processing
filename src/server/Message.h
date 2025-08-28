#pragma once

#include <iostream>

struct Message {
    int m_id;
    std::string m_data;

    Message(int id, std::string data)
        : m_id(id), m_data(data) {}
};