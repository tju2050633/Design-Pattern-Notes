package State.State;

import State.Context.AudioPlayer;

public class LockedState extends State {
    public LockedState(AudioPlayer player) {
        super(player);
    }

    @Override
    public void clickLock() {
        player.setState(new ReadyState(player));
    }

    @Override
    public void clickPlay() {
        // do nothing
    }

    @Override
    public void clickNext() {
        // do nothing
    }

    @Override
    public void clickPrevious() {
        // do nothing
    }
}
