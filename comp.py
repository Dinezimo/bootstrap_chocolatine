import speech_recognition as sr
import subprocess

recognizer = sr.Recognizer()
acces_token = "EAAPTEGWZCoNYBOZChjIrFt5DkX6VTHYV0WxZAwEpkfbT1QISZBE8hGGO5zSZCAEO8ZBwWYBaZACRwJD67NHlhpj7KlXDQIZCAgZCZBzRVyJCCEbzDkVRvzD2aIEMCbweqD1DbUe2OZAm2Pqv0C5YH0bWsCA9AZCz9Tk4OLQNPwTJ38xxMX9r8FnbFgngj0p5UciK8p1LEZA9mwzdAPjMkhQNnMbmme1TaBFZA3JsZCkyJWBsfIP2qkZBN5D2HZAmnNjyPbnsYjtxvBGampZA0ZD"
def record_audio():
    with sr.Microphone() as source:
        audio = recognizer.listen(source)
    return audio

def recognize_speech(audio):
    text = recognizer.recognize_google(audio)
    print(text)
    if (text == "ls"):
        cmd = "/bin/ls"
    if (text == "cd"):
        print("quelle est votre path ?")
        dest = recognizer.recognize_google(record_audio())
        cmd = "cd " + dest
    if (text == "push in github"):
        print("quelle commit souhaitez-vous utiliser ?")
        commit = recognizer.recognize_google(record_audio())
        cmd = "git add . ; git commit -m \" " + commit + "\" ; git push; clear"
    else:
        cmd = ""
    return cmd

def publish_to_facebook(message, access_token):
    graph = facebook.GraphAPI(access_token)
    try:
        graph.put_object("me", "feed", message=message)
        print("Message publié avec succès sur Facebook.")
    except facebook.GraphAPIError as e:
        print(f"Erreur lors de la publication sur Facebook : {e}")

def run_command(command):
    process = subprocess.Popen(command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    output, error = process.communicate()
    if output:
        print(output.decode("utf-8"))
    if error:
        print(error.decode("utf-8"))
    print("\nCommande exécuté avec succès. Avez vous envie de partager l'expérience sur la page officielle de Vocal-compilator Jam epitech ?")
    x = input()lower()
    if (x == oui):
        printf("quelle ");

if __name__ == "__main__":
    print("Que dois je exécuter ?")
    audio = record_audio()
    print("je suis blocké")
    cmd = recognize_speech(audio)
    if (cmd != ""):
        run_command(cmd)
    else:
        print("excuse us, this cmmand had not been manage... Try to une another");
