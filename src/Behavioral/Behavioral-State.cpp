#include <iostream>
#include <string>
using namespace std;

/* ********************************* */
// 声明
/* ********************************* */

// 上下文
class AudioPlayer;

// 状态
class State;
class LockedState;
class ReadyState;
class PlayingState;

/* ********************************* */
// 定义
/* ********************************* */

class AudioPlayer {
  private:
    State *state;

  public:
    AudioPlayer();
    void changeState(State *s) { state = s; }
    void clickLock();
    void clickPlay();
    void clickNext();
    void clickPrevious();

    void startPlayback() { cout << "Start playback." << endl; }

    void stopPlayback() { cout << "Stop playback." << endl; }

    void nextSong() { cout << "Next song." << endl; }

    void previousSong() { cout << "Previous song." << endl; }
};

class State {
  protected:
    AudioPlayer *player;

  public:
    State(AudioPlayer *p) { player = p; }
    virtual ~State() {}
    virtual void clickLock() = 0;
    virtual void clickPlay() = 0;
    virtual void clickNext() = 0;
    virtual void clickPrevious() = 0;
};

class LockedState : public State {
  public:
    LockedState(AudioPlayer *p) : State(p) {}
    void clickLock();
    void clickPlay() { cout << "Locked. Do nothing." << endl; }
    void clickNext() { cout << "Locked. Do nothing." << endl; }
    void clickPrevious() { cout << "Locked. Do nothing." << endl; }
};

class ReadyState : public State {
  public:
    ReadyState(AudioPlayer *p) : State(p) {}
    void clickLock() { player->changeState(new LockedState(player)); }
    void clickPlay() { player->startPlayback(); }
    void clickNext() { player->nextSong(); }
    void clickPrevious() { player->previousSong(); }
};

class PlayingState : public State {
  public:
    PlayingState(AudioPlayer *p) : State(p) {}
    void clickLock() { player->changeState(new LockedState(player)); }
    void clickPlay() {
        player->stopPlayback();
        player->changeState(new ReadyState(player));
    }
    void clickNext() { player->nextSong(); }
    void clickPrevious() { player->previousSong(); }
};

void LockedState::clickLock() { player->changeState(new ReadyState(player)); }

AudioPlayer::AudioPlayer() { state = new ReadyState(this); }

void AudioPlayer::clickLock() { state->clickLock(); }

void AudioPlayer::clickPlay() { state->clickPlay(); }

void AudioPlayer::clickNext() { state->clickNext(); }

void AudioPlayer::clickPrevious() { state->clickPrevious(); }

int main() {
    AudioPlayer *player = new AudioPlayer();
    player->clickPlay();
    player->clickLock();
    player->clickPlay();
    player->clickLock();
    player->clickNext();
    player->clickPlay();
    player->clickPrevious();
    player->clickPlay();
    player->clickLock();

    return 0;
}