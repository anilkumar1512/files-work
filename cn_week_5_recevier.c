#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEQ 7
#define BUFFER_SIZE 1

typedef struct {
    int seq;
    char data[BUFFER_SIZE];
} Frame;

void receive_frame(Frame frame) {
    printf("Received frame with sequence number: %d\n", frame.seq);
}

void sliding_window_receiver() {
    int expected_frame = 0;

    while (1) {
        Frame frame;
        frame.seq = expected_frame % (MAX_SEQ + 1);

        receive_frame(frame);

        if (frame.seq == expected_frame) {
            printf("Frame with sequence number %d is correctly received.\n", expected_frame);
            expected_frame++;
        } else {
            printf("Frame with sequence number %d is out of order.\n", frame.seq);
        }

        printf("Acknowledgment sent for frame with sequence number: %d\n", expected_frame - 1);
    }
}

int main() {
    sliding_window_receiver();
    return 0;
}