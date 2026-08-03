#include<iostream>
#include<vector>
#include<typeinfo>
using namespace std;

class MediaFile{
public:
    virtual void play()=0;
    virtual string getInfo()=0;

    virtual ~MediaFile(){}
};

class AudioFile:public MediaFile{
public:
    void play()
    {
        cout<<"Playing Audio"<<endl;
    }

    string getInfo()
    {
        return "Audio File";
    }

    int getBitrate()
    {
        return 320;
    }
};

class VideoFile:public MediaFile{
public:
    void play()
    {
        cout<<"Playing Video"<<endl;
    }

    string getInfo()
    {
        return "Video File";
    }

    string getResolution()
    {
        return "1080p";
    }
};

class ImageFile:public MediaFile{
public:
    void play()
    {
        cout<<"Showing Image"<<endl;
    }

    string getInfo()
    {
        return "Image File";
    }
};

int main()
{
    vector<MediaFile*> v;

    v.push_back(new AudioFile);
    v.push_back(new VideoFile);
    v.push_back(new ImageFile);

    for(int i=0;i<v.size();i++)
    {
        cout<<typeid(*v[i]).name()<<endl;

        v[i]->play();

        cout<<v[i]->getInfo()<<endl;

        VideoFile *vid=dynamic_cast<VideoFile*>(v[i]);

        if(vid)
            cout<<"Resolution = "<<vid->getResolution()<<endl;

        AudioFile *aud=dynamic_cast<AudioFile*>(v[i]);

        if(aud)
            cout<<"Bitrate = "<<aud->getBitrate()<<endl;
    }

    for(int i=0;i<v.size();i++)
        delete v[i];

    return 0;
}

/*
typeid identifies object's actual type.
dynamic_cast safely converts pointer.
If conversion fails, it returns NULL.
*/