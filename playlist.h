#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include <string>
using namespace std;

class Playlist {
private:
    struct Node {
        int id;
        string title;
        string artist;
        int duration;
        Node* next;
    };

    Node* head;
    int size;
public:
    Playlist();
    ~Playlist();
    bool isEmpty();
    int getSize();
    void clear();
    void display();
    void addSongEnd(int id, const string& title, const string& artist, int duration);
    void addSongBeginning(int id, const string& title, const string& artist, int duration);
    void addSongAt(int id, const string& title, const string& artist, int duration, int pos);
    bool removeSongById(int id);
    bool removeSongAt(int pos);
    int findSongById(int id);
    int findSongByTitle(const string& title);
    bool moveSongUp(int id);
    bool moveSongDown(int id);
    void playAll();
    void playFrom(int pos);
    int getFirstId();
    int getLastId();
};

#endif