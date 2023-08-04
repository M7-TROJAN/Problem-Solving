from pytube import Playlist

link = input("Enter YouTube Playlist URL: ")

yt_playlist = Playlist(link)
path = r"C:\Users\matte\Desktop\New"

i = 1
for video in yt_playlist.videos:
    # Download Normally
    # video.streams.get_lowest_resolution().download(output_path=path)
    # Download videos in series
    video.streams.get_lowest_resolution().download(output_path=path, filename=str(i)+" "+video.title+".mp4")
    print("Video Downloaded: ", video.title)
    i=i+1

print("\nAll videos are downloaded.")


