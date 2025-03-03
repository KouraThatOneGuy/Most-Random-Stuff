# Distributed Computing Algorithms

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_NODES 5
#define TIMEOUT 3

typedef struct {
    int id;
    int term;
    int voted_for;
    int state; // 0: follower, 1: candidate, 2: leader
} Node;

Node nodes[NUM_NODES];

void* node_function(void* arg) {
    Node* node = (Node*)arg;
    while (1) {
        sleep(TIMEOUT);
        if (node->state == 0) {
            printf("Node %d: Follower timeout, becoming candidate\n", node->id);
            node->state = 1;
            node->term++;
            node->voted_for = node->id;
            // Simulate voting process
            printf("Node %d: Requesting votes for term %d\n", node->id, node->term);
            // Voting logic would go here
        }
        // Additional logic for leader and candidate states would go here
    }
    return NULL;
}

int main() {
    pthread_t threads[NUM_NODES];
    
    for (int i = 0; i < NUM_NODES; i++) {
        nodes[i].id = i;
        nodes[i].term = 0;
        nodes[i].voted_for = -1;
        nodes[i].state = 0; // Start as follower
        pthread_create(&threads[i], NULL, node_function, (void*)&nodes[i]);
    }

    for (int i = 0; i < NUM_NODES; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
