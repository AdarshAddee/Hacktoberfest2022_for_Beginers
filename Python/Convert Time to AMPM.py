#Kayubakar0

def convert_to_24_hour(time12):
    AM = ['01', '02', '03', '04', '05', '06', '07', '08', '09', '10', '11', '12']
    PM = ['13', '14', '15', '16', '17', '18', '19', '20', '21', '22', '23', '00']

    finalSplit = split_time(time12)

    if finalSplit[-1] == "PM" :
        for i in range (len(AM)):
            if finalSplit[0] == AM[i]:
                finalSplit[0] = PM[i]
                del finalSplit[-1]
    
    return (':'.join(finalSplit))

def split_time(time12):
    splitTime = time12.split(":")
    splitFormat = splitTime[-1].split(' ')
    del splitTime[-1]
    finalSplit = splitTime + splitFormat
    return finalSplit

def main():
    test = True
    while test:
        tanggal = input("masukkan tanggal dengan format hh:mm:ss AM/PM = ")
        cek = split_time(tanggal)
        if cek[-1] == "AM" or "PM":
            print("Hasil Konversi Jam ke format 24 jam = ",convert_to_24_hour(tanggal))
            test = False

main()




