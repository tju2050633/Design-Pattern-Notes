#include <iostream>
#include <string>
using namespace std;

// 抄一遍书上的视频转换案例
// 老版本笔记是3个抽象的子系统，分别有3个方法，被外观类逐一调用

/* ********************************* */
// 声明
/* ********************************* */

// 框架类
class VideoFile;
class OggCompressionCodec;
class MPEG4CompressionCodec;
class CodecFactory;
class BitrateReader;
class AudioMixer;

// 外观类
class VideoConverter;

/* ********************************* */
// 定义
/* ********************************* */

class VideoFile {
private:
    string filename;

public:
    VideoFile(string filename) {
        cout << "Creating VideoFile object with filename: " << filename << endl;
        this->filename = filename;
    }

    string getCodecType() {
        size_t pos = filename.find_last_of(".");
        if (pos != string::npos) {
            return filename.substr(pos + 1);
        }
        return "";
    }
};

class OggCompressionCodec {
public:
    OggCompressionCodec() {
        cout << "Creating OggCompressionCodec object" << endl;
    }
};

class MPEG4CompressionCodec {
public:
    MPEG4CompressionCodec() {
        cout << "Creating MPEG4CompressionCodec object" << endl;
    }
};

class CodecFactory {
public:
    CodecFactory(string format) {
        cout << "Creating CodecFactory object with format: " << format << endl;
    }

    OggCompressionCodec* createOggCompressionCodec() {
        cout << "Creating OggCompressionCodec object" << endl;
        return new OggCompressionCodec();
    }

    MPEG4CompressionCodec* createMPEG4CompressionCodec() {
        cout << "Creating MPEG4CompressionCodec object" << endl;
        return new MPEG4CompressionCodec();
    }
};

class BitrateReader {
public:
    static VideoFile* read(VideoFile* file, CodecFactory* codec) {
        cout << "Reading VideoFile object with codec type: " << file->getCodecType() << endl;
        return file;
    }

    static VideoFile* convert(VideoFile* buffer, CodecFactory* codec) {
        cout << "Converting VideoFile object with codec type: " << codec->createMPEG4CompressionCodec() << endl;
        return buffer;
    }
};

class AudioMixer {
public:
    string fix(VideoFile* file) {
        cout << "Fixing VideoFile object" << endl;
        return "Fixed " + file->getCodecType() + " file";
    }
};

class VideoConverter
{
public:
    string convert(string filename, string format)
    {
        VideoFile* file = new VideoFile(filename);
        CodecFactory* sourceCodec = new CodecFactory(file->getCodecType());
        CodecFactory* destinationCodec = new CodecFactory(format);
        VideoFile* buffer = BitrateReader::read(file, sourceCodec);
        VideoFile* intermediateResult = BitrateReader::convert(buffer, destinationCodec);
        string result = (new AudioMixer())->fix(intermediateResult);

        delete file;
        delete sourceCodec;
        delete destinationCodec;
        
        return result;
    }
};

int main() 
{
    VideoConverter* converter = new VideoConverter();
    string result = converter->convert("funny-cats-video.ogg", "mp4");
    cout << "result : " << result << endl;

    delete converter;

    return 0;
}