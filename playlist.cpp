#include "Playlist.h"

Playlist::Playlist() {
    head = nullptr;
    size = 0;
}

Playlist::~Playlist() {
    clear();
}

bool Playlist::isEmpty() {
    return head == nullptr;
}

int Playlist::getSize() {
    return size;
}

void Playlist::clear() {
    while (head != nullptr) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
    size = 0;
}

void Playlist::display() {
    Node* temp = head;
    cout << "\n=== Playlist (" << size << " songs) ===\n";
    while (temp != nullptr) {
        int m = temp->duration / 60;
        int s = temp->duration % 60;
        cout << temp->id << ". " << temp->title << " - " << temp->artist
             << " [" << m << ":" << (s < 10 ? "0" : "") << s << "]\n";
        temp = temp->next;
    }
    cout << "=========================\n";
}

void Playlist::addSongEnd(int id, const string& title, const string& artist, int duration) {
    Node* newNode = new Node{ id, title, artist, duration, nullptr };
    if (isEmpty()) head = newNode;
    else {
        Node* temp = head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = newNode;
    }
    size++;
}

void Playlist::addSongBeginning(int id, const string& title, const string& artist, int duration) {
    Node* newNode = new Node{ id, title, artist, duration, head };
    head = newNode;
    size++;
}

void Playlist::addSongAt(int id, const string& title, const string& artist, int duration, int pos) {
    if (pos < 1 || pos > size + 1) return;
    if (pos == 1) { addSongBeginning(id, title, artist, duration); return; }
    Node* newNode = new Node{ id, title, artist, duration, nullptr };
    Node* temp = head;
    for (int i = 1; i < pos - 1; i++) temp = temp->next;
    newNode->next = temp->next;
    temp->next = newNode;
    size++;
}

bool Playlist::removeSongById(int id) {
    if (isEmpty()) return false;
    if (head->id == id) { Node* del = head; head = head->next; delete del; size--; return true; }
    Node* temp = head;
    while (temp->next != nullptr && temp->next->id != id) temp = temp->next;
    if (temp->next == nullptr) return false;
    Node* del = temp->next;
    temp->next = del->next;
    delete del;
    size--;
    return true;
}

bool Playlist::removeSongAt(int pos) {
    if (pos < 1 || pos > size) return false;
    if (pos == 1) { Node* del = head; head = head->next; delete del; size--; return true; }
    Node* temp = head;
    for (int i = 1; i < pos - 1; i++) temp = temp->next;
    Node* del = temp->next;
    temp->next = del->next;
    delete del;
    size--;
    return true;
}

int Playlist::findSongById(int id) {
    Node* temp = head; int pos = 1;
    while (temp != nullptr) { if (temp->id == id) return pos; temp = temp->next; pos++; }
    return -1;
}

int Playlist::findSongByTitle(const string& title) {
    Node* temp = head; int pos = 1;
    while (temp != nullptr) { if (temp->title == title) return pos; temp = temp->next; pos++; }
    return -1;
}

bool Playlist::moveSongUp(int id) {
    if (isEmpty() || head->id == id) return false;
    Node* prev = nullptr; Node* cur = head;
    while (cur != nullptr && cur->id != id) { prev = cur; cur = cur->next; }
    if (cur == nullptr || prev == nullptr) return false;
    Node* prev2 = nullptr; Node* temp = head;
    while (temp != nullptr && temp->next != prev) temp = temp->next;
    prev2 = temp;
    if (prev2 == nullptr) { prev->next = cur->next; cur->next = prev; head = cur; return true; }
    prev2->next = cur; prev->next = cur->next; cur->next = prev; return true;
}

bool Playlist::moveSongDown(int id) {
    if (isEmpty() || head->next == nullptr) return false;
    Node* prev = nullptr; Node* cur = head;
    while (cur != nullptr && cur->id != id) { prev = cur; cur = cur->next; }
    if (cur == nullptr || cur->next == nullptr) return false;
    Node* nxt = cur->next;
    if (prev == nullptr) { head = nxt; cur->next = nxt->next; nxt->next = cur; return true; }
    prev->next = nxt; cur->next = nxt->next; nxt->next = cur; return true;
}

void Playlist::playAll() {
    Node* temp = head;
    cout << "\nPlaying playlist:\n";
    while (temp != nullptr) {
        int m = temp->duration / 60; int s = temp->duration % 60;
        cout << "Now playing: " << temp->title << " - " << temp->artist
             << " (" << m << ":" << (s < 10 ? "0" : "") << s << ")\n";
        temp = temp->next;
    }
    cout << "End of playlist.\n";
}

void Playlist::playFrom(int pos) {
    if (pos < 1 || pos > size) return;
    Node* temp = head;
    for (int i = 1; i < pos; i++) temp = temp->next;
    cout << "\nPlaying from position " << pos << ":\n";
    while (temp != nullptr) {
        int m = temp->duration / 60; int s = temp->duration % 60;
        cout << "Now playing: " << temp->title << " - " << temp->artist
             << " (" << m << ":" << (s < 10 ? "0" : "") << s << ")\n";
        temp = temp->next;
    }
    cout << "End of playlist.\n";
}

int Playlist::getFirstId() { if (isEmpty()) return -1; return head->id; }
int Playlist::getLastId() { if (isEmpty()) return -1; Node* temp = head; while (temp->next != nullptr) temp = temp->next; return temp->id; }