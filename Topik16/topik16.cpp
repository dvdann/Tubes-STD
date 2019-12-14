#include "topik16.h"
#include <iostream>

bool isEmptyTweets(listTweets L){
  return (first(L) == NULL);
};

bool isEmptyHastags(listHastags L){
    return (first(L) == NULL);
};
bool isEmptyRelasi(listRelasi L){
    return (first(L) == NULL);
};

void createListTweets(listTweets &L) {
    first(L) = NULL;
};

void createListHastags(listHastags &L) {
    first(L) = NULL;
};

void createListRelasi(listRelasi &L) {
    first(L) = NULL;
};

addressTweets allocationTweets(infotypeTweets x){
    addressTweets P = new elmTweets;
    next(P) = NULL;
    prev(P) = NULL;
    info(P).Tweets = x.Tweets;
    info(P).idTweets = x.idTweets;
};

addressHastags allocationHastags(infotypeHastags x){
    addressHastags P = new elmHastags;
    next(P) = NULL;
    prev(P) = NULL;
    info(P).Hastags = x.Hastags;
    info(P).idHastags = x.idHastags;
};

addressRelasi allocationRelasi(addressTweets x){
    addressRelasi P = new elmRelasi;
    next(P) = NULL;
    prev(P) = NULL;
    P->Tweets = x;
};

addressTweets searchTweets(int TI,listTweets L) {
    addressTweets P = first(L);
    while (next(P) != first(L) && info(P).idTweets != TI){
        P = next(P);
    }
    if (info(P).idTweets == TI){
        return P;
    } else{
        return NULL;
    }
};

addressHastags searchHastags(int HI,listHastags L){
    addressHastags Q = first(L);
    while (next(Q) != first(L) && info(Q).idHastags != HI){
        Q = next(Q);
    }
    if (info(Q).idHastags == HI){
        return Q;
    } else{
        return NULL;
    }
};

addressTweets findtweet (listTweets L, infotypeTweets x){
    addressTweets temp;
    if(first(L)!=NULL){
        addressTweets temp = first(L);
        while (temp!=NULL){
            temp = next(temp);
        }
    } return temp;
}

addressHastags findhastags (listHastags L, infotypeHastags x){
    addressHastags temp1;
    if(first(L)!=NULL){
        addressHastags temp1 = first(L);
        while (temp1!=NULL){
            temp1 = next(temp1);
        }
    } return temp1;
}

addressRelasi findrel (listHastags L, listTweets Q, listRelasi M){
    addressRelasi temp1;
    if((first(L)!=NULL)&&(first(Q))){
        addressHastags temp1 = first(L);
        while (temp1!=NULL){
            temp1 = next(temp1);
        }
    } return temp1;
}

addressHastags findhastweet(listHastags L, string x){
    if (first(L)!=NULL){
        addressHastags temphas = first(L);
        while ((temphas!=NULL)&&(temphas->info.Hastags!=x)){
            temphas = temphas->next;
        }
        return temphas;
    }
}

addressTweets findtweethas(listTweets L, string x){
    if (first(L)!=NULL){
        addressTweets temptweet = first(L);
        while ((temptweet!=NULL)&&(temptweet->info.Tweets!=x)){
            temptweet = temptweet->next;
        }
        return temptweet;
    }
}

