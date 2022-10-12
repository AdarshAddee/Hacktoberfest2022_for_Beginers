'''
Dev By @DavidG33k
'''

def anagram_with_dict(first_word, second_word):

    if len(first_word) != len(second_word):
        return False

    occurrences_first_word = dict()
    occurrences_second_word = dict()

    for letter in first_word:
        if letter not in occurrences_first_word:
            occurrences_first_word[letter] = 1
        else:
            occurrences_first_word[letter] += 1

    for letter in second_word:
        if letter not in occurrences_second_word:
            occurrences_second_word[letter] = 1
        else:
            occurrences_second_word[letter] += 1

    for key in occurrences_first_word:
        #check if the letter is in both words
        if key in occurrences_second_word:
            #check the occurrences
            if occurrences_first_word[key] != occurrences_second_word[key]:
                return False
        else:
            return False
    
    return True

def anagram_with_dict2(first_word, second_word):

    if len(first_word) != len(second_word):
        return False

    occurrences = dict()

    for letter in first_word:
        if letter not in occurrences:
            occurrences[letter] = 1
        else:
            occurrences[letter] += 1

    for letter in second_word:
        for key in occurrences:
            if letter == key:
                occurrences[key] -= 1

    for key in occurrences:
        if occurrences[key] != 0:
            return False

    return True
            
def anagram_with_sort(first_word, second_word):
    first_word_list = list(first_word)

    second_word_list = list(second_word)

    if len(first_word_list) != len(second_word_list):
        return False

    first_word_list.sort()
    second_word_list.sort()

    for i in range(0, len(first_word_list)):
        if first_word_list[i] != second_word_list[i]:
            return False
    
    return True

def anagram_with_replacement(first_word, second_word):

    first_word_list = list(first_word)

    second_word_list = list(second_word)

    if len(first_word_list) != len(second_word_list):
        return False

    result = first_word_list

    for i in range(0, len(second_word_list)):
        for j in range(0, len(result)):
            if(second_word[i] == result[j]):
                result[j] = '!'

    for letter in result:
        if letter != '!':
            return False

    return True




first_word = 'incerta'

second_word = 'trincea'

print(anagram_with_dict(first_word, second_word))

print(anagram_with_dict2(first_word, second_word))

print(anagram_with_sort(first_word, second_word))

print(anagram_with_replacement(first_word, second_word))
