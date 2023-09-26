package State.Context;

import State.State.State;
import State.State.ReadyState;

public class AudioPlayer {
    private State state;

    public AudioPlayer() {
        state = new ReadyState(this);
    }

    public void setState(State state) {
        this.state = state;
    }

    public void clickLock() {
        state.clickLock();
    }

    public void clickPlay() {
        state.clickPlay();
    }

    public void clickNext() {
        state.clickNext();
    }

    public void clickPrevious() {
        state.clickPrevious();
    }

    public void startPlaying() {
        System.out.println("Start playing");
    }

    public void stopPlaying() {
        System.out.println("Stop playing");
    }

    public void nextSong() {
        System.out.println("Next song");
    }

    public void previousSong() {
        System.out.println("Previous song");
    }
}
