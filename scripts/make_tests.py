import sys
import uuid
import random

if (len(sys.argv) < 2):
    print(f"usage: python3 {sys.argv[0]} <number_of_vertexes> <dimension, default=10>")
    sys.exit(1)

m = 10

if (len(sys.argv) == 3):
    m = int(sys.argv[2])

n = int(sys.argv[1])


def random_string():
    result = str(uuid.uuid4())
    interval = len(result) - random.randrange(0, 10)
    return result[:interval]

def random_double():
     result = random.random()
     result *= random.randrange(-10000, 10000)
     return result

def vertex():
    result = []
    for i in range(0, m):
        result.append(random_double())
    return result



for i in range(0, n):
    v = vertex()
    name = random_string()

    print(f"{name}", end="")

    for number in v:
        print(f",{number}", end="")
    print()
