#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
using namespace std;

class MediaFile {
public:
    virtual void play() = 0;
    virtual string getInfo() = 0;
    virtual ~MediaFile() {}
};

class AudioFile : public MediaFile {
private:
    int duration;
    int bitrate;
public:
    AudioFile(int d, int b) : duration(d), bitrate(b) {}
    void play() override {
        cout << "Playing Audio File..." << endl;
    }
    string getInfo() override {
        return "Audio Duration: " + to_string(duration) + "s, Bitrate: " + to_string(bitrate) + " kbps";
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
    VideoFile(int d, string r) : duration(d), resolution(r) {}
    void play() override {
        cout << "Playing Video File..." << endl;
    }
    string getInfo() override {
        return "Video Duration: " + to_string(duration) + "s, Resolution: " + resolution;
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
    ImageFile(int w, int h) : width(w), height(h) {}
    void play() override {
        cout << "Displaying Image File..." << endl;
    }
    string getInfo() override {
        return "Image Dimensions: " + to_string(width) + "x" + to_string(height) + " px";
    }
};

int main() {
    vector<MediaFile*> mediaList;
    mediaList.push_back(new AudioFile(210, 320));
    mediaList.push_back(new VideoFile(7200, "1920x1080"));
    mediaList.push_back(new ImageFile(3840, 2160));

    for (MediaFile* media : mediaList) {
        cout << "\nRuntime type: " << typeid(*media).name() << endl;
        media->play();
        cout << media->getInfo() << endl;

        VideoFile* vid = dynamic_cast<VideoFile*>(media);
        if (vid) {
            cout << "Extracted Resolution: " << vid->getResolution() << endl;
        }

        AudioFile* aud = dynamic_cast<AudioFile*>(media);
        if (aud) {
            cout << "Extracted Bitrate: " << aud->getBitrate() << " kbps" << endl;
        }
    }

    for (MediaFile* media : mediaList) {
        delete media;
    }
    mediaList.clear();

    return 0;
}