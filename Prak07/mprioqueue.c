// NIM              : 13520131
// Nama             : Steven
// Tanggal          : 7 Oktober 2021
// Topik Praktikum  : ADT Queue
// Deskripsi        : Praktikum 7

#include <stdio.h>
#include <stdlib.h>
#include "prioqueue.h"

#define MAX 110

typedef struct Data Data;
struct Data {
    int id;
    int arrivalTime;
    int score;
    int serviceTime;
};

int main() {
    int current_time = 0;
    int n_students;

    scanf("%d", &n_students);

    if(n_students == 0) {
        printf("Tidak ada layanan\n");
        return 0;
    }

    Data data[n_students];
    for(int i = 0; i < n_students; ++i) {
        scanf("%d %d %d %d", &data[i].arrivalTime, &data[i].id, &data[i].score, &data[i].serviceTime);
    }


    printf("%d %d 0\n", data[0].arrivalTime, data[0].id);
    current_time = data[0].arrivalTime + data[0].serviceTime;

    for(int i = 1; i < n_students; ++i) {
        for(int j =i; j < n_students - 1; ++j) {
            for(int k = i; k < n_students - 1; ++k) {
                if(data[k].arrivalTime < (current_time - data[i-1].arrivalTime) &&
                   data[k+1].arrivalTime < current_time - data[i-1].arrivalTime) {

                    if(data[k].score < data[k+1].score) {
                        Data temp = data[k];
                        data[k] = data[k+1];
                        data[k+1] = temp;
                    }
                }
            }
        }
        int waiting_time = current_time - data[i].arrivalTime;
        waiting_time = waiting_time < 0 ? 0 : waiting_time;
        if(current_time < data[i].arrivalTime) {
            current_time = data[i].arrivalTime;
        }
        printf("%d %d %d\n", current_time, data[i].id, waiting_time );
        current_time += data[i].serviceTime;
    }

    return 0;
}
