#include "queue.h"
int main() {
    AntrianTugas Q;
    char pekerjaan;
    int waktu;
    address p;
    createQueue(Q);
    for (int i=0; i<4; i++){
        cout << "pekerjaan : ";
        cin >> pekerjaan;
        cout << "waktu : ";
        cin >> waktu;
        p = createElmTugas(pekerjaan,waktu);
        TambahTugas(Q,p);
    }
    printInfo(Q);
    DailyTask(Q);
}
