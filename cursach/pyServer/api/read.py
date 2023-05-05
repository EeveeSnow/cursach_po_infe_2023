import csv

def read_csv(filename: str):
    # opening the CSV file
    with open(filename, mode ='r') as file:
   
        # reading the CSV file
        csvFile = csv.reader(file, delimiter=';')
        data = list()
        # displaying the contents of the CSV file
        for lines in csvFile:
            data.append(lines)
            print(lines)
        file.close()
    return data