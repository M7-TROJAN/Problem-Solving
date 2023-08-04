
from pytube import YouTube
from tkinter import filedialog

url_input = input("Please Enter Your URL: ")
yt = YouTube(url_input)

# Get all available streams
all_streams = yt.streams.all()

# Print the available streams
for i, stream in enumerate(all_streams):
    print(f"{i}: {stream}")

# Ask the user to choose a stream
stm_input = int(input("Please Choose The Suitable Stream: "))

# Download the chosen stream to the chosen directory
folder_name = filedialog.askdirectory()
all_streams[stm_input].download(folder_name)
