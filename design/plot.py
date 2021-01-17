#!/usr/bin/python3
import numpy as np
import matplotlib.pyplot as plt

if __name__ == "__main__":
    fig, ax = plt.subplots()

    ax.set_xlabel("cache size")
    ax.set_ylabel("hate rating")
    ax.set_title("LRU Page Replace Algorithm")

    x = [i for i in range(5, 105, 5)]
    y1 = np.fromfile("local_hit_rate.txt", sep='\n')
    y2 = np.fromfile("random_hit_rate.txt", sep='\n')
    ax.plot(x, y1, marker="o", label="locality acess")
    ax.plot(x, y2, marker="o", label="random acess")
    ax.legend()
    plt.show()

