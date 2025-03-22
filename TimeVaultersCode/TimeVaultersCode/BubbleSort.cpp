#include "BubbleSort.h"

void BubbleSort(HistoricEvent event[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (event[j].year > event[j + 1].year) {
                HistoricEvent temp = event[j];
                event[j] = event[j + 1];
                event[j + 1] = temp;
            }
        }
    }
}