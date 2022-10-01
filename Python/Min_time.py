//LEETCODE-539 
// Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.
class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        convertedTimes = []
        minimumTime = math.inf
        for time in timePoints:
            splitTime = time.split(":")
            convertedTimes.append(int(splitTime[0])*60+int(splitTime[1]))
        
        convertedTimes.sort()
        
        for x in range(len(convertedTimes)):
            if x == len(convertedTimes)-1:
                minimumTime = min(minimumTime, 1440-convertedTimes[x]+convertedTimes[0])
            else:  
                minimumTime = min(minimumTime, convertedTimes[x+1]-convertedTimes[x])
                
        return minimumTime
