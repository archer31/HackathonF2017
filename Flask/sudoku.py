from flask import Flask
app = Flask(__name__)

@app.route('/')
def web_page():
  author = "Jake, Ryan, and Xandy"
  name = "AI Love Sudoku"
  return render_template('index.html', author=author, name=name)

if __name__ == '__main__':
  app.run()
