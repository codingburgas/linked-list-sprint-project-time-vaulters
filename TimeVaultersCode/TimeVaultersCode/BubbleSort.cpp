#include "BubbleSort.h"

void BubbleSort(HistoricEvent* head) {
    if (!head) return;

    bool swapped;
    HistoricEvent* ptr1;
    HistoricEvent* lptr = nullptr;

    do {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->year > ptr1->next->year) {
                std::swap(ptr1->year, ptr1->next->year);
                std::swap(ptr1->name, ptr1->next->name);
                std::swap(ptr1->description, ptr1->next->description);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}