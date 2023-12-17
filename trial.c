/*
 * File: browser_history.c
 * Author: Manjiri Chavande
 * Email:  manjiri.chavanded23@spit.ac.in
 * Created: 25th Sep 2023
 * Description: i.  Design Browser History.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct BrowserNode {
    char *url;
    struct BrowserNode *prev;
    struct BrowserNode *next;
} BrowserNode;


typedef struct BrowserHistory {
    BrowserNode *current;
} BrowserHistory;


BrowserHistory *browserHistoryCreate(char *homepage) {
    BrowserHistory *history = (BrowserHistory *)malloc(sizeof(BrowserHistory));

    BrowserNode *node = (BrowserNode *)malloc(sizeof(BrowserNode));
    node->url = strdup(homepage);
    node->prev = NULL;
    node->next = NULL;


    history->current = node;

    return history;
}

// Visit a URL and add it to the history
void browserHistoryVisit(BrowserHistory *page, char *url) {
    BrowserNode *node = (BrowserNode *)malloc(sizeof(BrowserNode));
    node->url = strdup(url); // Copy the URL
    node->prev = page->current;
    node->next = NULL;

    if (page->current != NULL) {
        page->current->next = node;
    }

    page->current = node;
}

char *browserHistoryBack(BrowserHistory *page, int steps) {
    while (steps > 0 && page->current->prev != NULL) {
        page->current = page->current->prev;
        steps--;
    }
    return page->current->url;
}


char *browserHistoryForward(BrowserHistory *page, int steps) {
    while (steps > 0 && page->current->next != NULL) {
        page->current = page->current->next;
        steps--;
    }
    return page->current->url;
}


void browserHistoryFree(BrowserHistory *page) {
    BrowserNode *current = page->current;
    while (current != NULL) {
        BrowserNode *temp = current;
        current = current->next;
        free(temp->url);
        free(temp);
    }
    free(page);
}

int main() {

    BrowserHistory *history = browserHistoryCreate("Homepage");


    browserHistoryVisit(history, "github.com");
    browserHistoryVisit(history, "gmail.com");
    browserHistoryVisit(history, "youtube.com");
    browserHistoryVisit(history, "javascript.com");
    browserHistoryVisit(history, "java.com");
    browserHistoryVisit(history, "google.com");


    printf("Current URL: %s\n", browserHistoryBack(history, 2));
    printf("Current URL: %s\n", browserHistoryForward(history, 1));
    printf("Current URL: %s\n", browserHistoryBack(history, 0));
    printf("Current URL: %s\n", browserHistoryForward(history, 4));
    printf("Current URL: %s\n", browserHistoryBack(history, 3));
    printf("Current URL: %s\n", browserHistoryBack(history, 2));




    // Free the memory when done
    browserHistoryFree(history);

    return 0;
}
