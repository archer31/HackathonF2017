import subprocess
from flask import Flask, render_template
from get_puzzle import get_puzzle

app = Flask(__name__)

@app.route('/')
def web_page():
  author = "Jake, Ryan, and Xandy"
  name = "AI Love Sudoku"

  puzzle = get_puzzle()
  return render_template('index.html', puzzle=puzzle)

if __name__ == '__main__':
  app.run()
