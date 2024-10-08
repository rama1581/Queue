#include "queue.h"

void createQueue(AntrianTugas &Q){
    head(Q) = Nil;
    tail(Q) = Nil;
}

address createElmTugas(char pekerjaan, int waktu){
    address P = new ElmTugas;
    info(P).pekerjaan = pekerjaan;
    info(P).waktu = waktu;
    info(P).dikerjakan = 0;
    info(P).status = "unfinished";
    next(P) = Nil;
    return P;
}

void DailyTask(AntrianTugas &Q) {
    int totalWaktu = 0;
    address P = head(Q);

    while (P != Nil) {
        // Menampilkan informasi tugas
        cout << "Melakukan pekerjaan " << info(P).pekerjaan << " selama " << info(P).waktu << " unit waktu." << endl;

        // Menambahkan waktu yang dikerjakan ke total waktu
        totalWaktu += info(P).waktu;
        int &waktu_dikerjakan = info(P).dikerjakan;
        waktu_dikerjakan += info(P).waktu;

        // Ubah status menjadi "finished"
        info(P).status = "finished";

        // Simpan alamat P sebelum pindah ke elemen berikutnya
        address temp = P;
        P = next(P);

        if (waktu_dikerjakan >= info(temp).waktu) {
            // Jika sudah selesai, hapus dari antrian
            HapusTugas(Q, temp);
        } else {
            // Jika belum selesai, masukkan kembali ke antrian
            TambahTugas(Q, temp);
        }
    }

    cout << "Total waktu pengerjaan semua tugas: " << totalWaktu << " unit waktu." << endl;
}



void TambahTugas(AntrianTugas &Q, address P) {
    if (head(Q) == Nil) {
        head(Q) = P;
        tail(Q) = P;
    } else {
        next(tail(Q)) = P;
        tail(Q) = P;
        next(tail(Q)) = head(Q);
    }
}

void HapusTugas(AntrianTugas &Q, address &P) {
    if (head(Q) != Nil) {
        P = head(Q);
        head(Q) = next(P);
        if (head(Q) == Nil){
            tail(Q) = Nil;
        }
        next(P) = Nil;
    }
}

void printInfo(AntrianTugas Q) {
    address P = head(Q);
    cout << "Pekerjaan : " << info(P).pekerjaan << " Waktu : " << info(P).waktu << " Dikerjakan " << info(P).dikerjakan << " Status :" << info(P).status << endl;
    P = next(P);
    do  {
    cout << "Pekerjaan : " << info(P).pekerjaan << " Waktu : " << info(P).waktu << " Dikerjakan " << info(P).dikerjakan << " Status :" << info(P).status << endl;
    	P = next(P);
    }while (P != head(Q));
}