void tambahTweets(listTweets &L, addressTweets &P){
    if (isEmptyTweets(L)){
        first(L)=P;
    }
    else{
        addressTweets Q = first(L);
        while (next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = P;
        prev(P) = Q;
    }
};

void tambahHastags(listHastags &L, addressHastags &P)
{
    if (isEmptyHastags(L)){
        first(L)=P;
    }
    else{
        addressHastags Q = first(L);
        while (next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = P;
        prev(P) = Q;
    }
};

void tambahRelasi(listRelasi &L, addressRelasi &P){
    if (isEmptyRelasi(L)){
        first(L)=P;
    }
    else{
        addressRelasi Q = first(L);
        while (next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = P;
        prev(P) = Q;
    }
};

void deleteTweets(listTweets &L, addressTweets &P){
    addressTweets Q, R;
    if (P == first(L)){
        if (next(P) == NULL){
            first(L) = NULL;
        } else {
            Q = next (P);
            prev(Q) = NULL;
            first(L) = Q;
            next(P) = NULL;
        }
    } else {
        if (next(P) == nil){
            Q = prev(P);
            prev(P) = nil;
            next(Q) = nil;
        } else {
            Q = prev(P);
            R = next(P);
            prev(P) = nil;
            next(P) = nil;
            next(Q) = R;
            prev(R) = Q;
        }
    }
};

void deleteHastags(listHastags &L, addressHastags &P){
    addressHastags Q, R;
    if (P == first(L)){
        if (next(P) == NULL){
            first(L) = NULL;
        } else {
            Q = next(P);
            prev(Q) = NULL;
            first(L) = Q;
            next(P) = NULL;
        }
    } else {
        if (next(P) == NULL){
            Q = prev(P);
            prev(P) = NULL;
            next(Q) = NULL;
        } else {
            Q = prev(P);
            R = next(P);
            prev(P) = NULL;
            next(P) = NULL;
            next(Q) = R;
            prev(R) = Q;
        }
    }
};
void printTweets(listTweets &L)
{
    if (!isEmptyTweets(L)) {
        addressTweets P = first(L);
        cout << " ID Tweets  |  Nama Tweets" << endl;
        while (P != nil) {
            cout << " " << info(P).idTweets << "  |  " << info(P).Tweets << endl;
            P = next(P);
        }
	} else {
		cout << " Tidak ada Tweets" << endl;
	}
};

void printHastags(listHastags &L)
{
    if (!isEmptyHastags(L)) {
        addressHastags P = first(L);
        cout << " ID Hastags  |  Nama Hastags" << endl;
        while (P != nil) {
            cout << " " << info(P).idHastags << "  |  " << info(P).Hastags << endl;
            P = next(P);
        }
	} else {
		cout << " Tidak ada Hastags" << endl;
	}
};

void relasiinp (listTweets &T, listHastags &H, listRelasi &R){
    addressTweets ph;
    infotypeTweets twrel;
    addressHastags pt;
    infotypeHastags hsrel;
    addressRelasi addrel;
    cout<<" HARAP PERHATIKAN PENULISAN "<<endl;
    printTweets(T);
    if (first(T) != NULL){
        cout<<" Masukkan Tweet yang ingin direlasikan : ";
        cin>>twrel.Tweets;
        ph = findtweet(T, twrel);
        if ( pt != NULL){
    printHastags(H);
    if(first(H) != NULL){
        cout<<" Masukkan Hastags yang ingin direlasikan : ";
        cin>>hsrel.Hastags;
        pt = findhastags(H, hsrel);
        if (ph != NULL){
            if (findrel(H,T,R)==NULL){
                tambahRelasi(R,addrel);
                cout<<" Tweet : -";
                cout<<twrel.Tweets;
                cout<<"- & Hastags : -";
                cout<<hsrel.Hastags;
                cout<<"- Sudah Di-Relasikan\n"<<endl;
            }
            else{
                cout<<"\n Relasi Data Sudah Ada\n"<<endl;
            }
        }
        else{
            cout<<"\n Twwet Tidak Ditemukan\n"<<endl;
        }
    }
    else{
        cout << "\n Harap Masukkan Tweet Dahulu....\n";
    }
        }
        else{
            cout<<"\n Hastags Tidak Ditemukan\n"<<endl;
        }
    }
    else{
        cout << "\n Harap Masukkan Hastags Dahulu....\n";
    }
}

//void printtweethas(listTweets T, listHastags &L, listRelasi &O, string tweet){
//    int r;
//    if (first(O) == NULL){
//        cout<<" Tweets belum tersedia / belum direlasikan! "<<endl;
//    } else {
//        addressHastags P;
//        P = findtweethas(T, tweet);
//        if ( P == NULL){
//            cout<<" Tweet tidak ada "<<endl;
//        } else {
//            addressRelasi Q;
//            addressTweets K;
//            int i=1;
//            do {
//                Q = findhastags(tweet, L);
//                if (Q != NULL){
//                    K = Q->tw;
//                    cout<< " "<<i<<". "<<K->info.Tweets<<endl;
//                    i++;
//                }
//                r=r->next;
//            } while (r!=NULL);
//        }
//    }
//}
//
//
