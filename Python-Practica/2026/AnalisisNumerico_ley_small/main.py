from flask import Flask
import time
import random
from concurrent.futures import ThreadPoolExecutor

pool = ThreadPoolExecutor(max_workers=10) 

def fib(n):
    if n < 2:
        return n
    return fib(n-1) + fib(n-2)

# C = Concurrencia, s = tiempo por requests medio, tpr = tiempo por request across all concurrent requests (tiempo de procesamiento individual)
# C=1, tpr = 7685.867 / s = 7685
# C=2, tpr = 9191.584 / s = 18383
# C=3, tpr = 8860.497 / s = 26581
# C=4, tpr = 11275.476 / s = 45101
# C=5, tpr = 11764.430 / s = 58822
# C=10, tpr = 15807.876 / s = 158078
def trabajo():
    datos = [0] * 500_000_000 # Mucha memoria
    fib(35) # Mucha CPU

app = Flask(__name__)
# ab -n 10 -c 1 -s 3600 http://localhost:8000/
@app.route("/")
def index():
    future = pool.submit(trabajo)
    future.result()
    return "OK"

app.run(host="0.0.0.0", port=8000, threaded=True)

