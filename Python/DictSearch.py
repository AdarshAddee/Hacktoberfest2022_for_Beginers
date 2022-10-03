#Github Profile:-. https://github.com/vishal10kesharwani/


def dic(words):

  wordList = {}

  for index in words:

    try:

      wordList[index] += 1

    except KeyError:

      wordList[index] = 1

  return wordList

 

wordList='1,3,2,4,5,3,2,1,4,3,2'.split(',')

print wordList

print dic(wordList)
