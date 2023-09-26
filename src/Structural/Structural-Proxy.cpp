#include <iostream>
#include <string>
using namespace std;

// 实现书上腾讯视频库下载的案例

/* ********************************* */
// 声明
/* ********************************* */

class ThirdPartyTVLib;
class ThirdPartyTVClass;
class CachedTVClass;
class TVManager;

/* ********************************* */
// 定义
/* ********************************* */

// 第三方视频库接口（远程服务接口）
class ThirdPartyTVLib
{
public:
    virtual void listVideos() = 0;
    virtual void getVideoInfo(string id) = 0;
    virtual void downloadVideo(string id) = 0;
};

// 第三方视频库实现（服务连接器的具体实现）
// 客户端直接使用该类会有性能问题（每次都要连接远程服务）
class ThirdPartyTVClass : public ThirdPartyTVLib
{
public:
    void listVideos() override
    {
        cout << "send listVideos request" << endl;
    }
    void getVideoInfo(string id) override
    {
        cout << "send getVideoInfo request" << endl;
    }
    void downloadVideo(string id) override
    {
        cout << "send downloadVideo request" << endl;
    }
};

// 本地缓存视频库（代理类）
class CachedTVClass : public ThirdPartyTVLib
{
private:
    ThirdPartyTVLib *m_service;
    string m_listVideosCache;
    string m_videoInfoCache;
    string m_videoCache;

public:
    CachedTVClass(ThirdPartyTVLib *service) : m_service(service) {}
    void listVideos() override
    {
        if (m_listVideosCache.empty())
        {
            m_service->listVideos();
            m_listVideosCache = "listVideos cache";
        }
        else
        {
            cout << "return listVideos cache" << endl;
        }
    }
    void getVideoInfo(string id) override
    {
        if (m_videoInfoCache.empty())
        {
            m_service->getVideoInfo(id);
            m_videoInfoCache = "getVideoInfo cache";
        }
        else
        {
            cout << "return getVideoInfo cache" << endl;
        }
    }
    void downloadVideo(string id) override
    {
        if (m_videoCache.empty())
        {
            m_service->downloadVideo(id);
            m_videoCache = "downloadVideo cache";
        }
        else
        {
            cout << "return downloadVideo cache" << endl;
        }
    }
};

// 本地视频库管理器（客户端）
class TVManager
{
private:
    ThirdPartyTVLib *m_service;

public:
    TVManager(ThirdPartyTVLib *service) : m_service(service) {}
    void renderVideoPage(string id)
    {
        m_service->listVideos();
        m_service->getVideoInfo(id);
        m_service->downloadVideo(id);
    }
};

int main()
{
    ThirdPartyTVLib *service = new ThirdPartyTVClass();
    CachedTVClass *proxy = new CachedTVClass(service);
    TVManager *manager = new TVManager(proxy);
    manager->renderVideoPage("1");
    manager->renderVideoPage("2");

    delete service;
    delete proxy;
    delete manager;

    return 0;
}