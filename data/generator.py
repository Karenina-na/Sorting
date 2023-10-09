import pandas as pd
import numpy as np
import os


# generate sorted data (greater)
def generate_sorted_data_greater(size):
    data = np.arange(size)
    data = data[::-1]
    os.makedirs("data/" + str(size), exist_ok=True)
    pd.DataFrame(data).to_csv("data/" + str(size) +
                              "/sorted_greater.txt", index=False, header=False, encoding="utf-8", sep=",", lineterminator=",")


# generate sorted data (less)
def generate_sorted_data_less(size):
    data = np.arange(size)
    os.makedirs("data/" + str(size), exist_ok=True)
    pd.DataFrame(data).to_csv("data/" + str(size) +
                              "/sorted_less.txt", index=False, header=False, encoding="utf-8", sep=",", lineterminator=",")


# generate random data
def generate_random_data(size):
    data = np.random.randint(0, size, size=size)
    os.makedirs("data/" + str(size), exist_ok=True)
    pd.DataFrame(data).to_csv("data/" + str(size) +
                              "/random.txt", index=False, header=False, encoding="utf-8", sep=",", lineterminator=",")


if __name__ == '__main__':
    for i in range(2, 7):
        generate_sorted_data_greater(10 ** i)
        generate_sorted_data_less(10 ** i)
        generate_random_data(10 ** i)
