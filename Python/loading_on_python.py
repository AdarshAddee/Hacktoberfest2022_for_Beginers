# Kry9toN

import itertools
import threading
import sys
import time

loading = True

def animate():
    for c in itertools.cycle(['🌑', '🌒', '🌓', '🌔', '🌕', '🌖', '🌗', '🌘']):
        if not loading:
            break
        sys.stdout.write('\rLOADING ' + c)
        sys.stdout.flush()
        time.sleep(0.1)

def count(number):
    result = 0
    for n in range(number):
        result += 1
        time.sleep(0.0001)
    print()
    return result

if __name__ == '__main__':
    t = threading.Thread(target=animate)
    t.start()
    print(count(10000))
    loading = False
    t.join()
