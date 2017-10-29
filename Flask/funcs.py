#!/usr/bin/python
from __future__ import print_function

import requests, subprocess, json, time
import BeautifulSoup as bs

# URL from which we'll grab the puzzle
url = 'http://www.sudokuweb.org/'

def get_puzzle():
  board = ""
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
          board += str(span.string)
        elif span['class'] == 'vloz':
          board += '0'

  return board

def ai_solve(board):
  with open('/tmp/grid', 'w') as f:
    for i, c in enumerate(board):
      if i != 0 and i % 9 == 0:
        f.write('\n')
      f.write(c)
  
  cmd = "../ai/solve 9 /tmp/grid"

  start_time = time.time()
  proc = subprocess.Popen(cmd.split(" "), stdout=subprocess.PIPE, stderr=subprocess.PIPE)
  out, err = proc.communicate()
  end_time = time.time()

  time_elapsed = end_time - start_time
  return out, time_elapsed
