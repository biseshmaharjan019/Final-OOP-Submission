#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
using namespace std;
class MediaFile {
public:
    virtual void play() = 0;
    virtual string getInfo() = 0;
    virtual ~MediaFile() {
        cout << "MediaFile Destructor" << endl;
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
    void play() {
        cout << "Playing Audio File..." << endl;
    }
    string getInfo() {
        return "Audio File | Duration: " + to_string(duration) +
               " sec | Bitrate: " + to_string(bitrate) + " kbps";
    }
    int getBitrate() {
        return bitrate;
    }
    ~AudioFile() {
        cout << "AudioFile Destructor" << endl;
    }
};
class VideoFile : public MediaFile {
private:
    int duration;
    string resolution;
public:
    VideoFile(int d, string r) {
        duration = d;
        resolution = r;
    }
    void play() {
        cout << "Playing Video File..." << endl;
    }
    string getInfo() {
        return "Video File | Duration: " + to_string(duration) +
               " sec | Resolution: " + resolution;
    }
    string getResolution() {
        return resolution;
    }
    ~VideoFile() {
        cout << "VideoFile Destructor" << endl;
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
    void play() {
        cout << "Displaying Image File..." << endl;
    }
    string getInfo() {
        return "Image File | Width: " + to_string(width) +
               " px | Height: " + to_string(height) + " px";
    }
    ~ImageFile() {
        cout << "ImageFile Destructor" << endl;
    }
};
int main() {
    vector<MediaFile*> media;
    media.push_back(new AudioFile(240, 320));
    media.push_back(new VideoFile(600, "1920x1080"));
    media.push_back(new ImageFile(1920, 1080));
    for (int i = 0; i < media.size(); i++) {
        cout << "\nMedia File " << i + 1 << endl;
        cout << "Runtime Type: " << typeid(*media[i]).name() << endl;
        media[i]->play();
        cout << media[i]->getInfo() << endl;
        AudioFile *a = dynamic_cast<AudioFile*>(media[i]);
        if (a != NULL) {
            cout << "Bitrate: " << a->getBitrate() << " kbps" << endl;
        }
        VideoFile *v = dynamic_cast<VideoFile*>(media[i]);
        if (v != NULL) {
            cout << "Resolution: " << v->getResolution() << endl;
        }
    }
    cout << "\nDeleting Objects..." << endl;
    for (int i = 0; i < media.size(); i++) {
        delete media[i];
    }
    media.clear();
    return 0;
}

