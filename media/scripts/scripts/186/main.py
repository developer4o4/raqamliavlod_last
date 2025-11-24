import requests
import threading
from bs4 import BeautifulSoup

def process():
    session = requests.Session()

    session.cookies.set("sessionid", "i7joonfku4xxvx5kwrp3olkh9tysx7g8")

    get_response = session.get('https://raqamliavlod.uz/kontest/masala/5/')

    if get_response.status_code == 200:
        soup = BeautifulSoup(get_response.text, 'html.parser')
        csrf_token = soup.find('input', {'name': 'csrfmiddlewaretoken'})['value']

        post_data = {
            'csrfmiddlewaretoken': csrf_token,
            'language': 'Python',
        }
        post_file = {
            'script': open('ex.py', 'r')
        }

        post_response = session.post('https://raqamliavlod.uz/kontest/masala/5/', data=post_data, files=post_file)

        if post_response.status_code == 200:
            print('POST request successful!')
        else:
            print(f'POST request failed with status code: {post_response.status_code}')
    else:
        print(f'GET request failed with status code: {get_response.status_code}')


if input('type: [threads/normal]') == "threads":
    for i in range(1000):
        t = threading.Thread(target=process)
        t.start()
else:
    for i in range(1000):
        process()

