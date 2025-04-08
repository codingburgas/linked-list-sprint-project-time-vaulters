#include "pch.h"
#include "CppUnitTest.h"
#include "../TimeVaultersCode/BubbleSort.h"
#include "../TimeVaultersCode/BubbleSort.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TimeVaultersTests
{
    TEST_CLASS(TimeVaultersTests)
    {
    public:

        TEST_METHOD(TestBubbleSort)
        {
            // Create a list of HistoricEvent nodes
            HistoricEvent* event1 = new HistoricEvent{ "Event A", 2000, "Description A", nullptr, nullptr };
            HistoricEvent* event2 = new HistoricEvent{ "Event B", 1990, "Description B", nullptr, nullptr };
            HistoricEvent* event3 = new HistoricEvent{ "Event C", 2010, "Description C", nullptr, nullptr };

            // Link the nodes to form a doubly linked list
            event1->next = event2;
            event2->prev = event1;
            event2->next = event3;
            event3->prev = event2;

            HistoricEvent* head = event1;
            BubbleSort(head);

            // Verify the order of the events
            Assert::AreEqual(std::string("Event B"), head->name);
            Assert::AreEqual(1990, head->year);
            Assert::AreEqual(std::string("Description B"), head->description);

            Assert::AreEqual(std::string("Event A"), head->next->name);
            Assert::AreEqual(2000, head->next->year);
            Assert::AreEqual(std::string("Description A"), head->next->description);

            Assert::AreEqual(std::string("Event C"), head->next->next->name);
            Assert::AreEqual(2010, head->next->next->year);
            Assert::AreEqual(std::string("Description C"), head->next->next->description);

            // Clean up
            delete event1;
            delete event2;
            delete event3;
        }
    };
}