import sys

def main(name_file):
    f = open(name_file, 'r')
    methods = {'0':'repeated_square', '1':'floyd_warshall', '2':'johnson_queue', '3':'johnson_array', '4':'nbfs'}
    memory = None
    for line in f.readlines():
        if line.startswith("\tCommand being timed:"):
            line = line.replace('"', "")
            line = line.replace("\tCommand being timed: ./main.out arquivos_testes/", "")
            line = line.split()
            name_file_test = line[0]
            community = line[1]
            method = line[2]
        elif line.startswith("\tUser time (seconds): "):
            line = line.replace("\tUser time (seconds): ", "")
            time = line.split()[0]
        elif line.startswith("\tMaximum resident set size (kbytes): "):
            line = line.replace("\tMaximum resident set size (kbytes): ", "")
            memory = line.split()[0]
        if memory:
            print name_file_test,community,methods[method],time,memory
            memory = None
    f.close()
    
if __name__ == '__main__':
    name_file = sys.argv[1]
    main(name_file)
