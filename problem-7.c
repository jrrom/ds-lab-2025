#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* title;
    char* artist;
    int duration;
} Song;

typedef struct Node Node;

struct Node {
    Node* prev;
    Song song;
    Node* next;
};

Node* playlist = NULL;

int size(Node* head) {
    if (!head) return 0;
    int count = 0;
    for (
         Node* current = head;
         current->next != head;
         current = current->next
     ) count++;
    if (head->next) count++;
    return count;
}

Song newSong
(
 char* title,
 char* artist,
 int duration
) {
    return (Song) {
        .title    = title,
        .artist   = artist,
        .duration = duration
    };
}

void addSong(Song song) {
    Node* new = (Node*)malloc(sizeof(Node));
    new->prev = NULL;
    new->song = song;
    new->next = NULL;
    
    if (!playlist) {
        new->prev = new;
        new->next = new;
        playlist = new;
        return;
    }

    Node* current;
    for (
         current = playlist;
         current->next != playlist;
         current = current->next
     );
    current->next  = new;
    playlist->prev = new;

    new->prev = current;
    new->next = playlist;
}

void removeSong(char* title) {
    Node* prev = playlist;
    Node* current;

    if (strcmp(playlist->song.title, title) == 0) {
        if (size(playlist) == 1) {
            free(playlist);
            playlist = NULL;
            return;
        }
        playlist = playlist->next;
        return removeSong(title);
    }

    for (
         current = playlist->next;
         current;
         current = current->next
     ) {
        if (strcmp(current->song.title, title) == 0) {
            if (size(playlist) == 1) return;
            
            Node* after = current->next;
            prev->next  = after;
            after->prev = prev;

            free(current);
            return;
        }
        prev = current;
    }
}

void playNext() {
    playlist = playlist->next;
}

void playPrevious() {
    playlist = playlist->prev;
}

void displayPlaylist() {
    if (!playlist) {
        printf("Error! Playlist is empty\n");
        return;
    }
    
    Song s = playlist->song;
    printf("   %-20s %-20s %s\n",
           "Title", "Artist", "Duration");
    printf("-> %-20s %-20s %d\n",
           s.title, s.artist, s.duration);
    for (
         Node* current = playlist->next;
         current != playlist;
         current = current->next
     ) {
        s = current->song;
        printf("   %-20s %-20s %d\n",
               s.title, s.artist, s.duration);        
     }

    printf("\n");
}

int main() {
    Song A = newSong("Walk On", "Neil Young", 2 * 60 + 40);
    Song B = newSong("Cities", "Talking Heads", 4 * 60 + 14);
    Song C = newSong("The Weight", "The Band", 4 * 60 + 38);
    Song D = newSong("All I Wanna Do", "The Beach Boys", 2 * 60 + 38);
    Song E = newSong("Ten Years Gone", "Led Zeppelin", 6 * 60 + 34);
        
    addSong(A);
    addSong(B);
    addSong(C);
    addSong(D);
    addSong(E);
    displayPlaylist();

    playPrevious();
    displayPlaylist();

    playNext();
    displayPlaylist();

    removeSong(C.title);
    displayPlaylist();

    playNext();
    playNext();
    displayPlaylist();
}
