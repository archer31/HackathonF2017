#!/usr/bin/python
from __future__ import print_function

import requests
import json
import BeautifulSoup as bs

# URL from which we'll grab the puzzle
url = 'http://www.sudokuweb.org/'

def get_puzzle():
  board = []
  payload = {'name': 'sign2', 'value': '9x9'}
  response = requests.post(url, data=json.dumps(payload)).text

  soup = bs.BeautifulSoup(response)
  table = soup.findChildren('table')[0]
  rows = table.findChildren('tr')

  for row in rows:
    spans = row.findChildren('span')

    for span in spans:
      if span.has_key('class'):
        if span['class'] == 'sedy':
          board.append(str(span.string))
        elif span['class'] == 'vloz':
          board.append(' ')

  return json.dumps(board)
