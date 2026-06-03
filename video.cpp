// Video Streaming Buffer Optimization using Queue (DSA)
// C++ Program

#include <iostream>
#include <queue>
#include <thread>
#include <chrono>

using namespace std;

class VideoStream {
private:
    queue<int> buffer;   // Queue for video packets
    int bufferSize;

public:
    VideoStream(int size) {
        bufferSize = size;
    }

    // Function to add packets into buffer
    void addPacket(int packet) {
        if (buffer.size() < bufferSize) {
            buffer.push(packet);
            cout << "Packet " << packet << " added to buffer." << endl;
        } else {
            cout << "Buffer Full! Packet " << packet << " dropped." << endl;
        }
    }

    // Function to play packets from buffer
    void playVideo() {
        if (!buffer.empty()) {
            cout << "Playing Packet: " << buffer.front() << endl;
            buffer.pop();
        } else {
            cout << "Buffer Empty! Video Buffering..." << endl;
        }
    }

    // Display current buffer
    void displayBuffer() {
        cout << "Current Buffer Size: " << buffer.size() << endl;
    }
};

int main() {

    VideoStream stream(5);

    // Simulating incoming packets
    for (int i = 1; i <= 7; i++) {
        stream.addPacket(i);
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    cout << "\nStarting Video Playback...\n" << endl;

    // Simulating video playback
    for (int i = 1; i <= 7; i++) {
        stream.playVideo();
        stream.displayBuffer();
        this_thread::sleep_for(chrono::milliseconds(1000));
    }

    return 0;
}