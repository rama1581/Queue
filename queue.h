#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include <iostream>

#define Nil NULL
#define info(P) P->info
#define next(P) P->next
#define head(Q) Q.head
#define tail(Q) Q.tail

using namespace std;

struct infotype {
    char pekerjaan;
    int waktu;
    int dikerjakan;
    string status;
};

typedef struct ElmTugas *address;

struct ElmTugas {
    infotype info;
    address next;
};

struct AntrianTugas {
    address head,tail;
};

void createQueue(AntrianTugas &Q);
address createElmTugas(char pekerjaan, int waktu);
void DailyTask(AntrianTugas &Q);
void TambahTugas(AntrianTugas &Q, address P);
void HapusTugas(AntrianTugas &Q, address &P);
void printInfo(AntrianTugas Q);
#endif // QUEUE_H_INCLUDED
