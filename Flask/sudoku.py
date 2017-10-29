#!/usr/bin/python

import subprocess, json
from flask import Flask, render_template
from funcs import get_puzzle, ai_solve

app = Flask(__name__)

@app.route('/')
def web_page():
  author = "Jake, Ryan, and Xandy"
  name = "AI Love Sudoku"

  puzzle = get_puzzle()
  solution = ai_solve(puzzle)
  return render_template('index.html', puzzle=str(puzzle), solution=str(solution))

if __name__ == '__main__':
  app.run()
