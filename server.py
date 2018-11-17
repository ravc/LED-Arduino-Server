from flask import Flask, render_template, jsonify
import serial

app = Flask(__name__)
ser = serial.Serial('/dev/ttyACM0', 9600)

def get_states():
    ser.write(b'S')
    states = []
    
    while True:
        s = ser.readline().decode().strip('\r\n')
        print(str(s))
        if "end" not in str(s):
            if '1' in str(s):
                states.append('checked')
            else:
                states.append('')
        else:
            break
    
    return states

@app.route('/')
def home():
    states = get_states()
    return render_template('index.html', power=states[0], red=states[1], blue=states[2], green=states[3])

@app.route('/changecolor/<color>', methods=['GET', 'POST'])
def change_color(color):
    print(color)
    ser.write('{}'.format(color).encode())
    states = get_states()
    return render_template('index.html', power=states[0], red=states[1], blue=states[2], green=states[3])

if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0')
