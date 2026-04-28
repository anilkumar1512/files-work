#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEQ 7
#define BUFFER_SIZE 1

typedef struct {
    int seq;
    char data[BUFFER_SIZE];
} Frame;

void send_frame(Frame frame) {
    printf("Sending frame with sequence number: %d\n", frame.seq);
}

void sliding_window_sender(char *message) {
    int next_frame_to_send = 0;
    int ack_expected = 0;
    int buffer_size = strlen(message);

    while (ack_expected < buffer_size) {
        for (int i = 0; i < MAX_SEQ && next_frame_to_send < buffer_size; i++) {
            Frame frame;
            frame.seq = next_frame_to_send % (MAX_SEQ + 1);
            strncpy(frame.data, &message[next_frame_to_send], BUFFER_SIZE);
            send_frame(frame);
            next_frame_to_send++;
        }

        ack_expected++;

        while (ack_expected < next_frame_to_send) {
            printf("Acknowledgment received for frame with sequence number: %d\n", ack_expected);
            ack_expected++;
        }
    }
}

int main() {
    char message[] = "This is a test message for the sliding window protocol.";
    sliding_window_sender(message);
    return 0;
}
