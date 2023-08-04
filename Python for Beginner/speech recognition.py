import speech_recognition as sr
import sys

rec = sr.Recognizer()

with sr.Microphone() as src:
    print("say something.....")
    while True:
        print("listening.....")
        audio = rec.listen(src)
        text = rec.recognize_google(audio)
        print(text)
        if text in ["hello" , "hi"]:
            print("Hi Trojan, How Are You?")
        elif text in ["fine", "iam fine " , "good" , "pretty good" , "great" , "i'm good"]:
            print("amazing nice to meet you bro")
        elif text in ["exit" , "close" , "enough"]:
            sys.exit()
        else:
            print("i do not understand")
