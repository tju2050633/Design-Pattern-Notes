package State;

import State.State.*;
import State.Context.AudioPlayer;

public class StateTest {
    public static void main(String[] args) {
        AudioPlayer player = new AudioPlayer();
        player.clickPlay();
        player.clickLock();
        player.clickPlay();
        player.clickLock();
        player.clickNext();
        player.clickPlay();
        player.clickPrevious();
        player.clickPlay();
        player.clickLock();
    }
}
