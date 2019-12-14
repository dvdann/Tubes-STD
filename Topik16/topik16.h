#ifndef TOPIK16_H_INCLUDED
#define TOPIK16_H_INCLUDED

#include <iostream>

#define nil NULL
#define first(L) L.first
#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev

using namespace std;

typedef struct elmTweets *addressTweets;
typedef struct elmHastags *addressHastags;
typedef struct elmRelasi*addressRelasi;

typedef struct infotypeTweets {
    int idTweets;
    string Tweets;
};

typedef struct infotypeHastags {
    int idHastags;
    string Hastags;
};

typedef struct infotypeRelasi {
    addressTweets Tweets;
    addressRelasi prev,next;
};

struct elmTweets {
    infotypeTweets info;
    addressTweets prev, next;
};

struct elmHastags {
    infotypeHastags info;
    addressHastags prev, next;
};

struct elmRelasi {
    addressTweets Tweets;
    addressTweets tw;
    addressRelasi next, prev;
};

struct listTweets {
    addressTweets first;
};

struct listHastags {
    addressHastags first;
};

struct listRelasi {
    addressRelasi first;
    addressTweets tw;
};

bool isEmptyTweets(listTweets L);
bool isEmptyHastags(listHastags L);
bool isEmptyRelasi(listRelasi L);
void createListTweets(listTweets &L);
void createListHastags(listHastags &L);
void createListRelasi(listRelasi &L);
addressTweets allocationTweets(infotypeTweets x);
addressHastags allocationHastags(infotypeHastags x);
addressRelasi allocationRelasi(infotypeRelasi x);
addressTweets searchTweets(int TI,listTweets L);
addressHastags searchHastags(int HI,listHastags L);
void tambahTweets(listTweets &L, addressTweets &P);
void tambahHastags(listHastags &L, addressHastags &P);
void tambahRelasi(listRelasi &L, addressRelasi &P);
void deleteTweets(listTweets &L, addressTweets &P);
void deleteHastags(listHastags &L, addressHastags &P);
void printTweets(listTweets &L);
void printHastags(listHastags &L);
void relasiinp(listTweets &T,listHastags &H,listRelasi &L);
addressHastags findhastweet(listHastags L, string x);
addressTweets findtweethas(listTweets L, string x);
void printtweethas(listTweets T, listRelasi &L, string tweet);
void printhastweet(listHastags H, listRelasi &L, string has);
#endif // TOPIK16_H_INCLUDED
