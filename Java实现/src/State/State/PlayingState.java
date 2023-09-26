package State.State;

import State.Context.AudioPlayer;

public class PlayingState extends State {
    public PlayingState(AudioPlayer player) {
        super(player);
    }

    @Override
    public void clickLock() {
        player.setState(new LockedState(player));
    }

    @Override
    public void clickPlay() {
        player.stopPlaying();
        player.setState(new ReadyState(player));
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
