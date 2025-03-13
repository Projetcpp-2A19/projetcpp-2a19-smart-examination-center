import sys
import json
from vosk import Model, KaldiRecognizer
import pyaudio

def recognize_speech(model_path):
    model = Model(model_path)
    rec = KaldiRecognizer(model, 16000)

    p = pyaudio.PyAudio()
    stream = p.open(format=pyaudio.paInt16, channels=1, rate=16000, input=True, frames_per_buffer=8192)
    stream.start_stream()

    print("Listening...")

    while True:
        data = stream.read(4096)
        if len(data) == 0:
            break
        if rec.AcceptWaveform(data):
            result = rec.Result()
            result_dict = json.loads(result)
            text = result_dict.get("text", "")
            if text:
                print(text)  # Ensure this line is present
                sys.stdout.flush()  # Flush the output

    stream.stop_stream()
    stream.close()
    p.terminate()

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python speech_to_text.py <model_path>")
        sys.exit(1)

    model_path = sys.argv[1]
    recognize_speech(model_path)
