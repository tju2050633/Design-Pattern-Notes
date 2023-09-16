#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 实现书上的微信社交网络例子
// friends迭代器遍历好友，colleagues迭代器遍历同事

/* ********************************* */
// 声明
/* ********************************* */

class Profile;
class ProfileIterator;
class SocialNetwork;
class WeChat;
class WeChatIterator;
class SocialSpammer;
class Application;

/* ********************************* */
// 定义
/* ********************************* */

// 用户信息
class Profile {
private:
    string id_;
    string name_;
    string email_;

public:
    Profile(string id, string name, string email) : id_(id), name_(name), email_(email) {}
    string getId() { return id_; }
    string getName() { return name_; }
    string getEmail() { return email_; }
};

// 迭代器接口
class ProfileIterator {
public:
    virtual ~ProfileIterator() {}
    virtual bool hasNext() = 0;
    virtual Profile getNext() = 0;
};

// 具体迭代器
class WeChatIterator : public ProfileIterator {
private:
    WeChat* wechat_;
    string profileId_;
    string type_;
    int currentPosition_;
    vector<Profile> cache_;

public:
    WeChatIterator(WeChat* wechat, string profileId, string type) : wechat_(wechat), profileId_(profileId), type_(type) {}
    bool hasNext() override {
        lazyInit();
        return currentPosition_ < cache_.size();
    }
    Profile getNext() override {
        if (!hasNext()) {
            throw new std::exception();
        }
        return cache_[currentPosition_++];
    }
    void lazyInit() {
        if (cache_.empty()) {
            vector<Profile> profiles = sendQuery(profileId_, type_);
            for (auto& profile : profiles) {
                cache_.push_back(profile);
            }
        }
    }
    vector<Profile> sendQuery(string profileId, string type) {
        // 模拟查询
        vector<Profile> profiles;
        return profiles;
    }
};

// 集合接口声明生成迭代器的工厂方法，用于生成不同类型的迭代器
class SocialNetwork {
public:
    virtual ~SocialNetwork() {}
    virtual ProfileIterator* createFriendsIterator(string profileId) = 0;
    virtual ProfileIterator* createColleaguesIterator(string profileId) = 0;
};

class WeChat : public SocialNetwork {
public:
    WeChat() {}
    ~WeChat() {}
    ProfileIterator* createFriendsIterator(string profileId) override {
        return new WeChatIterator(this, profileId, "friends");
    }
    ProfileIterator* createColleaguesIterator(string profileId) override {
        return new WeChatIterator(this, profileId, "colleagues");
    }
};


int main()
{
    return 0;
}