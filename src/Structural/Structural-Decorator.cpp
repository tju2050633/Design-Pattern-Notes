#include <iostream>
#include <string>
using namespace std;

// 实现书上的数据源模型
// 基础组件从磁盘读写数据，装饰器扩展其行为，允许写入磁盘时对数据加密和压缩、读出磁盘后对数据进行解压和解密

/* ********************************* */
// 客户端
/* ********************************* */
class DataSource;
class FileDataSource;
class DataSourceDecorator;
class EncryptionDecorator;
class CompressionDecorator;

/* ********************************* */
// 定义数据源继承体系
/* ********************************* */

class DataSource
{
public:
    virtual void writeData(string data) = 0;
    virtual ~DataSource() {}
    virtual string readData() = 0;
};

class FileDataSource : public DataSource
{
private:
    string filename;
    string data;

public:
    FileDataSource(string filename) : filename(filename) {}
    void writeData(string data)
    {
        cout << "Write data to file: " << filename << endl;
        this->data = data;
    }
    string readData()
    {
        cout << "Read data from file: " << filename << endl;
        return data;
    }
};

/* ********************************* */
// 定义装饰器继承体系（基础装饰器要继承自数据源接口）
/* ********************************* */

class DataSourceDecorator : public DataSource
{
protected:
    DataSource *wrappee;

public:
    DataSourceDecorator(DataSource *wrappee) : wrappee(wrappee) {}
    virtual ~DataSourceDecorator() {}
    void writeData(string data)
    {
        wrappee->writeData(data);
    }
    string readData()
    {
        return wrappee->readData();
    }
};

class EncryptionDecorator : public DataSourceDecorator
{
public:
    EncryptionDecorator(DataSource *wrappee) : DataSourceDecorator(wrappee) {}
    void writeData(string data)
    {
        cout << "Encrypt data" << endl;
        DataSourceDecorator::writeData(data);
    }
    string readData()
    {
        string data = DataSourceDecorator::readData();
        cout << "Decrypt data" << endl;
        return data;
    }
};

class CompressionDecorator : public DataSourceDecorator
{
public:
    CompressionDecorator(DataSource *wrappee) : DataSourceDecorator(wrappee) {}
    void writeData(string data)
    {
        cout << "Compress data" << endl;
        DataSourceDecorator::writeData(data);
    }
    string readData()
    {
        string data = DataSourceDecorator::readData();
        cout << "Decompress data" << endl;
        return data;
    }
};

/* ********************************* */
// 客户端
/* ********************************* */

int main()
{
    // 不使用装饰器
    cout << endl
         << "Without Decorator:" << endl
         << endl;
    DataSource *fileDataSource = new FileDataSource("demo_file");
    fileDataSource->writeData("data without decorator");
    fileDataSource->readData();

    // 使用装饰器
    cout << endl
         << "With Encryption Decorator:" << endl
         << endl;
    DataSource *encryptionDecorator = new EncryptionDecorator(fileDataSource);
    encryptionDecorator->writeData("data with encryption decorator");
    encryptionDecorator->readData();

    cout << endl
         << "With Compression Decorator:" << endl
         << endl;
    DataSource *compressionDecorator = new CompressionDecorator(fileDataSource);
    compressionDecorator->writeData("data with compression decorator");
    compressionDecorator->readData();

    cout << endl
         << "With Encryption and Compression Decorator:" << endl
         << endl;

    DataSource *encryptionAndCompressionDecorator = new CompressionDecorator(encryptionDecorator);
    encryptionAndCompressionDecorator->writeData("data with encryption and compression decorator");
    encryptionAndCompressionDecorator->readData();

    delete fileDataSource;
    delete encryptionDecorator;
    delete compressionDecorator;
    delete encryptionAndCompressionDecorator;

    return 0;
}