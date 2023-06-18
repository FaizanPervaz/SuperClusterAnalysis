# 20I0565 Faizan Pervaz
from matplotlib import pyplot as graph
import pandas as pd
import csv
import matplotlib.colors as mcolors


def Task1():
    # Define the colors for your custom colormap
    colors = ["r", "g", "b", "y"]

    # Create the colormap
    cmap1 = mcolors.LinearSegmentedColormap.from_list('mycmap', colors)

    data = pd.read_csv("output.csv")

    graph.scatter(data['mean_dist_day'], data['mean_over_speed_perc'], s=0.5,alpha=1, c=data['output'], cmap=cmap1)
    graph.title("Clustered : mean_over_speed_perc (y) vs mean_dist_day(x)", fontsize=10)
    graph.xlabel("mean_dist_day", fontsize=10)
    graph.ylabel("mean_over_speed_perc", fontsize=10)
    graph.colorbar()
    graph.show()


def Task2():
    # Define the colors for your custom colormap
    colors = ["r", "g", "b", "y"]

    # Create the colormap
    cmap1 = mcolors.LinearSegmentedColormap.from_list('mycmap', colors)

    data = pd.read_csv("output1.csv")

    graph.scatter(data['Annual Income (k$)'], data['Spending Score (1-100)'], s=5, c=data[' Output '], cmap=cmap1)
    graph.title("Clustered : spending (y) vs income(x)", fontsize=10)
    graph.xlabel("Annual Income (k$)", fontsize=10)
    graph.ylabel("Spending Score (1-100)", fontsize=10)
    graph.colorbar()
    graph.show()


Task1()
Task2()
