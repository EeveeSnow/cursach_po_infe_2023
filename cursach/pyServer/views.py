from flask import redirect, render_template, Flask
from os import environ
import api.read as reader


app = Flask(__name__)
app.config['SECRET_KEY'] = 'data'


@app.route('/')
def home():
    """Renders the home page."""
    filename = "data.csv"
    data = reader.read_csv(filename)
    return render_template(
        'index.html', title="data", filename=filename, data=data
    )

if __name__ == '__main__':
    HOST = environ.get('SERVER_HOST', 'localhost')
    try:
        PORT = int(environ.get('SERVER_PORT', '5555'))
    except ValueError:
        PORT = 5555
    app.run(HOST, PORT, debug=True)