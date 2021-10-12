import matplotlib.pyplot as plt
import csv
  
n = []
binary = []
binomial = []

with open('losdatos.csv','r') as csvfile:
    plots = csv.reader(csvfile, delimiter = ',')      
    for row in plots:
        n.append(int(row[0]))
        binary.append(float(row[1]))
        binomial.append(float(row[2]))
  
plt.plot(n, binary, color = 'g', label = "Binary Heap")
plt.plot(n, binomial, color = 'r', label = "Binomial Heap")
plt.xlabel('Número de elementos')
plt.ylabel('Tiempo(s)')
plt.title('Comparación Merge: Binary Heap v/s Binomial Heap')
plt.legend()
plt.show()