#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
using namespace std;

class MediaFile {
public:
    virtual void play() const = 0;
    virtual string getInfo() const = 0;

    virtual ~MediaFile() {
        cout << "MediaFile destroyed." << endl;
    }
};

class AudioFile : public MediaFile {
private:
    int duration;
    int bitrate;

public:
    AudioFile(int d, int b) {
        duration = d;
        bitrate = b;
    }

    void play() const override {
        cout << "Playing audio track..." << endl;
    }

    string getInfo() const override {
        return "Audio File | Duration: " + to_string(duration) + "s | Bitrate: " + to_string(bitrate) + " kbps";
    }

    int getBitrate() const {
        return bitrate;
    }
};

class VideoFile : public MediaFile {
private:
    int duration;
    string resolution;

public:
    VideoFile(int d, string res) {
        duration = d;
        resolution = res;
    }

    void play() const override {
        cout << "Playing video track..." << endl;
    }

    string getInfo() const override {
        return "Video File | Duration: " + to_string(duration) + "s | Resolution: " + resolution;
    }

    string getResolution() const {
        return resolution;
    }
};

class ImageFile : public MediaFile {
private:
    int width;
    int height;

public:
    ImageFile(int w, int h) {
        width = w;
        height = h;
    }

    void play() const override {
        cout << "Displaying image file..." << endl;
    }

    string getInfo() const override {
        return "Image File | Dimensions: " + to_string(width) + "x" + to_string(height);
    }
};

int main() {
    vector<MediaFile*> mediaList;

    mediaList.push_back(new AudioFile(210, 320));
    mediaList.push_back(new VideoFile(7200, "1920x1080"));
    mediaList.push_back(new ImageFile(3840, 2160));

    for (size_t i = 0; i < mediaList.size(); i++) {
        cout << "\n--- Item " << i + 1 << " ---" << endl;
        cout << "Type Name: " << typeid(*mediaList[i]).name() << endl;

        mediaList[i]->play();
        cout << mediaList[i]->getInfo() << endl;

        VideoFile* video = dynamic_cast<VideoFile*>(mediaList[i]);
        if (video) {
            cout << "Extracted Resolution: " << video->getResolution() << endl;
        }

        AudioFile* audio = dynamic_cast<AudioFile*>(mediaList[i]);
        if (audio) {
            cout << "Extracted Bitrate: " << audio->getBitrate() << " kbps" << endl;
        }
    }

    cout << "\n--- Cleaning up memory ---" << endl;
    for (size_t i = 0; i < mediaList.size(); i++) {
        delete mediaList[i];
    }
    mediaList.clear();

    return 0;
}

/*
 * EXPLANATION: DIFFERENCE BETWEEN typeid AND dynamic_cast
 * 
 * 1. typeid:
 *    - Used to identify the exact type of an expression at runtime.
 *    - Returns a reference to a type_info object containing type metadata.
 *    - Does not perform type conversion.
 * 
 * 2. dynamic_cast:
 *    - Used to safely navigate polymorphic class hierarchies via downcasting/crosscasting.
 *    - Converts base class pointers to derived class pointers safely.
 *    - Returns nullptr if the conversion fails rather than throwing an unhandled exception or corrupting memory.
 */
