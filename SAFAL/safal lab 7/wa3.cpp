#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;
class MediaFile
{
public:
    virtual void play()=0;
    virtual string getInfo()=0;

    virtual ~MediaFile()
    {
        cout<<"MediaFile Destructor"<<endl;
    }
};
class AudioFile : public MediaFile
{
    int duration;
    int bitrate;

public:
    AudioFile(int d,int b):duration(d),bitrate(b){}

    void play() override
    {
        cout<<"Playing Audio"<<endl;
    }

    string getInfo() override
    {
        return "Duration: "+to_string(duration)+" Bitrate: "+to_string(bitrate);
    }
    int getBitrate()
    {
        return bitrate;
    }

    ~AudioFile()
    {
        cout<<"AudioFile Destructor"<<endl;
    }
};

class VideoFile : public MediaFile
{
    int duration;
    string resolution;

public:
    VideoFile(int d,string r):duration(d),resolution(r){}

    void play() override
    {
        cout<<"Playing Video"<<endl;
    }
    string getInfo() override
    {
        return "Duration: "+to_string(duration)+" Resolution: "+resolution;
    }
    string getResolution()
    {
        return resolution;
    }
    ~VideoFile()
    {
        cout<<"VideoFile Destructor"<<endl;
    }
};
class ImageFile : public MediaFile
{
    int width;
    int height;
public:
    ImageFile(int w,int h):width(w),height(h){}

    void play() override
    {
        cout<<"Displaying Image"<<endl;
    }
    string getInfo() override
    {
        return "Size: "+to_string(width)+"x"+to_string(height);
    }
    ~ImageFile()
    {
        cout<<"ImageFile Destructor"<<endl;
    }
};
int main()
{
    vector<MediaFile*> files;
    files.push_back(new AudioFile(240,320));
    files.push_back(new VideoFile(600,"1920x1080"));
    files.push_back(new ImageFile(1024,768));
    for(MediaFile* ptr:files)
    {
        cout<<typeid(*ptr).name()<<endl;
        ptr->play();
        cout<<ptr->getInfo()<<endl;
        VideoFile* v=dynamic_cast<VideoFile*>(ptr);
        if(v)
            cout<<"Resolution: "<<v->getResolution()<<endl;
        AudioFile* a=dynamic_cast<AudioFile*>(ptr);
        if(a)
            cout<<"Bitrate: "<<a->getBitrate()<<endl;
    }
    for(MediaFile* ptr:files)
        delete ptr;
    files.clear();
    return 0;
}
