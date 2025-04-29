Python 3.13.3 (tags/v3.13.3:6280bb5, Apr  8 2025, 14:47:33) [MSC v.1943 64 bit (AMD64)] on win32
Enter "help" below or click "Help" above for more information.
>>> 
==================================================================================== RESTART: Shell ====================================================================================
>>> import speech_recognition as sr
... import sys
... def reconnaitre_voix():
...     r = sr.Recognizer()
...     with sr.Microphone() as source:
...         print("Parlez maintenant...")
...         r.adjust_for_ambient_noise(source)
...         audio = r.listen(source)
... 
...     try:
...         texte = r.recognize_google(audio, language="fr-FR")
...         print("Texte reconnu :", texte)
...         return texte
...     except sr.UnknownValueError:
...         print("Impossible de reconnaître la voix")
...         return ""
...     except sr.RequestError as e:
...         print("Erreur du service Google Speech Recognition; {0}".format(e))
...         return ""
... 
... if __name__ == "__main__":
...     resultat = reconnaitre_voix()
...     print(resultat)
...     sys.stdout.flush()  # important pour que C++ puisse lire la sortie
>>> [DEBUG ON]
>>> [DEBUG OFF]
