import re
import string
import sys
import os
import base64

if not (len(sys.argv) == 2):
	print("Please provide a username")
	exit()
username = sys.argv[1]


client_key = os.environ['MARKOV_KEY']
client_secret = os.environ['MARKOV_SECRET']


key_secret = '{}:{}'.format(client_key, client_secret).encode('ascii')
b64_encoded_key = base64.b64encode(key_secret)
b64_encoded_key = b64_encoded_key.decode('ascii')

import requests

base_url = 'https://api.twitter.com/'
auth_url = '{}oauth2/token'.format(base_url)

auth_headers = {
    'Authorization': 'Basic {}'.format(b64_encoded_key),
    'Content-Type': 'application/x-www-form-urlencoded;charset=UTF-8'
}

auth_data = {
    'grant_type': 'client_credentials'
}

auth_resp = requests.post(auth_url, headers=auth_headers, data=auth_data)

access_token = auth_resp.json()['access_token']

search_headers = {
    'Authorization': 'Bearer {}'.format(access_token)
}

search_params = {
    'screen_name': username,
    'count': 200
}

search_url = '{}1.1/statuses/user_timeline.json'.format(base_url)

search_resp = requests.get(search_url, headers=search_headers, params=search_params)

tweet_data = search_resp.json()

for x in tweet_data:
    if x['text'][0:2] != 'RT':
        output = re.sub('((https://)|(@))[^ $]* *', '', x['text'])
        output = output.encode('ascii', errors='ignore').decode()
        print(output + '\n')
