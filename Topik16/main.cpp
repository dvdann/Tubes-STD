#include "topik16.h"
#include <iostream>
using namespace std;
int tTweets = 0;
int tHastags = 0;

void mainmenu(listTweets LT, listHastags LH, listRelasi LR) {
    int pil;
    do {
        cout << endl;
        cout << "         MENU" << endl;
        cout << " ____________________" << endl << endl;
        cout << " 1. Tambah Tweets" << endl;
        cout << " 2. Tambah Hastags" << endl;
        cout << " 3. Tambah hubungan Tweet dan Hastags" << endl;
        cout << " 4. Hapus Tweets" << endl;
        cout << " 5. Tampil Hastags" << endl;
        cout << " 6. Tampil Semua Tweets dengan Hastags" << endl;
        cout << " 7. Tampil Hastags Yang Paling Populer" << endl;
        cout << " 8. Tampil Tweets dengan Hastags Tertentu" << endl;
        cout << " 9. Tampil Tweets Yang Memiliki 2 Hastags" << endl;
        cout << " 0. Keluar" << endl << endl;
        cout << " Pilih menu : ";
        cin >> pil;
        cout <<""<< endl;
        switch(pil){
        case 1 : {
            addressTweets P;
            infotypeTweets x;
            string tb;
            cout << " Masukkan Tweet Baru : ";
            cin >> tb;
            x.Tweets = tb;
            x.idTweets = tTweets + 1;
            P = allocationTweets(x);
            tambahTweets(LT, P);
            tTweets++;
            break;
        }
        case 2 :{
            addressHastags P;
            infotypeHastags x;
            string hb;
            cout << " Masukkan Hastags Baru : ";
            cin >> hb;
            x.Hastags = hb;
            x.idHastags = tHastags + 1;
            P = allocationHastags(x);
            tambahHastags(LH, P);
            tHastags++;
            break;
        }
        case 3 :{
            cout << "Belum bisa" << endl;
            relasiinp(LT,LH,LR);
            break;
        }
        case 4 :{
            printTweets(LT);
            int x;
            if (!isEmptyTweets(LT)) {
                cout << " Masukkan Tweets yang ingin dihapus (Berdasarkan ID) : ";
                cin >> x;
                addressTweets P;
                P = searchTweets(x, LT);
                if (P != nil) {
                    deleteTweets(LT, P);
                    cout << " Tweets berhasil dihapus" << endl;
                } else {
                    cout << " Tweets tidak ditemukan" << endl;
                }
            }
            break;
        }
        case 5 :{
            printHastags(LH);
            int x;
            if (!isEmptyHastags(LH)) {
                cout << " Masukkan Hastags yang ingin dihapus (Berdasarkan ID) : ";
                cin >> x;
                addressHastags P;
                P = searchHastags(x, LH);
                if (P != nil) {
                    deleteHastags(LH, P);
                    cout << " Hastags berhasil dihapus" << endl;
                } else {
                    cout << " Hastags tidak ditemukan" << endl;
                }
            }
            break;
        }
        case 6:{
            //TAMPIL SEMUA TWEET DENGAN HASTAGS//
            //printRelasi(LH,LT,LR);
            break;
        }
        case 7 :{
            printHastags(LH);
            break;
        }
        case 8 :{
            break;
        }
        case 9 : {
            break;
        }
        case 0 : break;
        default : break;
        }
    } while(pil != 0);
}

int main()
{

	listTweets LT;
	listHastags LH;
	listRelasi LR;
    createListTweets(LT);
    createListHastags(LH);
    createListRelasi(LR);
	mainmenu(LT, LH, LR);

    return 0;
}
