# generate htmt report in 5 line of code using pandas profiling
import pandas as pd
from pandas_profiling import ProfileReport

dataFrame = pd.read_csv('put your csv file here')
# print(dataFrame)

profile = ProfileReport(dataFrame)
profile.to_file(output_file='data.html')
