
import pyttsx3
name = input("what would you say?: ")
engine = pyttsx3.init()
engine.say(f"Hello {name}")
engine.runAndWait()