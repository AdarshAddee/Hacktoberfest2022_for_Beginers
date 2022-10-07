# Hey Guys, I'm Ratnesh 
# This code will help you to download videos from YouTube

from pytube import YouTube # Install pytube by using "pip install pytube command"
link=str(input("Enter yt video link: "))
yt=YouTube(link)
name=str(input("Enter vid name here: "))
try:
    yt.streams.filter(progressive=True,file_extension="mp4").first().download(output_path="E:\YT vid",filename=name)
except:
    print("Some Error!")
print('Task Completed')