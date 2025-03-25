#pragma once
#include <string>

struct HistoricEvent {
    std::string name;
    int year;
    std::string description;
    HistoricEvent* prev;
    HistoricEvent* next;
};