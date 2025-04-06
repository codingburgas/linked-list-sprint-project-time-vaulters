#pragma once
#include <string>
#include <filesystem>
#include <iostream>

struct EventNode {
    std::string fileName;
    EventNode* next;
    EventNode(const std::string& file) : fileName(file), next(nullptr) {}
};

EventNode* readEventFiles(const std::string& dirPath);
void displayEventList(EventNode* head);