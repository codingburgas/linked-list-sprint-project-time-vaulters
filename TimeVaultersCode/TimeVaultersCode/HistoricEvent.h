#pragma once
#include <string>

struct HistoricEvent {
    std::string name;
    int year = 0;
    std::string description;
    HistoricEvent* prev = nullptr;
    HistoricEvent* next = nullptr;
};