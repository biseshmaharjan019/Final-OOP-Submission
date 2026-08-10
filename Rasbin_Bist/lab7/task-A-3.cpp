#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

class MediaFile {
public:
    std::string filename;

    MediaFile(std::string filename) : filename(filename) {}
    virtual void play() const = 0;
    virtual std::string getInfo() const = 0;
    virtual ~MediaFile() {
        std::cout << "Destroying: " << filename << "\n";
    }
};

class AudioFile : public MediaFile {
public:
    int duration;
    int bitrate;

    AudioFile(std::string filename, int duration, int bitrate)
        : MediaFile(filename), duration(duration), bitrate(bitrate) {}

    void play() const override {
        std::cout << "Playing audio: " << filename << " (" << duration << "s, " << bitrate << "kbps)\n";
    }

    std::string getInfo() const override {
        return "Audio | " + filename + " | " + std::to_string(duration) + "s | " + std::to_string(bitrate) + "kbps";
    }

    ~AudioFile() {
        std::cout << "AudioFile destructor: " << filename << "\n";
    }
};

class VideoFile : public MediaFile {
public:
    int duration;
    std::string resolution;

    VideoFile(std::string filename, int duration, std::string resolution)
        : MediaFile(filename), duration(duration), resolution(resolution) {}

    void play() const override {
        std::cout << "Playing video: " << filename << " (" << duration << "s, " << resolution << ")\n";
    }

    std::string getInfo() const override {
        return "Video | " + filename + " | " + std::to_string(duration) + "s | " + resolution;
    }

    ~VideoFile() {
        std::cout << "VideoFile destructor: " << filename << "\n";
    }
};

class ImageFile : public MediaFile {
public:
    int width;
    int height;

    ImageFile(std::string filename, int width, int height)
        : MediaFile(filename), width(width), height(height) {}

    void play() const override {
        std::cout << "Displaying image: " << filename << " (" << width << "x" << height << ")\n";
    }

    std::string getInfo() const override {
        return "Image | " + filename + " | " + std::to_string(width) + "x" + std::to_string(height);
    }

    ~ImageFile() {
        std::cout << "ImageFile destructor: " << filename << "\n";
    }
};

int main() {
    std::vector<MediaFile*> library;
    library.push_back(new AudioFile("song.mp3",   213, 320));
    library.push_back(new VideoFile("movie.mp4", 7200, "1920x1080"));
    library.push_back(new ImageFile("photo.jpg", 4000, 3000));

    for (MediaFile* ptr : library) {
        std::cout << "Runtime type: " << typeid(*ptr).name() << "\n";

        ptr->play();
        std::cout << "Info: " << ptr->getInfo() << "\n";

        VideoFile* vf = dynamic_cast<VideoFile*>(ptr);
        if (vf != nullptr) {
            std::cout << "Resolution: " << vf->resolution << "\n";
        }

        AudioFile* af = dynamic_cast<AudioFile*>(ptr);
        if (af != nullptr) {
            std::cout << "Bitrate: " << af->bitrate << " kbps\n";
        }

        std::cout << "\n";
    }

    for (MediaFile* ptr : library) {
        delete ptr;
    }
    library.clear();

    return 0;
}