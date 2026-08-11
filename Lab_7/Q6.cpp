#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
using namespace std;

class MediaFile {
public:
    virtual void play() = 0;
    virtual string getInfo() = 0;
    virtual ~MediaFile() {
        cout << "[Destructor] MediaFile cleaned up" << endl;
    }
};

class AudioFile : public MediaFile {
private:
    int duration; // seconds
    int bitrate;  // kbps

public:
    AudioFile(int d, int b) : duration(d), bitrate(b) {}

    void play() override {
        cout << "Playing audio track..." << endl;
    }

    string getInfo() override {
        return "Audio [Duration: " + to_string(duration) + "s, Bitrate: " + to_string(bitrate) + " kbps]";
    }

    int getBitrate() const {
        return bitrate;
    }

    ~AudioFile() override {
        cout << "[Destructor] AudioFile cleaned up" << endl;
    }
};

class VideoFile : public MediaFile {
private:
    int duration;      // seconds
    string resolution; // e.g. "1920x1080"

public:
    VideoFile(int d, string res) : duration(d), resolution(res) {}

    void play() override {
        cout << "Rendering video stream..." << endl;
    }

    string getInfo() override {
        return "Video [Duration: " + to_string(duration) + "s, Resolution: " + resolution + "]";
    }

    string getResolution() const {
        return resolution;
    }

    ~VideoFile() override {
        cout << "[Destructor] VideoFile cleaned up" << endl;
    }
};

class ImageFile : public MediaFile {
private:
    int width, height;

public:
    ImageFile(int w, int h) : width(w), height(h) {}

    void play() override {
        cout << "Displaying static image on canvas..." << endl;
    }

    string getInfo() override {
        return "Image [Dimensions: " + to_string(width) + "x" + to_string(height) + " px]";
    }

    ~ImageFile() override {
        cout << "[Destructor] ImageFile cleaned up" << endl;
    }
};

int main() {
    vector<MediaFile*> playlist;
    playlist.push_back(new AudioFile(210, 320));
    playlist.push_back(new VideoFile(7200, "3840x2160"));
    playlist.push_back(new ImageFile(1920, 1080));

    for (size_t i = 0; i < playlist.size(); i++) {
        cout << "=== Media Item " << (i + 1) << " ===" << endl;

        // (a) typeid(*ptr).name()
        cout << "Type ID         : " << typeid(*playlist[i]).name() << endl;

        // (b) Call play() and getInfo()
        playlist[i]->play();
        cout << "Info Summary    : " << playlist[i]->getInfo() << endl;

        // (c) dynamic_cast to VideoFile*
        VideoFile* videoPtr = dynamic_cast<VideoFile*>(playlist[i]);
        if (videoPtr != nullptr) {
            cout << "Video Resolution: " << videoPtr->getResolution() << endl;
        }

        // (d) dynamic_cast to AudioFile*
        AudioFile* audioPtr = dynamic_cast<AudioFile*>(playlist[i]);
        if (audioPtr != nullptr) {
            cout << "Audio Bitrate   : " << audioPtr->getBitrate() << " kbps" << endl;
        }

        cout << endl;
    }

    cout << "--- Reclaiming Memory ---" << endl;
    for (MediaFile* item : playlist) {
        delete item; // Triggers virtual destructor chain
    }
    playlist.clear();

    cout << "\nPress Enter to exit...";
    cin.get();
    return 0;
}