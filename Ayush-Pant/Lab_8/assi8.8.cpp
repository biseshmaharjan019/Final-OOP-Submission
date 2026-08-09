#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <typeinfo>
using namespace std;

class MediaFile
{
public:
    virtual void play() = 0;
    virtual string getInfo() = 0;

    virtual ~MediaFile()
    {
        cout << "MediaFile Destructor" << endl;
    }
};

class AudioFile : public MediaFile
{
    int duration;
    int bitrate;

public:
    AudioFile(int d, int b)
    {
        duration = d;
        bitrate = b;
    }

    void play()
    {
        cout << "Playing Audio File" << endl;
    }

    string getInfo()
    {
        stringstream ss;
        ss << "Audio Duration: " << duration << " sec, Bitrate: " << bitrate;
        return ss.str();
    }

    int getBitrate()
    {
        return bitrate;
    }

    ~AudioFile()
    {
        cout << "AudioFile Destructor" << endl;
    }
};

class VideoFile : public MediaFile
{
    int duration;
    string resolution;

public:
    VideoFile(int d, string r)
    {
        duration = d;
        resolution = r;
    }

    void play()
    {
        cout << "Playing Video File" << endl;
    }

    string getInfo()
    {
        stringstream ss;
        ss << "Video Duration: " << duration << " sec, Resolution: " << resolution;
        return ss.str();
    }

    string getResolution()
    {
        return resolution;
    }

    ~VideoFile()
    {
        cout << "VideoFile Destructor" << endl;
    }
};

class ImageFile : public MediaFile
{
    int width;
    int height;

public:
    ImageFile(int w, int h)
    {
        width = w;
        height = h;
    }

    void play()
    {
        cout << "Displaying Image" << endl;
    }

    string getInfo()
    {
        stringstream ss;
        ss << "Image: " << width << " x " << height;
        return ss.str();
    }

    ~ImageFile()
    {
        cout << "ImageFile Destructor" << endl;
    }
};

int main()
{
    vector<MediaFile *> files;

    files.push_back(new AudioFile(180, 320));
    files.push_back(new VideoFile(600, "1920x1080"));
    files.push_back(new ImageFile(1024, 768));

    for (int i = 0; i < files.size(); i++)
    {
        cout << "Runtime Type: " << typeid(*files[i]).name() << endl;

        files[i]->play();
        cout << files[i]->getInfo() << endl;

        VideoFile *v = dynamic_cast<VideoFile *>(files[i]);
        if (v != NULL)
            cout << "Resolution: " << v->getResolution() << endl;

        AudioFile *a = dynamic_cast<AudioFile *>(files[i]);
        if (a != NULL)
            cout << "Bitrate: " << a->getBitrate() << endl;

        cout << endl;
    }

    for (int i = 0; i < files.size(); i++)
        delete files[i];

    return 0;
}
