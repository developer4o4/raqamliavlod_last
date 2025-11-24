# import time

# a = []

# for i in range(1024**1024):
#     a.append("a" * 1024)



# time.sleep(15)



import requests
from bs4 import BeautifulSoup

def process():
    # Start a session to persist cookies
    session = requests.Session()

    # Step 1: Send a GET request to fetch the page
    get_response = session.get('https://raqamliavlod.uz/kontest/masala/5/')
    
    # Check if the GET request was successful
    if get_response.status_code == 200:
        # Parse the CSRF token from the HTML
        soup = BeautifulSoup(get_response.text, 'html.parser')
        
        # Assuming the CSRF token is in a hidden input field named 'csrf_token'
        csrf_token = soup.find('input', {'name': 'csrftokenmiddleware'})['value']
        
        # Step 2: Prepare the data for the POST request
        post_data = {
            'csrf_token': csrf_token,
            # Add other required POST fields here
            'field_name': 'value'
        }
        
        # Step 3: Send the POST request with the CSRF token
        post_response = session.post('https://raqamliavlod.uz/kontest/masala/5/', data=post_data)
        
        # Check if the POST request was successful
        if post_response.status_code == 200:
            print('POST request successful!')
            print(post_response.text)
        else:
            print(f'POST request failed with status code: {post_response.status_code}')
    else:
        print(f'GET request failed with status code: {get_response.status_code}')


for i in range(100):
    process()

