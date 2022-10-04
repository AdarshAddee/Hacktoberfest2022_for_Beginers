# Hey Guys, I'm Ratnesh 
# This code will help you to build your own virtual assistant


import speech_recognition as sr
r = sr.Recognizer()

with sr.Microphone() as source:
    print("Say something!")
    audio = r.listen(source)

try:
    print("Did you say: " + r.recognize_google(audio))
except sr.UnknownValueError:
    print("Google Speech Recognition could not understand audio")
except sr.RequestError as e:
    print("Could not request results from Google Speech Recogniton service; {0}".format(e))