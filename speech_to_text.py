import speech_recognition as sr

def reconnaitre_voix():
    r = sr.Recognizer()
    with sr.Microphone() as source:
        r.adjust_for_ambient_noise(source)
        try:
            audio = r.listen(source, timeout=5)
            texte = r.recognize_google(audio, language="fr-FR")
            print(texte)
        except sr.WaitTimeoutError:
            print("Aucun son détecté.")
        except sr.UnknownValueError:
            print("impossible de reconnaitre ta voix")
        except sr.RequestError as e:
            print(f"Erreur du service de reconnaissance vocale : {e}")

if __name__ == "__main__":
    reconnaitre_voix()
