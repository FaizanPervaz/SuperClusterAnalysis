# SuperClusterAnalysis
Implementation of the SuperCluster algorithm for data clustering, enabling grouping of similar data points based on provided parameters, with support for both 2D and 3D datasets. Results are visualized graphically, aiding in data analysis and insights

In Task1, the code reads data from a CSV file named "driver-data.csv" and performs k-means clustering on the data. The code initializes a 2D dynamic array to store the data and creates four initial clusters. It then calculates the Euclidean distance between each data point and the clusters to assign the data point to the nearest cluster. The centroids of the clusters are updated iteratively until convergence. Finally, the clustered data is written to an output CSV file named "output.csv".

In Task2, the code reads data from a CSV file named "segmented_customers-1.csv" and performs k-means clustering on the data. It initializes a 3D dynamic array to store the data and creates four initial clusters. The code assigns each data point to the nearest cluster based on the Euclidean distance. The centroids of the clusters are updated iteratively until convergence. The clustered data is not written to an output file in this task.

Please note that I have provided a general description based on the code provided. If you have any specific questions or need further clarification, feel free to ask.
![20i0565_DSAss_01_page-0001](https://github.com/FaizanPervaz/SuperClusterAnalysis/assets/121532370/2fb9564c-13b3-470a-9f05-43702503642b)
