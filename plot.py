import json
import numpy as np 
import matplotlib.pyplot as plt 

f = open("build/output.txt")
d = json.loads(f.read())

for p in d:
  all_x = []
  all_y = []
  for v in p:
    all_x.append(v["x"])
    all_y.append(v["y"])
  plt.fill(all_x, all_y)

plt.title("covers") 
plt.show()

