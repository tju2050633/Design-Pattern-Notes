package State.State;

import State.Context.AudioPlayer;

public class ReadyState extends State {
    public ReadyState(AudioPlayer player) {
        super(player);
    }

    @Override
    public void clickLock() {
        player.setState(new LockedState(player));
    }

    @Override
    public void clickPlay() {
        player.startPlaying();
        player.setState(new PlayingState(player));
    }

    @Override
    public void clickNext() {
        player.nextSong();
    }

    @Override
    public void clickPrevious() {
        player.previousSong();
    }
}
