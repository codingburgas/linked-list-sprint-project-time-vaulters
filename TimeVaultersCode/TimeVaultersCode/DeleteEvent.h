#pragma once
#include <iostream>
#include <filesystem>
#include <string>

struct EventNode {
    std::string fileName;
    EventNode* next;
    EventNode(const std::string& file) : fileName(file), next(nullptr) {}
};

void deleteEvent();