# Python implementation of stable matching problem
# Modified based on Tyler Moore's implementation


def gale_shapley(hospital, student, pref_hospital, pref_student):
    # inverse student prereference list
    # for each student keep the rank for each man, rank_hospital is a dictionary of dicionary,
    # when w needs to choose, we can compare the rank of each man with constant time
    # the bigger the number, the higher the rank
    rank_hospital = {}
    for s in student:
        rank_hospital[s] = {}
        i = len(student)
        for h in pref_student[s]:
            # the higher the number (which is i) is,the higher the ranking
            rank_hospital[s][h] = i
            i -= 1
    # count how many proposals each hospital has made, to track next student he can propose
    count = {}
    for h in hospital:
        count[h] = hospital[h]

    # initially all hospital and student are free
    freehospital = list()
    for h in hospital:
        while count[h] > 0:
            freehospital.append(h)
            count[h] -= 1
    numpartners = len(student)
    S = {}           # engaged pairs stored in dictionary with student name as key, hospital name as value
    
    # run the algorithm
    while freehospital:
        h = freehospital.pop()
        if count[h] > numpartners:
            continue
        # get the first student that h has not yet been proposed to
        s = pref_hospital[h][count[h]]
        count[h] += 1

        if s not in S:  # student s is free
            S[s] = h
        else:
            # s prefers h to the current partner h', accepts h, dumps h'
            hprime = S[s]
            if rank_hospital[s][h] > rank_hospital[s][hprime]:
                S[s] = h
                freehospital.append(hprime)
            # s prefers the current partner, reject h
            else:
                freehospital.append(h)
    return S


if __name__ == "__main__":

    # change to a data structure (e.g a dictionay) to keep track the number of positions for each hospital
    hospital = {'Atlanta':1, 'Boston':2, 'Chicago':2, 'Detroit':1}

    student = ['Val', 'Wayne', 'Xavier', 'Yolanda', 'Zeus', 'Alfred']

    pref_hospital = {'Atlanta': ['Wayne', 'Val', 'Alfred', 'Yolanda', 'Zeus', 'Xavier'],
                     'Boston': ['Yolanda', 'Wayne', 'Alfred', 'Val', 'Xavier', 'Zeus'],
                     'Chicago': ['Alfred', 'Wayne', 'Zeus', 'Xavier', 'Yolanda', 'Val'],
                     'Detroit': ['Val', 'Yolanda', 'Xavier', 'Wayne', 'Zeus', 'Alfred']
                     }
    pref_student = {
        'Val': ['Atlanta', 'Boston', 'Detroit', 'Chicago'],
        'Wayne': ['Chicago', 'Boston', 'Detroit', 'Atlanta', 'El Paso'],
        'Xavier': ['Boston',  'Chicago', 'Detroit', 'Atlanta'],
        'Yolanda': ['Atlanta', 'Detroit', 'Chicago', 'Boston'],
        'Zeus': ['Detroit', 'Boston', 'Chicago', 'Atlanta'],
        'Alfred': ['Boston', 'Detroit', 'Atlanta', 'Chicago']
    }

    stable_matching = gale_shapley(
        hospital, student, pref_hospital, pref_student)
    print(stable_matching)
