package Adapter.MediaPlayer;

// 原本的MediaPlayer只能播放mp3，但是现在要求它能够播放mp3、mp4、vlc等格式的音频文件
// 为了实现这个功能，我们需要一个适配器，这个适配器能够将MediaPlayer的接口转换成AdvancedMediaPlayer的接口
// 使用依赖，AudioPlayer含有MediaAdapter，MediaAdapter含有AdvancedMediaPlayer

public class AudioPlayer implements MediaPlayer {
    MediaAdapter mediaAdapter;

    @Override
    public void play(String audioType, String fileName){
        // inbuilt support to play mp3 music files
        if(audioType.equalsIgnoreCase("mp3")){
            System.out.println("Playing mp3 file. Name: " + fileName);
        }
        // mediaAdapter is providing support to play other file formats
        else if(audioType.equalsIgnoreCase("vlc") || audioType.equalsIgnoreCase("mp4")){
            mediaAdapter = new MediaAdapter(audioType);
            mediaAdapter.play(audioType, fileName);
        }
        else{
            System.out.println("Invalid media. " + audioType + " format not supported");
        }
    }
}
